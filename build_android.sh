#!/bin/bash

ROOT_DIR=`pwd`
RAYLIB_REPO="$ROOT_DIR/build/_deps/raylib-src"
RAYLIB_SRC="$RAYLIB_REPO/src"
GAME_PACKAGE_PATH="com/willian/raysnake"

# $1 = ABI
# $2 = arch
# to be executed inside $RAYLIB_SRC
function compile-arch() {
    local LIB_DIR="$ROOT_DIR/android/lib/$1"
    mkdir -p "$LIB_DIR"
    if [ -z "$(ls -A "$LIB_DIR")" ]; then
        echo
        echo "COMPILING FOR $1"
        echo
        make clean
        make PLATFORM=PLATFORM_ANDROID ANDROID_NDK="$ROOT_DIR/android/ndk" ANDROID_ARCH=$2 ANDROID_API_VERSION=29
        mv libraylib.a $LIB_DIR
    fi
}

cd "$RAYLIB_SRC"
compile-arch armeabi-v7a arm
compile-arch arm64-v8a arm64
compile-arch x86 x86
compile-arch x86_64 x86_64
cd "$ROOT_DIR"

mkdir --parents android/build/obj android/build/dex android/build/res/values

ABIS="armeabi-v7a x86 x86_64"

BUILD_TOOLS=android/sdk/build-tools/29.0.3
TOOLCHAIN=android/ndk/toolchains/llvm/prebuilt/linux-x86_64
NATIVE_APP_GLUE=android/ndk/sources/android/native_app_glue

FLAGS="-ffunction-sections -funwind-tables -fstack-protector-strong -fPIC -Wall \
	-Wformat -Werror=format-security -no-canonical-prefixes \
	-DANDROID -DPLATFORM_ANDROID -D__ANDROID_API__=29"

INCLUDES="-I. -Iinclude -I../include -I$RAYLIB_SRC -I$NATIVE_APP_GLUE -I$TOOLCHAIN/sysroot/usr/include"

# Copy icons
mkdir -p android/build/res/drawable-ldpi
mkdir -p android/build/res/drawable-mdpi
mkdir -p android/build/res/drawable-hdpi
mkdir -p android/build/res/drawable-xhdpi
cp assets/icon_ldpi.png android/build/res/drawable-ldpi/icon.png
cp assets/icon_mdpi.png android/build/res/drawable-mdpi/icon.png
cp assets/icon_hdpi.png android/build/res/drawable-hdpi/icon.png
cp assets/icon_xhdpi.png android/build/res/drawable-xhdpi/icon.png

# cp assets/* android/build/assets

for ABI in $ABIS; do
	case "$ABI" in
		"armeabi-v7a")
			CCTYPE="armv7a-linux-androideabi"
			ABI_FLAGS="-std=c99 -march=armv7-a -mfloat-abi=softfp -mfpu=vfpv3-d16"
			;;

		"arm64-v8a")
			CCTYPE="aarch64-linux-android"
			ABI_FLAGS="-std=c99 -target aarch64 -mfix-cortex-a53-835769"
			;;

		"x86")
			CCTYPE="i686-linux-android"
			ABI_FLAGS=""
			;;

		"x86_64")
			CCTYPE="x86_64-linux-android"
			ABI_FLAGS=""
			;;
	esac
	CC="$TOOLCHAIN/bin/${CCTYPE}29-clang"

	# Compile native app glue
	# .c -> .o
	$CC -c $NATIVE_APP_GLUE/android_native_app_glue.c -o $NATIVE_APP_GLUE/native_app_glue.o \
		$INCLUDES -I$TOOLCHAIN/sysroot/usr/include/$CCTYPE $FLAGS $ABI_FLAGS

	# .o -> .a
	$TOOLCHAIN/bin/llvm-ar rcs android/lib/$ABI/libnative_app_glue.a $NATIVE_APP_GLUE/native_app_glue.o

	# Compile project
	$CC src/*.c -o android/lib/$ABI/libmain.so -shared \
		$INCLUDES -I$TOOLCHAIN/sysroot/usr/include/$CCTYPE $FLAGS $ABI_FLAGS \
		-Wl,-soname,libmain.so -Wl,--exclude-libs,libatomic.a -Wl,--build-id \
		-Wl,--no-undefined -Wl,-z,noexecstack -Wl,-z,relro -Wl,-z,now \
		-Wl,--warn-shared-textrel -Wl,--fatal-warnings -u ANativeActivity_onCreate \
		-L. -Landroid/build/obj -Landroid/lib/$ABI \
		-lraylib -lnative_app_glue -llog -landroid -lEGL -lGLESv2 -lOpenSLES -latomic -lc -lm -ldl
done

# ______________________________________________________________________________
#
#  Build APK
# ______________________________________________________________________________
#
$BUILD_TOOLS/aapt package -f -m \
	-S android/build/res -J android/build/src -M android/build/AndroidManifest.xml \
	-I android/sdk/platforms/android-29/android.jar

# Compile NativeLoader.java
javac -verbose -source 1.8 -target 1.8 -d android/build/obj \
	-bootclasspath jre/lib/rt.jar \
	-classpath android/sdk/platforms/android-29/android.jar:android/build/obj \
	-sourcepath src android/build/src/$GAME_PACKAGE_PATH/R.java \
	android/build/src/$GAME_PACKAGE_PATH/NativeLoader.java

$BUILD_TOOLS/dx --verbose --dex --output=android/build/dex/classes.dex android/build/obj

# Add resources and assets to APK
$BUILD_TOOLS/aapt package -f \
	-M android/build/AndroidManifest.xml -S android/build/res -A assets \
	-I android/sdk/platforms/android-29/android.jar -F game.apk android/build/dex

# Add libraries to APK
cd android
for ABI in $ABIS; do
	../$BUILD_TOOLS/aapt add ../game.apk lib/$ABI/libmain.so
done
cd ..

# Sign and zipalign APK
jarsigner -keystore android/raysnake.keystore -storepass raysnake -keypass raysnake \
	-signedjar game.apk game.apk projectKey

$BUILD_TOOLS/zipalign -f 4 game.apk game.final.apk
mv -f game.final.apk game.apk

# Install to device or emulator
android/sdk/platform-tools/adb install -r game.apk
