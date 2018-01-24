cmake_minimum_required(VERSION 2.8.9)
project(jeometry_test)
SET(TARGET tester)
set(GEOMETRY_INCLUDE_DIR
	${CMAKE_CURRENT_SOURCE_DIR}/geometry)
if(${CMAKE_C_COMPILER_ID} MATCHES "Clang" OR ${CMAKE_CXX_COMPILER_ID} MATCHES "Clang")
	set(CMAKE_COMPILER_IS_CLANG TRUE)
endif()


include(install_helpers.cmake)

set(SDL_DIR "${CMAKE_SOURCE_DIR}/deps/SDL2")
message("got sdl dir " ${SDL_DIR})
file (COPY ${SDL_DIR}/lib/x64/SDL2.lib
     DESTINATION "${CMAKE_BINARY_DIR}"
     )
file (COPY "${SDL_DIR}/lib/x64/SDL2.dll"
  DESTINATION "${CMAKE_BINARY_DIR}/"
  )
file (COPY "${SDL_DIR}/lib/x64/SDL2main.lib"
  DESTINATION "${CMAKE_BINARY_DIR}/"
  )

add_subdirectory(deps)

include_directories("${SDL_DIR}/include")

add_executable(${TARGET} main.cpp sdl_functions.h)
target_link_libraries(${TARGET} SDL2 SDL2main)


ADD_DEPENDENCIES(${TARGET} geometry)
