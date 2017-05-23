/*
 *
 * This file is part of the open-source cmssFace engine, which includes three modules:
 * cmssFace Detection, cmssFace Alignment, and cmssFace Identification.
 *
 * This file is part of the cmssFace Detection module, containing codes implementing the
 * face detection method described in the following paper:
 *
 *
 *   Funnel-structured cascade for multi-view face detection with alignment awareness,
 *   Shuzhe Wu, Meina Kan, Zhenliang He, Shiguang Shan, Xilin Chen.
 *   In Neurocomputing (under review)
 *
 *
 * Copyright (C) 2016, Visual Information Processing and Learning (VIPL) group,
 * Institute of Computing Technology, Chinese Academy of Sciences, Beijing, China.
 *
 * The codes are mainly developed by Shuzhe Wu (a Ph.D supervised by Prof. Shiguang Shan)
 *
 * As an open-source face recognition engine: you can redistribute cmssFace source codes
 * and/or modify it under the terms of the BSD 2-Clause License.
 *
 * You should have received a copy of the BSD 2-Clause License along with the software.
 * If not, see < https://opensource.org/licenses/BSD-2-Clause>.
 *
 * Contact Info: you can send an email to cmssFace@vipl.ict.ac.cn for any problems.
 *
 * Note: the above information must be kept whenever or wherever the codes are used.
 *
 */

#ifndef cmss_COMMON_H_
#define cmss_COMMON_H_

#include <cstdint>

#if defined _WIN32
#ifdef cmss_EXPORTS
#define cmss_API __declspec(dllexport)
#else
#define cmss_API __declspec(dllimport)
#endif

#else
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
