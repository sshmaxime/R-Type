//
// Created by sshsupreme on 10/01/18.
//

#include "WelcomePacket.h"

std::string             WelcomePacket::buildJSONFromObject()
{
    json                newJSON;

    newJSON.emplace("username", this->_Username);
    return (newJSON.dump(-1));
}

int                     WelcomePacket::buildObjectFromJSON(const std::string& JSONString)
{
    std::string         Username;

    try {
        json j = json::parse(JSONString);

        Username = j.at("username");
    } catch (std::exception exception) {
        std::cout << "Error Parsing WelcomePacket" << std::endl;
        return (-1);
    }
    this->_Username = Username;
    return (0);
}