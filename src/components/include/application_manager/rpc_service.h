/*
 * Copyright (c) 2018, Ford Motor Company
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following
 * disclaimer in the documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of the Ford Motor Company nor the names of its contributors
 * may be used to endorse or promote products derived from this software
 * without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef SRC_COMPONENTS_INCLUDE_APPLICATION_MANAGER_RPC_SERVICE_H
#define SRC_COMPONENTS_INCLUDE_APPLICATION_MANAGER_RPC_SERVICE_H

#include "application_manager/commands/command.h"
#include "application_manager/message.h"

namespace application_manager {
namespace rpc_service {

class RPCService {
 public:
  virtual ~RPCService() {}

  virtual bool ManageMobileCommand(const commands::MessageSharedPtr message,
                                   commands::Command::CommandOrigin origin) = 0;
  virtual bool ManageHMICommand(const commands::MessageSharedPtr message) = 0;
  virtual void SendMessageToMobile(const commands::MessageSharedPtr message,
                                   bool final_message = false) = 0;
  virtual void SendMessageToHMI(const commands::MessageSharedPtr message) = 0;

#ifdef SDL_REMOTE_CONTROL
  virtual void SendPostMessageToMobile(const MessagePtr& message) = 0;
  virtual void SendPostMessageToHMI(const MessagePtr& message) = 0;
#endif  // SDL_REMOTE_CONTROL
};
}  // namespace rpc_service
}  // namespace application_manager

#endif  // SRC_COMPONENTS_INCLUDE_APPLICATION_MANAGER_RPC_SERVICE_H
