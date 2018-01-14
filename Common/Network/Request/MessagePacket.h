//
// Created by sshsupreme on 10/01/18.
//

#ifndef R_TYPE_MESSAGEPACKET_H
#define R_TYPE_MESSAGEPACKET_H


#include "Request.h"

class MessagePacket : public JSONObject {
public:
    MessagePacket()                 {__HEADER__ = "0x1";}
    ~MessagePacket()                {}

private:
    std::string                     _Message;
    std::string                     _Username;

public:
    int                             buildObjectFromJSON(const std::string&);
    std::string                     getJSON();

public:
    void                            setMessage(const std::string&);
    void                            setUsername(const std::string&);
};


#endif //R_TYPE_MESSAGEPACKET_H
