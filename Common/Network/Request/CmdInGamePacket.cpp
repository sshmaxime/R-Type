//
// Created by sshsupreme on 10/01/18.
//

#include "CmdInGamePacket.h"

std::string             CmdInGamePacket::getJSON()
{
    return (_JSON.dump(-1));
}

int                     CmdInGamePacket::buildObjectFromJSON(const std::string& JSONString)
{
    try {
        _JSON = JSON::parse(JSONString);

        this->_Username = _JSON.at("username");
        this->_Command = _JSON.at("command");
        this->_CommandContent = _JSON.at("commandContent");
    } catch (std::exception &exception) {
        std::cout << "Error Parsing CmdInGamePacket" << std::endl;
        return (-1);
    }
    return (0);
}

void                    CmdInGamePacket::setCommand(const std::string& newCommand)
{
    this->_Command = newCommand;
    _JSON.emplace("command", this->_Command);
}

void                    CmdInGamePacket::setCmmandContent(const std::string& newCommandContent)
{
    this->_CommandContent = newCommandContent;
    _JSON.emplace("commandContent", this->_CommandContent);
}

void                    CmdInGamePacket::setUsername(const std::string& newUsername)
{
    this->_Username = newUsername;
    _JSON.emplace("username", this->_Username);
}
