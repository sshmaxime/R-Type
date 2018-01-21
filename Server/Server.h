//
// Created by sshsupreme on 20/01/18.
//

#ifndef R_TYPE_SERVER_H
#define R_TYPE_SERVER_H

#include <iostream>
#include <vector>
#include "Room/Room.h"
#include "Network/SNetwork.h"

class Server {
public:
    Server()                = default;
    ~Server();

private:
    SNetwork                _Network;

private:
    std::vector<Room>       _Rooms;

public:
    int                     Initialize(char*[], int);
    int                     Run();
};


#endif //R_TYPE_SERVER_H
