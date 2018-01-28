//
// Created by sshsupreme on 22/01/18.
//

#ifndef R_TYPE_ROOMMANAGER_H
#define R_TYPE_ROOMMANAGER_H


#include <vector>
#include <boost/asio/detail/shared_ptr.hpp>
#include "../User/User.h"
#include "Room.h"
#include <memory>

class RoomManager {
public:
    RoomManager()                   = default;
    ~RoomManager()                  = default;

public:
    std::vector<std::shared_ptr<Room>> _Rooms;

public:
    int                             sendInRoom(const std::string&);

public:
    int                             addUser(std::shared_ptr<User>);
    int                             deleteUser(const std::string&);
    int                             stop();

private:
    int                             createRoom(std::shared_ptr<User>);
    int                             checkEmptyRoom();
};


#endif //R_TYPE_ROOMMANAGER_H
