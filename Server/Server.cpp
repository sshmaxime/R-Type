//
// Created by sshsupreme on 20/01/18.
//

#include <HelloPacket.h>
#include <MessagePacket.h>
#include "Server.h"
#include "Global/Global.h"
#include "Global/Global.h"

bool                isMessageValid(const std::string& ip, const std::string& header)
{
    // TODO
    return (true);
}

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
    _AllMessagesReceived = std::make_shared<std::list<std::string>>();
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
    while(!Global::Instance()->quit)
    {
        mutex_AllMessagesReceived.lock();

        while (!_AllMessagesReceived->empty())
        {
            std::string i = _AllMessagesReceived->front();
            auto beg = i.find('[');
            auto end = i.find(']');

            std::string ip = i.substr(beg + 1, end - 1);
            std::string header = i.substr(end + 1, 3);
            std::string packetContent = i.substr(end + 4);

            if (isMessageValid(ip, header))
                this->TreatMessage(header, packetContent, ip);
            _AllMessagesReceived->pop_front();
            mutex_AllMessagesReceived.unlock();
        }
        mutex_AllMessagesReceived.unlock();
    }
    return 0;
}

int                 Server::TreatMessage(const std::string& header, const std::string& packetContent, const std::string& ip)
{
    if (header == "bye")
        this->deleteUser(ip);
    else if (header == "0x0")
        this->HelloPacketHandler(packetContent, ip);
    else if (header == "0x1")
        this->MessagePacketHandler(packetContent, ip);
    return (0);
}

int                 Server::HelloPacketHandler(const std::string& packetContent, const std::string& ip)
{
    HelloPacket     helloPacket;
    helloPacket.buildObjectFromJSON(packetContent);

    std::shared_ptr<User> newUser = std::make_shared<User>(helloPacket.getUsername(), ip);

    if (_RoomManager.addUser(newUser) == -1)
    {
        std::cout << "error addUser" << std::endl;
        // TODO renvoyer connection REFUSED
        return (-1);
    }
    // TODO renvoyer connection OK
    return (0);
}

int                 Server::MessagePacketHandler(const std::string& packetContent, const std::string& ip)
{
    MessagePacket   messagePacket;

    messagePacket.buildObjectFromJSON(packetContent);
    return (0);
}

int                 Server::deleteUser(const std::string& ip)
{
    _RoomManager.deleteUser(ip);
    return 0;
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
