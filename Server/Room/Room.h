//
// Created by sshsupreme on 20/01/18.
//

#ifndef R_TYPE_ROOM_H
#define R_TYPE_ROOM_H


#include <vector>
#include "../User/User.h"
#include <iostream>
#include <boost/asio/detail/shared_ptr.hpp>

class Room {
public:
    Room();
    ~Room();

private:
    std::vector<std::shared_ptr<User>>  _Users;

public:
    bool                    isAvailable() const;
    int                     addUser(const std::shared_ptr<User>);
    bool                    isDuplicate(const std::shared_ptr<User>) const;
    bool                    isUserIn(const std::string&) const;
    bool                    deleteUser(const std::string&);
    bool                    isEmpty() const;
};


#endif //R_TYPE_ROOM_H
