//
// Created by sshsupreme on 10/01/18.
//

#include "MessagePacket.h"

std::string             MessagePacket::buildJSONFromObject()
{
    json                newJSON;

    newJSON.emplace("username", this->_Username);
    newJSON.emplace("message", this->_Message);
    return (newJSON.dump(-1));
}

int                     MessagePacket::buildObjectFromJSON(const std::string& JSONString)
{
    std::string         Username;
    std::string         Message;

    try {
        json j = json::parse(JSONString);

        Username = j.at("username");
        Message = j.at("message");
    } catch (std::exception exception) {
        std::cout << "Error Parsing MessagePacket" << std::endl;
        return (-1);
    }
    this->_Username = Username;
    this->_Message = Message;
    return (0);
}