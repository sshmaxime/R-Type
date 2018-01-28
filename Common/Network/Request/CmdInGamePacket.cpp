//
// Created by sshsupreme on 10/01/18.
//

#include "CmdInGamePacket.h"

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
    _JSON["command"] = this->_Command;
}

void                    CmdInGamePacket::setCommandContent(const std::string& newCommandContent)
{
    this->_CommandContent = newCommandContent;
    _JSON["commandContent"] = this->_CommandContent;
}

void                    CmdInGamePacket::setUsername(const std::string& newUsername)
{
    this->_Username = newUsername;
    _JSON["username"] = this->_Username;
}

const std::string &CmdInGamePacket::getUsername() const
{
    return (this->_Username);
}

const std::string &CmdInGamePacket::getCommand() const
{
    return (this->_Command);
}

const std::string &CmdInGamePacket::getCommandContent() const
{
    return (this->_CommandContent);
}
