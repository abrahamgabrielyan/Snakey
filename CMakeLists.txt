cmake_minimum_required(VERSION 3.21)
project(Snakey)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)

# Compiler options
set(CMAKE_CXX_COMPILER "/usr/bin/gcc")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -DNDEBUG -Wall -Wpedantic -Werror")

# Add source files
set(SOURCE_FILES
    src/Fruit.cc
    src/Game.cc
    src/main.cc
    src/Snake.cc
)

# Include directories
include_directories(src)

# Find SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Add executable
add_executable(Snakey ${SOURCE_FILES})

# Link SDL2 and C++ standard library
target_link_libraries(Snakey ${SDL2_LIBRARIES} -lstdc++)

# Set output directory
set_target_properties(Snakey PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Copy res folder to build directory
file(COPY res DESTINATION ${CMAKE_BINARY_DIR})
