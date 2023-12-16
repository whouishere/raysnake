# RaySnake

Simple snake game made with [raylib][raylib]!

You can play RaySnake from your browser on https://whou.codeberg.page/raysnake.

### TODO:
- multi-threaded
- more flexible grid and graphics
- gameplay twist

## Building
### Requirements
- A C99 compatible compiler
- CMake >= 3.11
- A working raylib installation (optional)

If you have these simple requirements, use

```
cmake -B build/ -S .
cmake --build build/
```

If you want a debug build, pass `-DCMAKE_BUILD_TYPE=Debug` to the first `cmake` command.

If you don't have raylib 4.5 installed for CMake, it will fetch the raylib source from GitHub and build it automatically for you.

Then the built binary will be on the `build` directory.

### Web build
It's also possible to play the game on the browser with WebAssembly. To build a target for browsers, first follow [Emscripten][emscripten]'s install instructions and use a slightly different `cmake` command:

```
emcmake cmake -B build/emscripten -S . -DPLATFORM=Web
cmake --build build/emscripten
```

Now you can setup a web server with Python to test the output:

```
python -m http.server -d build/emscripten
```

The game will now be available on `http://localhost:8000/raysnake.html`.

### Android build
There's also an experimental build (__tested on Linux only__) for Android. You must first do a CMake build or copy the raylib 4.5 source code somewhere and have at least [OpenJDK](https://openjdk.java.net/) 18 installed.

Then install the [command line tools](https://developer.android.com/studio/#command-tools) of the Android SDK inside the `android/sdk` folder and the [Android NDK](https://developer.android.com/ndk/downloads/) inside the `android/ndk` folder.

Now you might install some of the tools needed to build Android applications with Android SDK's `sdkmanager`:

```
cd android/sdk/cmdline-tools/bin
./sdkmanager --update --sdk_root=../..
./sdkmanager --install "build-tools;29.0.3" --sdk_root=../..
./sdkmanager --install "platform-tools" --sdk_root=../..
./sdkmanager --install "platforms;android-29" --sdk_root=../..
cd ../../../..
```

If you think you missed something, you can use the [raylib wiki](https://github.com/raysan5/raylib/wiki/Working-for-Android-(on-Linux)) as reference.

Now you can gladly run the `android_build.sh` script, build the APK, and automatically get the game installed on the Android device connected to the computer!

If you copied the raylib source code somewhere, run the script specifying the repo path with `RAYLIB_REPO`:

```
RAYLIB_REPO=<path to raylib here> ./build_android.sh
```

---

Have fun! :)

## License
RaySnake is licensed under [GPL 3.0][GPLv3] or later. You may freely copy, distribute and modify it. Any modifications must also be distributed under GPL. You can read the [COPYING](./COPYING) file for more information.

RaySnake uses [raylib][raylib repo], which is licensed under [Zlib][raylib license].

[raylib]: https://www.raylib.com/
[emscripten]: https://emscripten.org/docs/getting_started/downloads.html
[GPLv3]: https://www.gnu.org/licenses/gpl-3.0.html
[raylib repo]: https://github.com/raysan5/raylib
[raylib license]: https://github.com/raysan5/raylib/blob/master/LICENSE
