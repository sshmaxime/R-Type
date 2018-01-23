//
// Created by sshsupreme on 14/01/18.
//

#include <iostream>
#include "User.h"

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

User::User(const std::string& username, const std::string& ip)
{
    this->_FullIP = ip;
    this->_Username = username;

    auto pos = _FullIP.find(':');
    this->_Port = _FullIP.substr(0, pos);
    this->_IP = _FullIP.substr(pos + 1);
}

User::~User()
{
    std::cout << "User " + _Username + " deleted" << std::endl;
}
