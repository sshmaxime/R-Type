//
// Created by sshsupreme on 10/01/18.
//

#include "CmdInGame.h"

std::string             CmdInGame::buildJSONFromObject()
{
    json                newJSON;

    newJSON.emplace("username", this->_Username);
    newJSON.emplace("command", this->_Command);
    newJSON.emplace("commandContent", this->_Command);
    return (newJSON.dump(-1));
}

int                     CmdInGame::buildObjectFromJSON(const std::string& JSONString)
{
    std::string         Username;
    std::string         Command;
    std::string         CommandContent;

    try {
        json j = json::parse(JSONString);

        Username = j.at("username");
        Command = j.at("command");
        CommandContent = j.at("commandContent");
    } catch (std::exception exception) {
        std::cout << "Error Parsing CmdInGame" << std::endl;
        return (-1);
    }
    this->_Username = Username;
    this->_Command = Command;
    this->_CommandContent = CommandContent;
    return (0);
}