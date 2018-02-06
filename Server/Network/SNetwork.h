//
// Created by sshsupreme on 20/01/18.
//

#ifndef R_TYPE_SNETWORK_H
#define R_TYPE_SNETWORK_H

#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/asio/error.hpp>
#include <list>
#include "../../Common/JSON/JSONObject.h"

using boost::asio::ip::udp;

class SNetwork {
public:
    SNetwork()              = default;
    ~SNetwork();

public:
    int                     Initialize(int, std::shared_ptr<std::list<std::string>>&);
    void                    handleReceive(const boost::system::error_code& error, size_t bytes);

  int Send(JSONObject &);
    int                     Receive();

  int Shutdown();
    int                     Run();

private:
    udp::endpoint           _Endpoint;

private:
    std::shared_ptr<std::list<std::string>> _AllMessagesReceived;

public:
    enum                    { max_length = 1024 };
    boost::array<char, 128> _DATA;
};


#endif //R_TYPE_SNETWORK_H
