//
// Created by sshsupreme on 14/01/18.
//

#include "CmdMovePacket.h"

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

std::string             CmdMovePacket::getUsername() const
{
    return (this->_Username);
}

std::string             CmdMovePacket::getCommand() const
{
    return (this->_Command);
}
