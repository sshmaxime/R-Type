//
// Created by sshsupreme on 10/01/18.
//

#ifndef R_TYPE_MESSAGEPACKET_H
#define R_TYPE_MESSAGEPACKET_H


#include "Request.h"

class MessagePacket : public JSONObject {
public:
    MessagePacket();
    ~MessagePacket();

private:
    std::string                     _Message = NULL;
    std::string                     _Username= NULL;

public:
    int                             buildObjectFromJSON(const std::string&);
    std::string                     buildJSONFromObject();

};


#endif //R_TYPE_MESSAGEPACKET_H
