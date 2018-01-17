//
// Created by sshsupreme on 17/01/18.
//

#include "Client.h"

int Client::Initialize(const std::string& ip, int port)
{
    if (_Network.Initialize(ip, port) == -1)
        return (-1);
    return 0;
}

int Client::Run()
{
    _Network.Run();
    return 0;
}

int Client::Delete()
{
    return 0;
}
