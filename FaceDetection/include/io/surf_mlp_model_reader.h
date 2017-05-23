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

#ifndef cmss_FD_IO_SURF_MLP_MODEL_READER_H_
#define cmss_FD_IO_SURF_MLP_MODEL_READER_H_

#include <iosfwd>
#include <vector>

#include "model_reader.h"

namespace cmss {
namespace fd {

class SURFMLPModelReader : public ModelReader {
 public:
  SURFMLPModelReader() {}
  virtual ~SURFMLPModelReader() {}

  virtual bool Read(std::istream* input, cmss::fd::Classifier* model);

 private:
  std::vector<int32_t> feat_id_buf_;
  std::vector<float> weights_buf_;
  std::vector<float> bias_buf_;
};

}  // namespace fd
}  // namespace cmss

#endif  // cmss_FD_IO_SURF_MLP_MODEL_READER_H_
