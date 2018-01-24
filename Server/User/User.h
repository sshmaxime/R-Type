//
// Created by sshsupreme on 14/01/18.
//

#ifndef R_TYPE_USER_H
#define R_TYPE_USER_H

#include <string>

class User {
public:
    User(const std::string&, const std::string&);
    ~User();

private:
    std::string             _FullIP;
    std::string             _Username;
    std::string             _Port;
    std::string             _IP;

public:
    std::string             getFullIp() const;
    std::string             getUsername() const;
    std::string             getPort() const;
    std::string             getIp() const;
};


#endif //R_TYPE_USER_H
