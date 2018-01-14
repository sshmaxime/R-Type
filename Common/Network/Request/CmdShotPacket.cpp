//
// Created by sshsupreme on 14/01/18.
//

#include "CmdShotPacket.h"


std::string             CmdShotPacket::getJSON()
{
    return (_JSON.dump(-1));
}

int                     CmdShotPacket::buildObjectFromJSON(const std::string& JSONString)
{
    try {
        _JSON = JSON::parse(JSONString);

        this->_Username = _JSON.at("username");
    } catch (std::exception &exception) {
        std::cout << "Error Parsing CmdLobbyPacket" << std::endl;
        return (-1);
    }
    return (0);
}

void                    CmdShotPacket::setUsername(const std::string& newUsername)
{
    this->_Username = newUsername;
    _JSON.emplace("username", this->_Username);
}

