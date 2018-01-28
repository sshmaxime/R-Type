//
// Created by sshsupreme on 10/01/18.
//

#include "HelloPacket.h"

int                     HelloPacket::buildObjectFromJSON(const std::string& JSONString)
{
    try {
        _JSON = JSON::parse(JSONString);

        this->_Username = _JSON.at("username");
    } catch (std::exception &exception) {
        std::cout << "Error Parsing HelloPacket" << std::endl;
        return (-1);
    }
    return (0);
}

void                    HelloPacket::setUsername(const std::string& newUsername)
{
    this->_Username = newUsername;
  _JSON.at("username") = this->_Username;
}

std::string &HelloPacket::getUsername() const
{
    return (this->_Username);
}

