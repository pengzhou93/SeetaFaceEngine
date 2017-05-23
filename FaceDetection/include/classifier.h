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

#ifndef cmss_FD_CLASSIFIER_H_
#define cmss_FD_CLASSIFIER_H_

#include "common.h"
#include "feature_map.h"

namespace cmss {
namespace fd {

enum ClassifierType {
    LAB_Boosted_Classifier,
    SURF_MLP
};

class Classifier {
 public:
  Classifier() {}
  virtual ~Classifier() {}

  virtual void SetFeatureMap(cmss::fd::FeatureMap* feat_map) = 0;
  virtual bool Classify(float* score = nullptr, float* outputs = nullptr) = 0;
  
  virtual cmss::fd::ClassifierType type() = 0;

  DISABLE_COPY_AND_ASSIGN(Classifier);
};

}  // namespace fd
}  // namespace cmss

#endif  // cmss_FD_CLASSIFIER_H_
