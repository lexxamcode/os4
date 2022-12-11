cmake_minimum_required(VERSION 3.24)
project(os4)

set(CMAKE_CXX_STANDARD 17)

find_package(X11 REQUIRED)
link_libraries(${X11_LIBRARIES})
include_directories(${X11_INCLUDE_DIR})
add_executable(os4 main.cpp)
