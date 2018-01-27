//
// Created by sshsupreme on 20/01/18.
//

#include "SNetwork.h"
#include "../Global/Global.h"
#include "../Global/Global.h"

std::mutex              mutex_AllMessagesReceived;

int                 SNetwork::Initialize(int port, std::shared_ptr<std::list<std::string>>& queue)
{
    _AllMessagesReceived = queue;

    try {
        _Socket = new udp::socket(_Service, udp::endpoint(udp::v4(), port));
        Global::Instance()->_Socket = _Socket;
        this->Receive();
    } catch (std::exception& exception) {
        std::cout << exception.what() << std::endl;
        return (-1);
    }
    return 0;
}

int                 SNetwork::Receive()
{
    try {
        _Socket->async_receive_from(
                boost::asio::buffer(_DATA), _Endpoint,
                boost::bind(&SNetwork::handleReceive, this,
                            boost::asio::placeholders::error,
                            boost::asio::placeholders::bytes_transferred));
    } catch (std::exception& exception) {
        std::cout << exception.what() << std::endl;
        return (-1);
    }
    return (0);
}

int                 SNetwork::Send(JSONObject &toSend)
{
    return 0;
}

int                 SNetwork::Run()
{
    try {
        _Service.run();
    } catch (std::exception &exception) {
        std::cout << exception.what() << std::endl;
        return (-1);
    }
    return (0);
}

void                printQueue(std::shared_ptr<std::list<std::string>> lol)
{
    int x = 0;
    std::cout << "print" << std::endl;
    for (const auto item : *lol)
    {
        std::cout << item + "->tst" << std::endl;
    }

}

void                SNetwork::handleReceive(const boost::system::error_code &error, size_t bytes)
{
    std::string     msgSender = "[" + _Endpoint.address().to_string() + ":" + std::to_string(_Endpoint.port()) + "]";

    _DATA.at(bytes) = '\0';
    if (Global::Instance()->quit)
    {
        _Socket->close();
        return;
    }
    mutex_AllMessagesReceived.lock();
    _AllMessagesReceived->push_back(msgSender + std::string(_DATA.c_array()));
    mutex_AllMessagesReceived.unlock();

    this->Receive();
}

int                 SNetwork::Stop()
{
    if (!this->_Service.stopped())
        this->_Service.stop();
    return (0);
}

SNetwork::~SNetwork()
{
    if (_Socket != nullptr)
        delete _Socket;
    if (!this->_Service.stopped())
        this->_Service.stop();
}
