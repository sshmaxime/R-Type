//
// Created by sshsupreme on 17/01/18.
//

#include <HelloPacket.h>
#include "Client.h"
#include "Global/CGlobal.h"

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
    _GameThread = std::thread(&Client::LaunchGame, this);
    _Network.Run();
    this->_GameThread.join();
    return 0;
}

int                 Client::LaunchGame()
{
    this->_Game.Init();
    this->_Network.set_game(this->_Game);
    this->_Game.get_engine()->run();
    this->Delete();
    return 0;
}

int                 Client::Delete()
{
    CGlobal::Instance()->quit = true;
    CGlobal::Instance()->_Service->stop();
    return 0;
}
