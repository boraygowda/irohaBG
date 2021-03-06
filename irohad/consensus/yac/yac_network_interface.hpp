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

#ifndef IROHA_YAC_NETWORK_INTERFACE_HPP
#define IROHA_YAC_NETWORK_INTERFACE_HPP

#include <memory>
#include "consensus/yac/messages.hpp"
#include "model/peer.hpp"

namespace iroha {
  namespace consensus {
    namespace yac {

      class YacNetworkNotifications {
       public:
        /**
         * Callback on receiving commit message
         * @param from - peer that provide message
         * @param commit - provided message
         */
        virtual void on_commit(model::Peer from, CommitMessage commit) = 0;

        /**
         * Callback on receiving reject message
         * @param from - peer that provide message
         * @param reject - provided message
         */
        virtual void on_reject(model::Peer from, RejectMessage reject) = 0;

        /**
         * Callback on receiving vote message
         * @param from - peer that provide message
         * @param vote - provided message
         */
        virtual void on_vote(model::Peer from, VoteMessage vote) = 0;

        virtual ~YacNetworkNotifications() = default;
      };

      class YacNetwork {
       public:
        virtual void subscribe(
            std::shared_ptr<YacNetworkNotifications> handler) = 0;

        /**
         * Directly share commit message
         * @param to - peer recipient
         * @param commit - message for sending
         */
        virtual void send_commit(model::Peer to, CommitMessage commit) = 0;

        /**
         * Directly share reject message
         * @param to - peer recipient
         * @param reject - message for sending
         */
        virtual void send_reject(model::Peer to, RejectMessage reject) = 0;

        /**
         * Directly share vote message
         * @param to - peer recipient
         * @param vote - message for sending
         */
        virtual void send_vote(model::Peer to, VoteMessage vote) = 0;

        /**
         * Virtual destructor required for inheritance
         */
        virtual ~YacNetwork() = default;
      };
    }  // namespace yac
  }    // namespace consensus
}  // namespace iroha
#endif  // IROHA_YAC_NETWORK_INTERFACE_HPP
