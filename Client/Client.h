//
// Created by sshsupreme on 17/01/18.
//

#ifndef R_TYPE_CLIENT_H
#define R_TYPE_CLIENT_H

#include "Network/CNetwork.h"
#include "../Game/Core/Core.hpp"
#include <thread>

class Client {
 public:
  Client()                = default;
  ~Client()               = default;

 private:
  Core                    _Game;
  CNetwork                _Network;
  std::thread             _GameThread;
  std::thread		_sendThread;
 public:
  int                     Initialize(const std::string&, int);
  int                     Run();
  int                     Delete();
  int                     LaunchGame();
  void 			sendListener();
};


#endif //R_TYPE_CLIENT_H
