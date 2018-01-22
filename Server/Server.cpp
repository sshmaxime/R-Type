//
// Created by sshsupreme on 20/01/18.
//

#include <HelloPacket.h>
#include <MessagePacket.h>
#include "Server.h"
#include "Global/Global.h"

void                Help()
{
    std::cout << "./Server <ip> <port>" << std::endl;
}

bool                isCommandLineValid(char *av[], int ac)
{
    return (true);
}

int                 Server::Initialize(char *av[], int ac)
{
    _AllMessagesReceived = std::make_shared<std::queue<std::string>>();
    if (!isCommandLineValid(av, ac))
    {
        Help();
        return (-1);
    }

    if (_Network.Initialize(8887, _AllMessagesReceived) == -1)
        return (-1);
    _MessageHandler = std::thread(&Server::MessageHandler, this);
    return 0;
}

int                 Server::MessageHandler()
{
    while(!Global::Instance().quit)
    {
        Global::Instance().mutex_AllMessagesReceived.lock();

        if (!_AllMessagesReceived->empty())
        {
            std::string i = _AllMessagesReceived->front();
            std::string Header = i.substr(0, 3);
            std::string packetContent = i.substr(3);
            this->TreatMessage(Header, packetContent);
            _AllMessagesReceived->pop();
        }
        Global::Instance().mutex_AllMessagesReceived.unlock();
    }
    return 0;
}

int                 Server::TreatMessage(const std::string& header, const std::string& packetContent)
{
    if (header == "0x0")
        this->HelloPacketHandler(packetContent);
    else if (header == "0x1")
        this->MessagePacketHandler(packetContent);
    return (0);
}

int                 Server::HelloPacketHandler(const std::string& packetContent)
{
    HelloPacket     helloPacket;

    helloPacket.buildObjectFromJSON(packetContent);
    std::cout << helloPacket.getUsername() << std::endl;
    return (0);
}

int                 Server::MessagePacketHandler(const std::string& packetContent)
{
    MessagePacket   messagePacket;

    messagePacket.buildObjectFromJSON(packetContent);
    return (0);
}

int                 Server::Run()
{
    if (_Network.Run() == -1)
        return (-1);
    _MessageHandler.join();
    return 0;
}

Server::~Server()
{
    if (_MessageHandler.joinable())
        _MessageHandler.detach();
}
