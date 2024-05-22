cmake_minimum_required(VERSION 3.4)

project ("POC")

include_directories(BEFORE
                    $(CMAKE_CURRENT_SOURCE_DIR)/Logger)

add_subdirectory(logging)
