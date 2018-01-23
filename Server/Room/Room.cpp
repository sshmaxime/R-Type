//
// Created by sshsupreme on 20/01/18.
//

#include "Room.h"

bool                    Room::isAvailable() const
{
    if (_Users.size() >= 4)
        return (false);
    return (true);
}

bool                    Room::isDuplicate(const std::shared_ptr<User> newUser) const
{
    for (const auto &user : _Users)
    {
        if (user->getUsername() == newUser->getUsername())
        {
            std::cout << "Name already used" << std::endl;
            return (true);
        }
        if (user->getFullIp() == newUser->getFullIp())
        {
            std::cout << "Already connected" << std::endl;
            return (true);
        }
    }
    return (false);
}

int                     Room::addUser(const std::shared_ptr<User> newUser)
{
    if (_Users.size() >= 4)
        return (-1);
    if (isDuplicate(newUser))
        return (-1);

    _Users.emplace_back(newUser);
    std::cout << "User added" << std::endl;
    return 0;
}

bool                    Room::isUserIn(const std::string &ip) const
{
    for (const auto &user : _Users)
    {
        if (user->getFullIp() == ip)
            return (true);
    }
    return false;
}

bool                    Room::deleteUser(const std::string& ip)
{
    for (auto it = _Users.begin(); it != _Users.end();)
    {
        if(it->get()->getFullIp() == ip)
        {
            it = _Users.erase(it);
            return (true);
        }
        else
            ++it;
    }
    return false;
}

bool                    Room::isEmpty() const
{
    if (_Users.size() == 0)
        return (true);
    return (false);
}

Room::Room()
{
    std::cout << "Room created" << std::endl;
}

Room::~Room()
{
    std::cout << "Room deleted" << std::endl;
}
