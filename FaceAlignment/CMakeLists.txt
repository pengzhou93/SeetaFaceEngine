cmake_minimum_required(VERSION 2.8.4)

project(cmss_facealign_lib)
message(Build face alignment lib)
# Build options
option(BUILD_EXAMPLES  "Set to ON to build examples"  OFF)

# Use C++11
#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
message(STATUS "C++11 support has been enabled by default.")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse4.1")

include_directories(include)

set(src_files 
    src/cfan.cpp
    src/face_alignment.cpp
    src/sift.cpp
    )

# build face alignment lib
add_library(cmss_facealign_lib SHARED ${src_files})
install(DIRECTORY include/ DESTINATION include/FaceAlignment)
install(TARGETS cmss_facealign_lib LIBRARY DESTINATION lib
  PERMISSIONS WORLD_EXECUTE OWNER_EXECUTE OWNER_WRITE OWNER_READ)

set(fa_required_libs cmss_facealign_lib)

if (BUILD_EXAMPLES)
    set(cmss_facedet_lib "./libcmss_facedet_lib.so")
    message(STATUS "Build with examples.")
    set(OpenCV_DIR "/home/shhs/env/opencv3_2_openface/share/OpenCV")
    find_package(OpenCV)
    if (NOT OpenCV_FOUND)
        message(WARNING "OpenCV not found. Test will not be built.")
      else()
	include_directories("../FaceDetection/include")
        include_directories(${OpenCV_INCLUDE_DIRS} build)
	link_directories(build .)
        list(APPEND fa_required_libs ${OpenCV_LIBS} cmss_facedet_lib)
        add_executable(fa_align_test src/test/face_alignment_test.cpp)
        target_link_libraries(fa_align_test ${fa_required_libs})
    endif()
else()
message(STATUS "Don't build example")      
endif()
