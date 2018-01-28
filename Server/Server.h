//
// Created by sshsupreme on 20/01/18.
//

#ifndef R_TYPE_SERVER_H
#define R_TYPE_SERVER_H

#include <iostream>
#include <vector>
#include <queue>
#include "Room/Room.h"
#include "Network/SNetwork.h"
#include "Room/RoomManager.h"
#include "../Game/Core/Core.hpp"
#include <thread>

class Server {
public:
    Server()                = default;
    ~Server();

private:
    SNetwork                _Network;
    RoomManager             _RoomManager;
  Core _Game;

private:
    std::shared_ptr<std::list<std::string>> _AllMessagesReceived;

private:
  std::thread _MessageHandlerThread;

public:
    int                     MessageHandler();


public:
    int                     Initialize(char*[], int);
    int                     Run();

  int Shutdown();
    int                     TreatMessage(const std::string&, const std::string&, const std::string&);

public:
    int                     HelloPacketHandler(const std::string&, const std::string&);
    int                     MessagePacketHandler(const std::string&, const std::string&);

public:
    int                     deleteUser(const std::string&);
};


#endif //R_TYPE_SERVER_H
