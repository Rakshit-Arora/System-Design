cmake_minimum_required(VERSION 3.10)
project(CarRentalSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include header files
include_directories(include)

# Source files
file(GLOB SOURCES "src/*.cpp")

# Add executable
add_executable(CarRentalSystem main.cpp ${SOURCES})
