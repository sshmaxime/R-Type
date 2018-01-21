//
// Created by sshsupreme on 20/01/18.
//

#ifndef R_TYPE_SNETWORK_H
#define R_TYPE_SNETWORK_H

#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/asio/error.hpp>
#include <queue>
#include "../../Common/JSON/JSONObject.h"

using boost::asio::ip::udp;

class SNetwork {
public:
    SNetwork()              = default;
    ~SNetwork();

public:
    int                     Initialize(int, std::shared_ptr<std::queue<std::string>>);
    int                     Send(JSONObject&);
    void                    handleReceive(const boost::system::error_code& error, size_t bytes);
    int                     Receive();
    int                     Stop();
    int                     Run();

private:
    boost::asio::io_service _Service;
    udp::socket             *_Socket = NULL;
    udp::endpoint           _Endpoint;

private:
    std::shared_ptr<std::queue<std::string>> _AllMessagesReceived;

public:
    enum                    { max_length = 1024 };
    boost::array<char, 128> _DATA;
};


#endif //R_TYPE_SNETWORK_H
