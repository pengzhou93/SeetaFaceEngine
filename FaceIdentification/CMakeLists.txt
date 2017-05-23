cmake_minimum_required (VERSION 2.6)

project (cmss_faceid_lib)
message(Build face identification lib)
option(BUILD_EXAMPLES  "Set to ON to build examples"  OFF)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -std=c++11 -O2 -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -std=c++11 -O2")

MESSAGE(STATUS "platform: ${CMAKE_SYSTEM_NAME}")

if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DGTEST_USE_OWN_TR1_TUPLE=1")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DGTEST_USE_OWN_TR1_TUPLE=1")
endif (CMAKE_SYSTEM_NAME MATCHES "Darwin")

set(cmss_FACEID_LIB_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(cmss_FACEID_LIB_SRC_DIR ${PROJECT_SOURCE_DIR}/src)
# set __VIOL_LOG__ macro
# add_definitions(-D__VIPL_LOG__)

include_directories(${cmss_FACEID_LIB_INCLUDE_DIR})
include_directories(${cmss_FACEID_LIB_SRC_DIR})
# detection
include_directories("../FaceDetection/include")
include_directories("../FaceAlignment/include")

if (BUILD_EXAMPLES)
  add_subdirectory(src)
else()
  message(STATUS "Don't build example")      
endif()

aux_source_directory(./src SRC_LIST)
aux_source_directory(./tools TOOLS_LIST)
add_library(cmss_faceid_lib SHARED ${SRC_LIST} ${TOOLS_LIST})

install(DIRECTORY include/ DESTINATION include/FaceIdentification)
install(TARGETS cmss_faceid_lib LIBRARY DESTINATION lib
  PERMISSIONS WORLD_EXECUTE OWNER_EXECUTE OWNER_WRITE OWNER_READ)

