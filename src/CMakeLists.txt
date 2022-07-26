set(SOURCE_FILES
    game.h
    input.h
    input.c
    food.h
    food.c
    snake.h
    snake.c
    drawing.h
    drawing.c
    main.c
)

set(CMAKE_C_FLAGS
    "${CMAKE_C_FLAGS} \
    -static -Os -std=c99 -Wall -Wextra -pedantic"
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_BINARY_DIR}/src")

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