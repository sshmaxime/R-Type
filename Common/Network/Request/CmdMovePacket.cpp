//
// Created by sshsupreme on 14/01/18.
//

#include "CmdMovePacket.h"

std::string             CmdMovePacket::getJSON()
{
    return (_JSON.dump(-1));
}

int                     CmdMovePacket::buildObjectFromJSON(const std::string& JSONString)
{
    try {
        _JSON = JSON::parse(JSONString);

        this->_Username = _JSON.at("username");
        this->_Command = _JSON.at("command");
    } catch (std::exception &exception) {
        std::cout << "Error Parsing CmdLobbyPacket" << std::endl;
        return (-1);
    }
    return (0);
}

void                    CmdMovePacket::setUsername(const std::string& newUsername)
{
    this->_Username = newUsername;
    _JSON.emplace("username", this->_Username);
}

void                    CmdMovePacket::setCommand(const std::string& newCommand)
{
    this->_Command = newCommand;
    _JSON.emplace("command", this->_Command);
}