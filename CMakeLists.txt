cmake_minimum_required(VERSION 3.0)

project(Koulu)

file(GLOB KOULU_SOURCES "src/Kotitehtävä*/*.cpp")

add_executable(Koulu ${KOULU_SOURCES})

