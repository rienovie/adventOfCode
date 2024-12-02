cmake_minimum_required(VERSION 3.27)
project(avc)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fsanitize=address")

set(SOURCES main.cpp CppUtil/util.cpp 2024/day1.cpp)

add_executable(avc ${SOURCES})

target_include_directories(avc PUBLIC CppUtil/)

install(TARGETS avc RUNTIME DESTINATION bin)
