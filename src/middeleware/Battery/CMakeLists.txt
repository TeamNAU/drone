cmake_minimum_required(VERSION 3.4)

project(battery LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_CXX_EXTENSIONS)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

add_library(battery SHARED
    Battery.cpp
)

install(TARGETS battery DESTINATION output)
