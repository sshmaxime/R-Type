//
// Created by sshsupreme on 20/01/18.
//

#include "SNetwork.h"
#include "../Global/Global.h"

int                 SNetwork::Initialize(int port)
{
    try {
        _Socket = new udp::socket(_Service, udp::endpoint(udp::v4(), port));
        Global::Instance()._Socket = _Socket;
        this->Receive();
        _Service.run();

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


void                SNetwork::handleReceive(const boost::system::error_code &error, size_t bytes)
{
    _DATA.at(bytes) = '\0';
    std::cout << std::string(_DATA.c_array()) << std::endl;

    if (Global::Instance().quit)
    {
        _Socket->close();
        return ;
    }
    this->Receive();
}

SNetwork::~SNetwork()
{
    delete _Socket;
    this->_Service.stop();
}