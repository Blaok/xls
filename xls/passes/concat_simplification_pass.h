// Copyright 2020 Google LLC
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

#ifndef THIRD_PARTY_XLS_PASSES_CONCAT_SIMPLIFICATION_PASS_H_
#define THIRD_PARTY_XLS_PASSES_CONCAT_SIMPLIFICATION_PASS_H_

#include "xls/common/status/statusor.h"
#include "xls/ir/function.h"
#include "xls/passes/passes.h"

namespace xls {

// Pass which simplifies concats. This includes removing single-operand concats,
// flattening trees of dependent concats, and others.
class ConcatSimplificationPass : public FunctionPass {
 public:
  ConcatSimplificationPass()
      : FunctionPass("concat_simp", "Concat simplification") {}
  ~ConcatSimplificationPass() override {}

  xabsl::StatusOr<bool> RunOnFunction(Function* f, const PassOptions& options,
                                      PassResults* results) const override;
};

}  // namespace xls

#endif  // THIRD_PARTY_XLS_PASSES_CONCAT_SIMPLIFICATION_PASS_H_