//
// Created by sshsupreme on 14/01/18.
//

#ifndef R_TYPE_USER_H
#define R_TYPE_USER_H

#include <string>

class User {
public:
    User(const std::string&, const std::string&);
    ~User()                 = default;

private:
    std::string             _IP;
    std::string             _Username;

public:
    std::string             getIp() const;
    std::string             getUsername() const;
};


#endif //R_TYPE_USER_H
