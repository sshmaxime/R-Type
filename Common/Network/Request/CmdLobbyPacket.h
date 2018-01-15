//
// Created by sshsupreme on 10/01/18.
//

#ifndef R_TYPE_CMDLOBBYPACKET_H
#define R_TYPE_CMDLOBBYPACKET_H

#include "Request.h"

class CmdLobbyPacket : public JSONObject{
public:
    CmdLobbyPacket()                {__HEADER__ = "0x2";}
    ~CmdLobbyPacket()               = default;

private:
    std::string                     _Username;
    std::string                     _Command;

public:
int                                 buildObjectFromJSON(const std::string&) override;

public:
    void                            setUsername(const std::string&);
    void                            setCommand(const std::string&);

public:
    std::string                     getUsername() const;
    std::string                     getCommand() const;
};


#endif //R_TYPE_CMDLOBBYPACKET_H
