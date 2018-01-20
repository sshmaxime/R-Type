//
// Created by sshsupreme on 17/01/18.
//

#ifndef R_TYPE_NETWORK_H
#define R_TYPE_NETWORK_H

#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/asio/error.hpp>
#include <WelcomePacket.h>

using boost::asio::ip::udp;

class Network {
public:
    Network()               = default;
    ~Network()              = default;

public:
    int                     Initialize(const std::string&, int);
    int                     Send(JSONObject&);
    int                     Run();
    int                     Delete();
    void                    handleReceive(const boost::system::error_code& error, size_t bytes);

private:
    boost::asio::io_service _Service;
    udp::socket             *_Socket;
    udp::endpoint           _Endpoint;
    udp::endpoint           _SenderEndpoint;

public:
    enum                    { max_length = 1024 };
    boost::array<char, 128> _DATA;
};


#endif //R_TYPE_NETWORK_H
