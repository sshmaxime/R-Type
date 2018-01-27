//
// Created by sshsupreme on 27/01/18.
//

#ifndef R_TYPE_CGLOBAL_H
#define R_TYPE_CGLOBAL_H

#include <boost/asio/ip/udp.hpp>

using boost::asio::ip::udp;

class  CGlobal {
public:
    static                  CGlobal* Instance();
    CGlobal&                operator= (const CGlobal&){}

    CGlobal                  (const CGlobal&){}

private:

    static CGlobal           m_instance;
    CGlobal()                = default;
    ~CGlobal()               = default;

public:
    bool                    quit = false;
    udp::socket             *_Socket = NULL;
    boost::asio::io_service *_Service;

};


#endif //R_TYPE_CGLOBAL_H
