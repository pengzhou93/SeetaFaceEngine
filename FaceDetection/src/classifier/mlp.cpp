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

#include "classifier/mlp.h"

#include "common.h"

namespace cmss {
namespace fd {

void MLPLayer::Compute(const float* input, float* output) {
#pragma omp parallel num_threads(cmss_NUM_THREADS)
  {
#pragma omp for nowait
    for (int32_t i = 0; i < output_dim_; i++) {
      output[i] = cmss::fd::MathFunction::VectorInnerProduct(input,
        weights_.data() + i * input_dim_, input_dim_) + bias_[i];
      output[i] = (act_func_type_ == 1 ? ReLU(output[i]) : Sigmoid(-output[i]));
    }
  }
}

void MLP::Compute(const float* input, float* output) {
  layer_buf_[0].resize(layers_[0]->GetOutputDim());
  layers_[0]->Compute(input, layer_buf_[0].data());

  size_t i; /**< layer index */
  for (i = 1; i < layers_.size() - 1; i++) {
    layer_buf_[i % 2].resize(layers_[i]->GetOutputDim());
    layers_[i]->Compute(layer_buf_[(i + 1) % 2].data(), layer_buf_[i % 2].data());
  }
  layers_.back()->Compute(layer_buf_[(i + 1) % 2].data(), output);
}

void MLP::AddLayer(int32_t inputDim, int32_t outputDim, const float* weights,
    const float* bias, bool is_output) {
  if (layers_.size() > 0 && inputDim != layers_.back()->GetOutputDim())
    return;  // @todo handle the errors!!!

  std::shared_ptr<cmss::fd::MLPLayer> layer(new cmss::fd::MLPLayer(is_output ? 0 : 1));
  layer->SetSize(inputDim, outputDim);
  layer->SetWeights(weights, inputDim * outputDim);
  layer->SetBias(bias, outputDim);
  layers_.push_back(layer);
}

}  // namespace fd
}  // namespace cmss
