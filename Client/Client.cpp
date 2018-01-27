//
// Created by sshsupreme on 17/01/18.
//

#include <HelloPacket.h>
#include "Client.h"

int                 Client::Initialize(const std::string& ip, int port)
{
    if (_Network.Initialize(ip, port) == -1)
        return (-1);
    return 0;
}

int                 Client::Run()
{
    // Do whatever we want to

    HelloPacket   a;

    a.setUsername("rozita");
    _Network.Send(a);
    this->LaunchGame();
    _Network.Run();
    return 0;
}

int                 Client::LaunchGame()
{
    this->_Game.Init();
    this->_Game.get_engine()->run();
}

int                 Client::Delete()
{
    return 0;
}
