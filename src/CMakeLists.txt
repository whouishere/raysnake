set(SOURCE_FILES
    game.h       game.c
    input.h      input.c
    food.h       food.c
    snake.h      snake.c
    highscore.h  highscore.c
    drawing.h    drawing.c
    icon.h
    main.c
)

set(RELEASE_FLAGS -Os)
set(DEBUG_FLAGS   -Wall -Wextra -Wstrict-prototypes -pedantic)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(SHELL_FILE ${PROJECT_SOURCE_DIR}/src/minshell.html)
set(JS_FILE ${PROJECT_SOURCE_DIR}/src/library.js)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} snake.rc)

target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_BINARY_DIR}/src")

target_compile_definitions(${PROJECT_NAME} PRIVATE "DEBUG=$<IF:$<CONFIG:Debug>,1,0>")
target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Debug>:${DEBUG_FLAGS}>")
target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Release>:${RELEASE_FLAGS}>")
target_link_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Release>:-mwindows>") # don't use the terminal

target_link_libraries(${PROJECT_NAME} raylib)

# Web and OSX configuration also taken from raylib's CMake project example
if (EMSCRIPTEN)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} \
                              -s USE_GLFW=3 \
                              -s ASSERTIONS=1 \
                              -s WASM=1 \
                              -s ASYNCIFY \
                              --js-library ${JS_FILE} \
                              --shell-file ${SHELL_FILE}")

  set(CMAKE_EXECUTABLE_SUFFIX ".html")
  configure_file(${PROJECT_SOURCE_DIR}/assets/icon.ico ${PROJECT_BINARY_DIR}/favicon.ico COPYONLY)
  configure_file(${PROJECT_SOURCE_DIR}/assets/icon.png ${PROJECT_BINARY_DIR}/icon.png COPYONLY)
endif ()

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
  target_link_libraries(${PROJECT_NAME} "-framework IOKit")
  target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
  target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()
