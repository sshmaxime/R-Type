//
// Created by sshsupreme on 10/01/18.
//

#include "WelcomePacket.h"

int                     WelcomePacket::buildObjectFromJSON(const std::string& JSONString)
{
    try {
        _JSON = JSON::parse(JSONString);

        this->_Username = _JSON.at("username");
    } catch (std::exception &exception) {
        std::cout << "Error Parsing WelcomePacket" << std::endl;
        return (-1);
    }
    return (0);
}

void                    WelcomePacket::setUsername(const std::string& newUsername)
{
    this->_Username = newUsername;
    _JSON.emplace("username", this->_Username);
}

std::string             WelcomePacket::getUsername() const
{
    return (this->_Username);
}

