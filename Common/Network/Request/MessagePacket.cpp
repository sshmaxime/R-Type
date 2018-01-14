//
// Created by sshsupreme on 10/01/18.
//

#include "MessagePacket.h"

int                     MessagePacket::buildObjectFromJSON(const std::string& JSONString)
{
    try {
        _JSON = JSON::parse(JSONString);

        this->_Username = _JSON.at("username");
        this->_Message = _JSON.at("message");
    } catch (std::exception &exception) {
        std::cout << "Error Parsing MessagePacket" << std::endl;
        return (-1);
    }
    return (0);
}

void                    MessagePacket::setUsername(const std::string& newUsername)
{
    this->_Username = newUsername;
    _JSON.emplace("username", this->_Username);
}

void                    MessagePacket::setMessage(const std::string& newMessage)
{
    this->_Message = newMessage;
    _JSON.emplace("message", this->_Message);
}

std::string             MessagePacket::getUsername() const
{
    return (this->_Username);
}

std::string             MessagePacket::getMessage() const
{
    return (this->_Message);
}
