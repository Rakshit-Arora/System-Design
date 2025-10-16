cmake_minimum_required(VERSION 3.10)
project(VendingMachine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Gather all .cpp files recursively
file(GLOB_RECURSE SOURCES
    "${PROJECT_SOURCE_DIR}/context/*.cpp"
    "${PROJECT_SOURCE_DIR}/states/*.cpp"
    "${PROJECT_SOURCE_DIR}/main.cpp"
)

# Include header directories
include_directories(
    "${PROJECT_SOURCE_DIR}/context"
    "${PROJECT_SOURCE_DIR}/states"
)

add_executable(VendingMachine ${SOURCES})
