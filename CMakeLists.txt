cmake_minimum_required(VERSION 3.10)
project(Obliviion)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set SFML location
set(SFML_DIR "/opt/sfml2/lib/cmake/SFML")

# Include directories (recursive under include/)
include_directories(include)

# Recursively grab all .cpp files in src/
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Define the executable
add_executable(Obliviion ${SOURCES})

# Link against SFML
find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)
target_link_libraries(Obliviion sfml-graphics sfml-window sfml-system sfml-audio)
