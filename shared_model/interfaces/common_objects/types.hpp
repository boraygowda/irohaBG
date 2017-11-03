/**
 * Copyright Soramitsu Co., Ltd. 2017 All Rights Reserved.
 * http://soramitsu.co.jp
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef IROHA_SHARED_MODEL_TYPES_HPP
#define IROHA_SHARED_MODEL_TYPES_HPP

#include "common/types.hpp"

namespace shared_model {
  namespace interface {
    namespace types {
      /// Type of account id
      using AccountIdType = std::string;
      /// Type of height (for Block, Proposal etc)
      using HeightType = uint64_t;
      /// Type of public key
      using PubkeyType = iroha::pubkey_t;  // TODO: replace with shared lib?
      /// Type of role (i.e admin, user)
      using RoleIdType = std::string;
      /// Iroha domain id type
      using DomainIdType = std::string;
      /// Type of asset id
      using AssetIdType = std::string;
      /// Permission type used in permission commands
      using PermissionNameType = std::string;
      /// Type of amount
      using AmountType = iroha::Amount;
      /// Type of Quorum used in transaction and set quorum
      using QuorumType = uint32_t;
    }  // namespace types
  }    // namespace interface
}  // namespace shared_model
#endif  // IROHA_SHARED_MODEL_TYPES_HPP
