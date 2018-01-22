//
// Created by sshsupreme on 14/01/18.
//

#include "User.h"

std::string                 User::getUsername() const
{
    return (this->_Username);
}

std::string                 User::getIp() const
{
    return (this->_IP);
}

User::User(const std::string& username, const std::string& ip)
{
    this->_IP = ip;
    this->_Username = username;
}
