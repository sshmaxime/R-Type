//
// Created by sshsupreme on 20/01/18.
//

#ifndef R_TYPE_ROOM_H
#define R_TYPE_ROOM_H


#include <vector>
#include "../User/User.h"

class Room {
public:
    Room()                  = default;
    ~Room()                 = default;

private:
    std::vector<User>       _Users;
};


#endif //R_TYPE_ROOM_H
