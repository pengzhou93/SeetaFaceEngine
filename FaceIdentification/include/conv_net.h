/*
 *
 * This file is part of the open-source cmssFace engine, which includes three modules:
 * cmssFace Detection, cmssFace Alignment, and cmssFace Identification.
 *
 * This file is part of the cmssFace Identification module, containing codes implementing the
 * face identification method described in the following paper:
 *
 *   
 *   VIPLFaceNet: An Open Source Deep Face Recognition SDK,
 *   Xin Liu, Meina Kan, Wanglong Wu, Shiguang Shan, Xilin Chen.
 *   In Frontiers of Computer Science.
 *
 *
 * Copyright (C) 2016, Visual Information Processing and Learning (VIPL) group,
 * Institute of Computing Technology, Chinese Academy of Sciences, Beijing, China.
 *
 * The codes are mainly developed by Zining Xu(a M.S. supervised by Prof. Shiguang Shan)
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

#ifndef CONV_NET_H_
#define CONV_NET_H_

#include "net.h"
#include "net_factory.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>

class ConvNet: public Net {
 public:
  ConvNet(): Net() {}
  virtual ~ConvNet() {}
  virtual void SetUp();
  virtual void Execute();
 
 protected:
  int stride_h_;
  int stride_w_;
};

#endif //CONV_NET_H_

