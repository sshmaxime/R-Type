//
// Created by sshsupreme on 14/01/18.
//

#ifndef R_TYPE_CMDMOVEPACKET_H
#define R_TYPE_CMDMOVEPACKET_H

#include "Request.h"

class CmdMovePacket : public JSONObject{
public:
    CmdMovePacket()                 {__HEADER__ = "1x1";}
    ~CmdMovePacket()                = default;

private:
    std::string                     _Username;
    std::string                     _Command;

public:
    int                             buildObjectFromJSON(const std::string&) override;

public:
    void                            setCommand(const std::string&);
    void                            setUsername(const std::string&);

public:
    std::string                     getCommand() const;
    std::string                     getUsername() const;
};



#endif //R_TYPE_CMDMOVEPACKET_H
