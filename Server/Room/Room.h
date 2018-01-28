//
// Created by sshsupreme on 20/01/18.
//

#ifndef R_TYPE_ROOM_H
#define R_TYPE_ROOM_H


#include <vector>
#include "../User/User.h"
#include "../../Game/Core/Core.hpp"
#include <iostream>
#include <boost/asio/detail/shared_ptr.hpp>
#include <thread>

class Room {
public:
    Room();
    ~Room();

private:
    std::vector<std::shared_ptr<User>>  _Users;
  Core _Game;
  std::thread _ThreadGame;

public:
    bool                    isAvailable() const;
    int                     addUser(const std::shared_ptr<User>);
    bool                    isDuplicate(const std::shared_ptr<User>) const;
    bool                    isUserIn(const std::string&) const;
    bool                    deleteUser(const std::string&);
    bool                    isEmpty() const;

  int checkStart();

  int startGame();

  int Shutdown();

  int Send(const std::string &);
};


#endif //R_TYPE_ROOM_H
