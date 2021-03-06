/* Copyright 2018 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/
#include "tensorflow/lite/tools/optimize/test_util.h"

#include <gtest/gtest.h>

namespace tflite {
namespace optimize {
namespace internal {
const char* kModelWithMinus128Plus127Weights =
    "single_conv_weights_min_minus_127_max_plus_127.tflite";

const char* kModelWith0Plus10Weights =
    "single_conv_weights_min_0_max_plus_10.tflite";

int FailOnErrorReporter::Report(const char* format, va_list args) {
  char buf[1024];
  vsnprintf(buf, sizeof(buf), format, args);
  EXPECT_TRUE(false) << "Error happened: " << buf;
  return 0;
}
}  // namespace internal
}  // namespace optimize
}  // namespace tflite
