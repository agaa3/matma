cmake_minimum_required(VERSION 3.21)
project(Matma)

set(CMAKE_CXX_STANDARD 14)
include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src
)

add_executable(Matma main.cpp src/Vector.cpp include/Vector.h src/Matrix4.cpp include/Matrix4.h)
