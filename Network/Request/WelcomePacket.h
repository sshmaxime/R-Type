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
    std::string                     _Username;

public:
    void                            setUsername(const std::string&);

public:
    int                             buildObjectFromJSON(const std::string&);
    std::string                     getJSON();
};


#endif //R_TYPE_WELCOMEPACKET_H
