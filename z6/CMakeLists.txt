cmake_minimum_required(VERSION 3.21)
project(Matma)

set(CMAKE_CXX_STANDARD 14)
include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src
)

add_executable(Matma main.cpp src/Vector.cpp include/Vector.h src/Matrix4.cpp include/Matrix4.h src/Vector4.cpp include/Vector4.h src/Quaternion.cpp include/Quaternion.h src/Line.cpp include/Line.h src/Plane.cpp include/Plane.h src/Camera.cpp include/Camera.h)
