//
// Created by sshsupreme on 22/01/18.
//

#include "RoomManager.h"

int                 RoomManager::addUser(const std::shared_ptr<User> newUser)
{
    if (_Rooms.size() != 0 && _Rooms.at(_Rooms.size() - 1)->isAvailable())
    {
        if (this->_Rooms.at(_Rooms.size() - 1)->addUser(newUser) == -1)
            return (-1);
        return 0;
    }
    else if (_Rooms.size() < 4)
    {
        if (this->createRoom(newUser))
            return (-1);
        return 0;
    }
    return (-1);
}

int                 RoomManager::removeUser(const User& user)
{
    // TODO
    return 0;
}

int                 RoomManager::stop()
{
    // TODO
    return 0;
}

int                 RoomManager::createRoom(const std::shared_ptr<User> newUser)
{
    if (this->_Rooms.size() == 4)
        return (-1);

    std::shared_ptr<Room> newRoom = std::make_shared<Room>();
    newRoom->addUser(newUser);
    _Rooms.push_back(newRoom);
    return 0;
}
