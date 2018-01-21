//
// Created by sshsupreme on 20/01/18.
//

#include "SNetwork.h"
#include "../Global/Global.h"

int                 SNetwork::Initialize(int port, std::shared_ptr<std::queue<std::string>> queue)
{
    _AllMessagesReceived = queue;

    try {
        _Socket = new udp::socket(_Service, udp::endpoint(udp::v4(), port));
        Global::Instance()._Socket = _Socket;
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

void                SNetwork::handleReceive(const boost::system::error_code &error, size_t bytes)
{
    _DATA.at(bytes) = '\0';
    if (Global::Instance().quit)
    {
        _Socket->close();
        return;
    }
    this->Receive();
    Global::Instance().mutex_AllMessagesReceived.lock();
    _AllMessagesReceived->push(std::string(_DATA.c_array()));
    Global::Instance().mutex_AllMessagesReceived.unlock();
}

int                 SNetwork::Stop()
{
    if (!this->_Service.stopped())
        this->_Service.stop();
    return (0);
}

SNetwork::~SNetwork()
{
    if (_Socket != NULL)
        delete _Socket;
    if (!this->_Service.stopped())
        this->_Service.stop();
}
