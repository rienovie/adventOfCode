cmake_minimum_required(VERSION 3.27)
project(avc)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

set(SOURCES
    main.cpp
    old/2015.cpp
    util.cpp
    2023/day1.cpp
    2023/day2.cpp
    2023/day3.cpp
    2023/day4.cpp
    2023/day6.cpp
)

add_executable(avc ${SOURCES})

target_include_directories(avc PUBLIC
    old/
    2023/
)

install(TARGETS avc RUNTIME DESTINATION bin)
