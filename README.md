# RaySnake

Simple snake game made with raylib!

### TODO:
- high score system
- "you lost!" popup
- more flexible grid and graphics
- gameplay twist

## Building
### Requirements
- A C99 compatible compiler
- CMake >= 3.11
- A working raylib installation (optional)

If you have these simple requirements, use

```
mkdir build
cmake -B build/ -S .
cmake --build build/
```

If you don't have raylib 4.0 installed for CMake, it will fetch the raylib source from GitHub and build it automatically for you.

Then the built binary will be on the `build` directory.

Have fun! :)

## License
RaySnake is licensed under [GPL 3.0](https://www.gnu.org/licenses/gpl-3.0.html) or later. You may freely copy, distribute and modify it. Any modifications must also be distributed under GPL. You can read the [COPYING](/COPYING) file for more information.

RaySnake uses [raylib](https://github.com/raysan5/raylib), which is licensed under [Zlib](https://github.com/raysan5/raylib/blob/master/LICENSE).