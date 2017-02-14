cmake_minimum_required(VERSION 3.6)
project(GRAPHICS)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(GRAPHICS ${SOURCE_FILES} bresenham.h bresenham.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )


target_link_libraries(GRAPHICS ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )