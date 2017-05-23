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

#ifndef cmss_FD_FEATURE_MAP_H_
#define cmss_FD_FEATURE_MAP_H_

#include "common.h"

namespace cmss {
namespace fd {

class FeatureMap {
 public:
  FeatureMap()
      : width_(0), height_(0) {
    roi_.x = 0;
    roi_.y = 0;
    roi_.width = 0;
    roi_.height = 0;
  }

  virtual ~FeatureMap() {}

  virtual void Compute(const uint8_t* input, int32_t width, int32_t height) = 0;

  inline virtual void SetROI(const cmss::Rect & roi) {
    roi_ = roi;
  }

 protected:
  int32_t width_;
  int32_t height_;

  cmss::Rect roi_;
};

}  // namespace fd
}  // namespace cmss

#endif  // cmss_FD_FEATURE_MAP_H_
