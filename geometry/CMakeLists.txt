
set(GEOMETRY_SRCS geometry.h geometry.cpp)

set(LIB_TYPE STATIC)
#SET(LIB_TYPE SHARED)
add_library(geometry ${LIB_TYPE} ${GEOMETRY_SRCS})
