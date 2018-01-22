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
        if (user->getIp() == newUser->getIp())
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

Room::Room()
{
    std::cout << "Room created" << std::endl;
}

Room::~Room()
{
    std::cout << "Room deleted" << std::endl;
}

