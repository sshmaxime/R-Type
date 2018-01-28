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

int                 RoomManager::checkEmptyRoom()
{
    for (auto it = _Rooms.begin(); it != _Rooms.end();)
    {
        if (it->get()->isEmpty())
        {
            it->get()->Shutdown();
            it = _Rooms.erase(it);
            return (0);
        }
        else
            ++it;
    }
    return (-1);
}

int                 RoomManager::deleteUser(const std::string& ip)
{
    for (const auto &room : _Rooms)
    {
        if (room->isUserIn(ip))
        {
            room->deleteUser(ip);
            checkEmptyRoom();
            return (0);
        }
    }
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
