//
// Created by sshsupreme on 17/01/18.
//

#include <HelloPacket.h>
#include <CmdAddPlayerPacket.hpp>
#include "Client.h"
#include "Global/CGlobal.h"

int                 Client::Initialize(const std::string& ip, int port, const std::string& username, bool isOnline)
{
    if (isOnline && _Network.Initialize(ip, port) == -1)
        return (-1);
    _Username = username;
    _isOnline = isOnline;
    return 0;
}

int                 Client::RunSolo()
{
    _GameThread = std::thread(&Client::LaunchGame, this);
    CmdAddPlayerPacket  packet;

    packet.set_Active("true");
    packet.set_Number("0");
    packet.set_Username(this->_Username);
    this->_Game.addEvent(packet.getHEADER() + packet.getJSON());

    this->_GameThread.join();
    return (0);
}

int                 Client::RunMultiplayer()
{
    auto *a = new HelloPacket;

    a->setUsername(_Username);
    _Network.Send(a);
    _Network.WaitStart();
    int _numberPlayer = _Network.WaitStart();
    if (_numberPlayer == -1)
        return (-1);
    _GameThread = std::thread(&Client::LaunchGame, this);
    _sendThread = std::thread(&Client::sendListener, this);
    _Network.Run();
    this->_GameThread.join();
    this->_sendThread.join();

    return (0);
}

int                 Client::Run()
{
    if (_isOnline)
        RunMultiplayer();
    else
        RunSolo();
    return 0;
}

int                 Client::LaunchGame()
{
    this->_Game.Init(true, _numberPlayer);
    CGlobal::Instance()->_init = true;
    this->_Network.set_game(this->_Game);
    this->_Game.get_engine()->run();
    this->Delete();
}

void 		Client::sendListener()
{
    while(!CGlobal::Instance()->quit)
    {
        if (CGlobal::Instance()->_init)
        {
            while (!CGlobal::Instance()->_mutexSend.try_lock());
            while (!this->_Game.get_engine()->getSceneInProcess()->get_send()->empty())
            {
                auto i = _Game.get_engine()->getSceneInProcess()->get_send()->front();
                this->_Network.Send(i);
                _Game.get_engine()->getSceneInProcess()->get_send()->pop();
            }
            CGlobal::Instance()->_mutexSend.unlock();
        }
    }
}

int                 Client::Delete()
{
    CGlobal::Instance()->quit = true;
    CGlobal::Instance()->_Service->stop();
    return 0;
}
