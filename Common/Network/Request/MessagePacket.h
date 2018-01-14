//
// Created by sshsupreme on 10/01/18.
//

#ifndef R_TYPE_MESSAGEPACKET_H
#define R_TYPE_MESSAGEPACKET_H

#include "Request.h"

class MessagePacket : public JSONObject {
public:
    MessagePacket()                 {__HEADER__ = "0x1";}
    ~MessagePacket()                = default;

private:
    std::string                     _Message;
    std::string                     _Username;

public:
    int                             buildObjectFromJSON(const std::string&) override;

public:
    void                            setMessage(const std::string&);
    void                            setUsername(const std::string&);

public:
    std::string                     getMessage() const;
    std::string                     getUsername() const;
};


#endif //R_TYPE_MESSAGEPACKET_H
