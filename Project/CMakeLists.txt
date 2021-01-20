cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Project VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(CTest)
enable_testing()

#add_library (Sources Game.h)
add_executable(Project main.cpp Game.cpp Colony.cpp Cell.cpp Cargo.cpp Passenger.cpp Missile.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
