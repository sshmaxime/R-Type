#ifndef SERVER_HPP
#define SERVER_HPP

#include <cstdlib>
#include <iostream>
#include <boost/asio.hpp>
#include <list>
#include "Room.hpp"
#include "../Request/WelcomePacket.h"
#include "../Request/MessagePacket.h"
#include <string>
using boost::asio::ip::udp;

class Server
{
public:
  Server(boost::asio::io_service& io_service, short port);
  void Receive_Message();
  void Send_Message(std::size_t length);
  void Send_Message(udp::endpoint end);
  void Repartition_in_Room(Player player);
  void Treatment_Message(udp::endpoint sender);
  bool Player_exist(udp::endpoint sender);
  bool Room_full(Room Room_check);
  bool All_Room_Full();
  void Send_Message(const char *msg, udp::endpoint send);

private:
  int lol = 0;
  udp::socket socket_;
  udp::endpoint sender_endpoint_;
  enum { max_length = 1024 };
  char data_[max_length];
  std::list<udp::endpoint> users;
  std::list<Player> players;
  std::list<Room> RoomList;
};

#endif
