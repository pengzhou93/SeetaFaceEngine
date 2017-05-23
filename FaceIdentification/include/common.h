#ifndef cmss_COMMON_H_
#define cmss_COMMON_H_

#include <cstdint>

#if defined (_MSC_VER) || defined (_WIN32) || defined (_WIN64)
  #ifndef cmss_EXPORTS
    #define  cmss_API __declspec(dllexport)
  #else
    #define  cmss_API __declspec(dllimport)
  #endif // cmss_API
#else // defined (windows)
 #define cmss_API
#endif

#define DISABLE_COPY_AND_ASSIGN(classname) \
 private: \
  classname(const classname&); \
  classname& operator=(const classname&)

#ifdef USE_OPENMP
#include <omp.h>

#define cmss_NUM_THREADS 4
#endif

namespace cmss {

  typedef struct ImageData {
    ImageData() {
      data = nullptr;
      width = 0;
      height = 0;
      num_channels = 0;
    }

    ImageData(int32_t img_width, int32_t img_height,
      int32_t img_num_channels = 1) {
      data = nullptr;
      width = img_width;
      height = img_height;
      num_channels = img_num_channels;
    }

    uint8_t* data;
    int32_t width;
    int32_t height;
    int32_t num_channels;
  } ImageData;

  typedef struct Rect {
    int32_t x;
    int32_t y;
    int32_t width;
    int32_t height;
  } Rect;

  typedef struct FaceInfo {
    cmss::Rect bbox;

    double roll;
    double pitch;
    double yaw;

    double score; /**< Larger score should mean higher confidence. */
  } FaceInfo;

  typedef struct {
    double x;
    double y;
  } FacialLandmark;
}  // namespace cmss

#endif  // cmss_COMMON_H_

