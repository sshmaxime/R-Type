//
// Created by sshsupreme on 10/01/18.
//

#ifndef R_TYPE_WELCOMEPACKET_H
#define R_TYPE_WELCOMEPACKET_H

#include "Request.h"

class HelloPacket : public JSONObject{
public:
    HelloPacket()                 {__HEADER__ = "0x0";};
    ~HelloPacket()                = default;

private:
    std::string                     _Username;

public:
    int                             buildObjectFromJSON(const std::string&) override;

public:
    void                            setUsername(const std::string&);

public:
    std::string                     getUsername() const;
};


#endif //R_TYPE_WELCOMEPACKET_H
