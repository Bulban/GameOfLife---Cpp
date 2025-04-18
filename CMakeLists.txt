cmake_minimum_required(VERSION 3.21)
project(gameoflife)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(gameoflife src/main.cpp)

find_package(SFML 3 REQUIRED COMPONENTS Window Graphics System)
target_link_libraries(gameoflife PRIVATE SFML::Window SFML::Graphics SFML::System)
 

