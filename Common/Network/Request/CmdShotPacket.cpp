//
// Created by sshsupreme on 14/01/18.
//

#include "CmdShotPacket.h"

int                     CmdShotPacket::buildObjectFromJSON(const std::string& JSONString)
{
    try {
        _JSON = JSON::parse(JSONString);

        this->_Username = _JSON["username"];
    } catch (std::exception &exception) {
        std::cout << "Error Parsing CmdLobbyPacket" << std::endl;
        return (-1);
    }
    return (0);
}

void                    CmdShotPacket::setUsername(const std::string& newUsername)
{
    this->_Username = newUsername;
    _JSON["username"] = this->_Username;

    std::string a = _JSON["username"];
    std::cout << "name in json = " + a << std::endl;
}

const std::string &CmdShotPacket::getUsername() const
{
    return (this->_Username);
}
