
add_subdirectory(glad)

set(OPENGL_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/glad/include" CACHE PATH "glad include dir .."  FORCE)
message("currsrc dir " ${CMAKE_CURRENT_SOURCE_DIR})
message("opengl include dirs " ${OPENGL_INCLUDE_DIR})
