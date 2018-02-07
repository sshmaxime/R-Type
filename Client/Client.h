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
    std::thread		      _sendThread;
    int                     _numberPlayer;

public:
    bool                    _isOnline = false;

private:
    std::string             _Username = std::string();

public:
    int                     Initialize(const std::string&, int, const std::string&);
    int                     Delete();
    int                     LaunchGame();
    void 			        sendListener();

public:
    int                     Run();
    int                     RunSolo();
    int                     RunMultiplayer();
};


#endif //R_TYPE_CLIENT_H
