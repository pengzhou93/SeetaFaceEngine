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

#ifndef cmss_FD_CLASSIFIER_SURF_MLP_H_
#define cmss_FD_CLASSIFIER_SURF_MLP_H_

#include <memory>
#include <vector>

#include "classifier.h"
#include "classifier/mlp.h"
#include "feat/surf_feature_map.h"

namespace cmss {
namespace fd {

class SURFMLP : public Classifier {
 public:
  SURFMLP() : Classifier(), model_(new cmss::fd::MLP()) {}
  virtual ~SURFMLP() {}

  virtual bool Classify(float* score = nullptr, float* outputs = nullptr);

  inline virtual void SetFeatureMap(cmss::fd::FeatureMap* feat_map) {
    feat_map_ = dynamic_cast<cmss::fd::SURFFeatureMap*>(feat_map);
  }

  inline virtual cmss::fd::ClassifierType type() {
    return cmss::fd::ClassifierType::SURF_MLP;
  }

  void AddFeatureByID(int32_t feat_id);
  void AddLayer(int32_t input_dim, int32_t output_dim, const float* weights,
    const float* bias, bool is_output = false);

  inline void SetThreshold(float thresh) { thresh_ = thresh; }

 private:
  std::vector<int32_t> feat_id_;
  std::vector<float> input_buf_;
  std::vector<float> output_buf_;

  std::shared_ptr<cmss::fd::MLP> model_;
  float thresh_;
  cmss::fd::SURFFeatureMap* feat_map_;
};

}  // namespace fd
}  // namespace cmss

#endif  // cmss_FD_CLASSIFIER_SURF_MLP_H_
