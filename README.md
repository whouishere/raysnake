# RaySnake

Simple snake game made with [raylib][raylib]!

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

If you don't have raylib 4.2 installed for CMake, it will fetch the raylib source from GitHub and build it automatically for you.

Then the built binary will be on the `build` directory.

### Web build
There's also experimental compatibility for the web available. To build a target for browsers, first follow [Emscripten][emscripten]'s install instructions and use a slightly different `cmake` command:

```
emcmake cmake -B build/emscripten -S . -DPLATFORM=Web
cmake --build build/emscripten
```

Now you can setup a web server with Python to test the output:

```
python -m http.server -d build/emscripten
```

The game will now be available on `http://localhost:8000/raysnake.html`.

Have fun! :)

## License
RaySnake is licensed under [GPL 3.0][GPLv3] or later. You may freely copy, distribute and modify it. Any modifications must also be distributed under GPL. You can read the [COPYING](./COPYING) file for more information.

RaySnake uses [raylib][raylib repo], which is licensed under [Zlib][raylib license].

[raylib]: https://www.raylib.com/
[emscripten]: https://emscripten.org/docs/getting_started/downloads.html
[GPLv3]: https://www.gnu.org/licenses/gpl-3.0.html
[raylib repo]: https://github.com/raysan5/raylib
[raylib license]: https://github.com/raysan5/raylib/blob/master/LICENSE
