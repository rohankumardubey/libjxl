// Copyright (c) the JPEG XL Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "jxl/enc_transforms.h"

#undef HWY_TARGET_INCLUDE
#define HWY_TARGET_INCLUDE "jxl/enc_transforms.cc"
#include <hwy/foreach_target.h>
// ^ must come before highway.h and any *-inl.h.

#include <hwy/highway.h>

#include "jxl/dct_scales.h"
#include "jxl/enc_transforms-inl.h"

namespace jxl {

#if HWY_ONCE
HWY_EXPORT(TransformFromPixels);
void TransformFromPixels(const AcStrategy::Type strategy,
                         const float* JXL_RESTRICT pixels, size_t pixels_stride,
                         float* JXL_RESTRICT coefficients,
                         float* scratch_space) {
  return HWY_DYNAMIC_DISPATCH(TransformFromPixels)(
      strategy, pixels, pixels_stride, coefficients, scratch_space);
}

HWY_EXPORT(LowestFrequenciesFromDC);
void LowestFrequenciesFromDC(const jxl::AcStrategy::Type strategy,
                             const float* dc, size_t dc_stride, float* llf) {
  return HWY_DYNAMIC_DISPATCH(LowestFrequenciesFromDC)(strategy, dc, dc_stride,
                                                       llf);
}

HWY_EXPORT(AFVDCT4x4);
void AFVDCT4x4(const float* JXL_RESTRICT pixels, float* JXL_RESTRICT coeffs) {
  return HWY_DYNAMIC_DISPATCH(AFVDCT4x4)(pixels, coeffs);
}
#endif  // HWY_ONCE

}  // namespace jxl