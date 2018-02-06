//
// Created by sshsupreme on 14/01/18.
//

#include <iostream>
#include <boost/asio.hpp>
#include "User.h"
#include "../Global/Global.h"

std::string                 User::getUsername() const
{
    return (this->_Username);
}

std::string                 User::getFullIp() const
{
    return (this->_FullIP);
}

std::string                 User::getIp() const
{
    return (this->_IP);
}

std::string                 User::getPort() const
{
    return (this->_Port);
}

void                        User::send(const JSONObject& toSend) const
{
    std::string             JSONtoString = toSend.getHEADER() + toSend.getJSON();

    try {
        Global::Instance()->_Socket->send_to(boost::asio::buffer(JSONtoString), _Endpoint);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void                        User::send(const std::string& msg) const
{
    try {
        Global::Instance()->_Socket->send_to(boost::asio::buffer(msg), _Endpoint);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

User::User(const std::string& username, const std::string& ip)
{
    this->_FullIP = ip;
    this->_Username = username;

    auto pos = _FullIP.find(':');
    this->_IP = _FullIP.substr(0, pos);
    this->_Port = _FullIP.substr(pos + 1);

    try {
        this->_Endpoint = udp::endpoint(boost::asio::ip::address_v4::from_string(this->_IP), std::stoi(this->_Port));
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    this->send("received");
}

User::~User()
{
    std::cout << "User " + _Username + " deleted" << std::endl;
}
