cmake_minimum_required(VERSION 4.1)
project(breadfetch VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SOURCES
    src/main.cc
    src/system_info.cc
    src/display.cc
)

add_executable(breadfetch ${SOURCES})

install(TARGETS breadfetch DESTINATION bin)
