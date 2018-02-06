//
// Created by sshsupreme on 14/01/18.
//

#ifndef R_TYPE_CMDSHOTPACKET_H
#define R_TYPE_CMDSHOTPACKET_H

#include "Request.h"

class CmdShotPacket : public JSONObject{
public:
    CmdShotPacket()                 {__HEADER__ = "1x2";}
    ~CmdShotPacket()                = default;

private:
    std::string                     _Username;

public:
    int                             buildObjectFromJSON(const std::string&) override;

public:
    void                            setUsername(const std::string&);

public:
    const std::string &getUsername() const;
};



#endif //R_TYPE_CMDSHOTPACKET_H
