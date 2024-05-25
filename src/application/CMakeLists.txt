cmake_minimum_required(VERSION 3.4)

project(test_app LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

set(SOURCES_MNGR
    ../middeleware/
    Drone.cpp
    DeliveryCenter.cpp
    UserInterface.cpp
    main.cpp
)

include_directories(BEFORE
                    $(CMAKE_CURRENT_SOURCE_DIR)
                    $(CMAKE_CURRENT_SOURCE_DIR)/../middeleware
                    $(CMAKE_CURRENT_SOURCE_DIR)/../middeleware/Logger
                    $(CMAKE_CURRENT_SOURCE_DIR)/../middeleware/Battery)

add_executable(test_app ${SOURCES_MNGR})

target_link_libraries(test_app PRIVATE battery)

install(TARGETS test_app DESTINATION output)
