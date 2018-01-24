cmake_minimum_required(VERSION 2.8.9)
project(jeometry_test)
SET(TARGET tester)
set(GEOMETRY_INCLUDE_DIR
	${CMAKE_CURRENT_SOURCE_DIR}/geometry)
if(${CMAKE_C_COMPILER_ID} MATCHES "Clang" OR ${CMAKE_CXX_COMPILER_ID} MATCHES "Clang")
	set(CMAKE_COMPILER_IS_CLANG TRUE)
endif()


include(install_helpers.cmake)

add_subdirectory(deps)
add_subdirectory(geometry)

include_directories(${GEOMETRY_INCLUDE_DIR})

add_executable(${TARGET} main.cpp)

target_link_libraries(${TARGET} geometry)
#for glut tmp this will be moved lib
find_package(OpenGL REQUIRED)
message("found open gl " ${OpenGL})
include_directories(${OPENGL_INCLUDE_DIR})
target_link_libraries(${TARGET} glad)


ADD_DEPENDENCIES(${TARGET} geometry)
