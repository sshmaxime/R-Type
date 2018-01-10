//
// Created by sshsupreme on 10/01/18.
//

#include "CmdLobbyPacket.h"

std::string             CmdLobbyPacket::buildJSONFromObject()
{
    json                newJSON;

    newJSON.emplace("username", this->_Username);
    newJSON.emplace("command", this->_Command);
    return (newJSON.dump(-1));
}

int                     CmdLobbyPacket::buildObjectFromJSON(const std::string& JSONString)
{
    std::string         Username;
    std::string         Command;

    try {
        json j = json::parse(JSONString);

        Username = j.at("username");
        Command = j.at("command");
    } catch (std::exception exception) {
        std::cout << "Error Parsing CmdLobbyPacket" << std::endl;
        return (-1);
    }
    this->_Username = Username;
    this->_Command = Command;
    return (0);
}