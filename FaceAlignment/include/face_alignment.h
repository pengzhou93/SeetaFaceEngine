/*
 *
 * This file is part of the open-source cmssFace engine, which includes three modules:
 * cmssFace Detection, cmssFace Alignment, and cmssFace Identification.
 *
 * This file is part of the cmssFace Alignment module, containing codes implementing the
 * facial landmarks location method described in the following paper:
 *
 *
 *   Coarse-to-Fine Auto-Encoder Networks (CFAN) for Real-Time Face Alignment, 
 *   Jie Zhang, Shiguang Shan, Meina Kan, Xilin Chen. In Proceeding of the
 *   European Conference on Computer Vision (ECCV), 2014
 *
 *
 * Copyright (C) 2016, Visual Information Processing and Learning (VIPL) group,
 * Institute of Computing Technology, Chinese Academy of Sciences, Beijing, China.
 *
 * The codes are mainly developed by Jie Zhang (a Ph.D supervised by Prof. Shiguang Shan)
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

#ifndef cmss_FACE_ALIGNMENT_H_
#define cmss_FACE_ALIGNMENT_H_

#include <cstdlib>
#include "common.h"
class CCFAN;

namespace cmss {
class FaceAlignment{
 public:
  /** A constructor with an optional argument specifying path of the model file.
  *  If called with no argument, the model file is assumed to be stored in the
  *  the working directory as "cmss_fa_v1.1.bin".
  *
  *  @param model_path Path of the model file, either absolute or relative to
  *  the working directory.
  */
  cmss_API FaceAlignment(const char* model_path = NULL);

  /** A Destructor which should never be called explicitly.
  *  Release all dynamically allocated resources.
  */
  cmss_API ~FaceAlignment();

  /** Detect five facial landmarks, i.e., two eye centers, nose tip and two mouth corners.
  *  @param gray_im A grayscale image
  *  @param face_info The face bounding box
  *  @param[out] points The locations of detected facial points
  */
  cmss_API bool PointDetectLandmarks(ImageData gray_im, FaceInfo face_info, FacialLandmark *points);

 private:
  CCFAN *facial_detector;
};
}  // namespace cmss

#endif
