//
// Created by sshsupreme on 17/01/18.
//

#include <iostream>
#include <MessagePacket.h>
#include "Network.h"

int                     Network::Initialize(const std::string &ip, int port)
{
    try {
        _Endpoint = udp::endpoint(boost::asio::ip::address_v4::from_string(ip.c_str()), port);
        _Socket = new udp::socket(this->_Service);
        _Socket->open(udp::v4());

        _Socket->async_receive_from(
                boost::asio::buffer(_DATA, max_length), _SenderEndpoint,
                boost::bind(&Network::handleReceive, this,
                            boost::asio::placeholders::error,
                            boost::asio::placeholders::bytes_transferred));
    } catch (std::exception &exception) {
        std::cout << exception.what() << std::endl;
        this->Delete();
        return (-1);
    }
    return 0;
}

void                    Network::handleReceive(const boost::system::error_code &error, size_t bytes)
{
    std::cout << std::string(_DATA.c_array()) << std::endl;
}

int                     Network::Send(JSONObject& toSend)
{
    std::string         JSONtoString = toSend.getHEADER() + toSend.getJSON();

    try {
        _Socket->send_to(boost::asio::buffer(JSONtoString), _Endpoint);
    } catch (std::exception& exception) {
        std::cout << exception.what() << std::endl;
    }

    return (0);
}

int                     Network::Run()
{
    // Do whatever we want to
    this->Delete();
    return 0;
}

int                     Network::Delete()
{
    delete _Socket;
    return 0;
}
