aux_source_directory (. SRC_LIST)

message(${SRC_LIST})

# add external libraries
set(OpenCV_DIR "/home/shhs/env/opencv3_2_openface/share/OpenCV")
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
# det alig .so
set(det_align_lib seeta_facedet_lib;seeta_fa_lib)
link_directories(${PROJECT_SOURCE_DIR})
link_directories("${PROJECT_SOURCE_DIR}/build")

enable_testing ()
foreach (f ${SRC_LIST})
  string(REGEX REPLACE "[.]cpp" ".bin" BIN ${f})
  add_executable(${BIN} ${f})
  target_link_libraries(${BIN} viplnet ${OpenCV_LIBS} ${det_align_lib})
endforeach ()

