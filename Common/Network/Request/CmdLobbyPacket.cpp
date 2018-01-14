//
// Created by sshsupreme on 10/01/18.
//

#include "CmdLobbyPacket.h"

std::string             CmdLobbyPacket::getJSON()
{
    return (_JSON.dump(-1));
}

int                     CmdLobbyPacket::buildObjectFromJSON(const std::string& JSONString)
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

void                    CmdLobbyPacket::setUsername(const std::string& newUsername)
{
    this->_Username = newUsername;
    _JSON.emplace("username", this->_Username);
}

void                    CmdLobbyPacket::setCommand(const std::string& newCommand)
{
    this->_Command = newCommand;
    _JSON.emplace("command", this->_Command);
}