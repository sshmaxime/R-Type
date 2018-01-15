#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <boost/asio.hpp>
#include <list>

using boost::asio::ip::udp;

class Player
{
public:
  Player(udp::endpoint end);
  ~Player(){};
  void SetName(std::string Pseudo);
  std::string GetName();

private:
  udp::endpoint endpoint;
  std::string Name;
};

#endif
