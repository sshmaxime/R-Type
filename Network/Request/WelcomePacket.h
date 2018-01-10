//
// Created by sshsupreme on 10/01/18.
//

#ifndef R_TYPE_WELCOMEPACKET_H
#define R_TYPE_WELCOMEPACKET_H

#include "Request.h"

class WelcomePacket : public JSONObject{
public:
    WelcomePacket()                 {};
    ~WelcomePacket()                {};

private:
    std::string                     _Username = NULL;

public:
    int                             buildObjectFromJSON(const std::string&);
    std::string                     buildJSONFromObject();
};


#endif //R_TYPE_WELCOMEPACKET_H
