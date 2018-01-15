#ifndef USER_HPP
#define USER_HPP

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include "../Request/WelcomePacket.h"
#include "../Request/MessagePacket.h"

using boost::asio::ip::udp;

class User
{
public:
  User(boost::asio::io_service& io_service, char* host, char* port);
  void  Send_Message();
  void  Send_Message_Login();
  void  Receive_Message();
  void  SetName(std::string);
  std::string  GetName();

private:
  std::string Name;
  udp::socket socket_;
  udp::endpoint endpoint;
  udp::endpoint sender_endpoint;
  enum { max_length = 1024 };
  char message[max_length];
  char response[max_length];

};

#endif
