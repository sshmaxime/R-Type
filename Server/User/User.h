//
// Created by sshsupreme on 14/01/18.
//

#ifndef R_TYPE_USER_H
#define R_TYPE_USER_H

#include <string>
#include <boost/asio/ip/udp.hpp>
#include <Request.h>

using boost::asio::ip::udp;

class User {
public:
    User(const std::string&, const std::string&);
    ~User();

private:
    std::string             _FullIP;
    std::string             _Username;
    std::string             _Port;
    std::string             _IP;
    udp::endpoint           _Endpoint;
    int                     _ID;

public:
    std::string             getFullIp() const;
    std::string             getUsername() const;
    std::string             getPort() const;
    std::string             getIp() const;
    int                     getID() const;
    void                    setID(int);

public:
    void                    send(const JSONObject&) const;
    void                    send(const std::string&) const;
    void                    handleSend(const boost::system::error_code&, std::size_t) {}

};


#endif //R_TYPE_USER_H
