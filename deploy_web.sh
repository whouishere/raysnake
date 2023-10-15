#!/bin/sh

BUILD=build/emscripten

if ! type emcmake > /dev/null; then
	echo "emcmake isn't available, check if emscripten is activated correctly."
	exit 1
fi

emcmake cmake -B $BUILD -DPLATFORM=Web
cmake --build $BUILD

git switch pages

cp $BUILD/raysnake.html ./index.html
cp $BUILD/raysnake.js \
   $BUILD/raysnake.wasm \
   $BUILD/favicon.ico \
   $BUILD/icon.png \
   ./

git add --all

read -p 'Enter your commit message: ' msg

git commit -m "$msg"

read -p 'Push changes to upstream (y/n)? ' answer
if [ "$answer" != "${answer#[Yy]}" ] ;then 
    git push
fi
