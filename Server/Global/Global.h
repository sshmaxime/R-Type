//
// Created by sshsupreme on 20/01/18.
//

#ifndef R_TYPE_GLOBAL_H
#define R_TYPE_GLOBAL_H

#include <boost/asio/ip/udp.hpp>
#include <mutex>

using boost::asio::ip::udp;


class Global {
public:
    static                  Global& Instance();
    Global&                 operator= (const Global&){}

    Global                  (const Global&){}

private:

    static Global           m_instance;
    Global()                = default;
    ~Global()               = default;

public:
    bool                    quit = false;
    udp::socket             *_Socket = NULL;

public:
    std::mutex              mutex_AllMessagesReceived;
};


#endif //R_TYPE_GLOBAL_H
