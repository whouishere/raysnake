# RaySnake

Simple snake game made with [raylib][raylib]!

### TODO:
- simple, small, and fast high score file encryption
- multi-threaded
- more flexible grid and graphics
- gameplay twist
- web browser support

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

If you don't have raylib 4.0 installed for CMake, it will fetch the raylib source from GitHub and build it automatically for you.

Then the built binary will be on the `build` directory.

Have fun! :)

## License
RaySnake is licensed under [GPL 3.0][GPLv3] or later. You may freely copy, distribute and modify it. Any modifications must also be distributed under GPL. You can read the [COPYING](./COPYING) file for more information.

RaySnake uses [raylib][raylib repo], which is licensed under [Zlib][raylib license].

[raylib]: https://www.raylib.com/
[GPLv3]: https://www.gnu.org/licenses/gpl-3.0.html
[raylib repo]: https://github.com/raysan5/raylib
[raylib license]: https://github.com/raysan5/raylib/blob/master/LICENSE
