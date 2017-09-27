/* Copyright (c) 2016 PaddlePaddle Authors. All Rights Reserve.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License. */

#pragma once

#include <vector>
#include "paddle/framework/framework.pb.h"

namespace paddle {
namespace framework {

class BlockDescBind;

class ProgramDescBind {
 public:
  static ProgramDescBind &Instance(ProgramDesc *prog);

  ProgramDescBind(const ProgramDescBind &o) = delete;
  ProgramDescBind &operator=(const ProgramDescBind &o) = delete;

  BlockDescBind *AppendBlock(const BlockDescBind &parent);

  BlockDescBind *Block(size_t idx) { return blocks_[idx].get(); }

  std::string DebugString() { return Proto()->DebugString(); }

  size_t Size() const { return blocks_.size(); }

  ProgramDesc *Proto();

 private:
  explicit ProgramDescBind(ProgramDesc *prog);

  // Not owned
  ProgramDesc *prog_;

  std::vector<std::unique_ptr<BlockDescBind>> blocks_;
};
}
}
