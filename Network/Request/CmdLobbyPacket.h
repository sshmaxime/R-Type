//
// Created by sshsupreme on 10/01/18.
//

#ifndef R_TYPE_CMDLOBBYPACKET_H
#define R_TYPE_CMDLOBBYPACKET_H

#include "Request.h"

class CmdLobbyPacket : public JSONObject{
public:
    CmdLobbyPacket();
    ~CmdLobbyPacket();

private:
    std::string                     _Username = NULL;
    std::string                     _Command = NULL;

public:
int                                 buildObjectFromJSON(const std::string&);
std::string                         buildJSONFromObject();
};


#endif //R_TYPE_CMDLOBBYPACKET_H
