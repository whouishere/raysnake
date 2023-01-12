set(SOURCE_FILES
    game.h       game.c
    input.h      input.c
    food.h       food.c
    snake.h      snake.c
	highscore.h  highscore.c
    drawing.h    drawing.c
    main.c
)

set(RELEASE_FLAGS -Os)
set(DEBUG_FLAGS   -Wall -Wextra -Wstrict-prototypes -pedantic)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_BINARY_DIR}/src")

target_compile_definitions(${PROJECT_NAME} PRIVATE "DEBUG=$<IF:$<CONFIG:Debug>,1,0>")
target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Debug>:${DEBUG_FLAGS}>")
target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Release>:${RELEASE_FLAGS}>")
target_link_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Release>:-mwindows>") # don't use the terminal
target_link_options(${PROJECT_NAME} PRIVATE "-static")

target_link_libraries(${PROJECT_NAME} raylib)

# Web and OSX configurations also taken from raylib's CMake project example
# Web Configurations
if (${PLATFORM} STREQUAL "Web")
  # Tell Emscripten to build an example.html file.
  set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
endif()

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
  target_link_libraries(${PROJECT_NAME} "-framework IOKit")
  target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
  target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()
