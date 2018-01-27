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
    CNetwork                _Network;
    Core                    _Game;
    std::thread             _GameThread;

public:
    int                     Initialize(const std::string&, int);
    int                     Run();
    int                     Delete();
    int                     LaunchGame();
};


#endif //R_TYPE_CLIENT_H
