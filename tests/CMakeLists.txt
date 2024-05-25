cmake_minimum_required(VERSION 3.4.3)

project(UT-drone_del)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(APP_SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/middeleware/Battery/Battery.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/middeleware/Logger/Logger.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/application/Drone.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/application/DeliveryCenter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/application/UserInterface.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)


include_directories(BEFORE
                    $(CMAKE_CURRENT_SOURCE_DIR)
                    $(CMAKE_CURRENT_SOURCE_DIR)/../src/application
                    $(CMAKE_CURRENT_SOURCE_DIR)/../src/middeleware
                    $(CMAKE_CURRENT_SOURCE_DIR)/../src/middeleware/Logger
                    $(CMAKE_CURRENT_SOURCE_DIR)/../src/middeleware/Battery)

add_executable(UT-app ${APP_SOURCE_FILES})
