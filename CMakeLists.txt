cmake_minimum_required(VERSION 3.0)

project(avc)

add_executable(avc main.cpp)

install(TARGETS avc RUNTIME DESTINATION bin)
