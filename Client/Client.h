//
// Created by sshsupreme on 17/01/18.
//

#ifndef R_TYPE_CLIENT_H
#define R_TYPE_CLIENT_H

#include "Network/CNetwork.h"

class Client {
public:
    Client()                = default;
    ~Client()               = default;

private:
    CNetwork                 _Network;

public:
    int                     Initialize(const std::string&, int);
    int                     Run();
    int                     Delete();
};


#endif //R_TYPE_CLIENT_H
