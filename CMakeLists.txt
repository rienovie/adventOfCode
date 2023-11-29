cmake_minimum_required(VERSION 3.27)
project(avc)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
    main.cpp
    old/2015.cpp
)

add_executable(avc ${SOURCES})

target_include_directories(avc PUBLIC
    old/
)

install(TARGETS avc RUNTIME DESTINATION bin)
