#ifndef ROOM_HPP
#define ROOM_HPP

#include "Player.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <boost/asio.hpp>
#include <list>



class Room
{
public:
  Room();
  ~Room(){};

  void Launch_game();
  void Send_ToAll_Time_ToPlay();
  void Add_Player(Player player);
  ///void Receive_Message();
  int  Size_Of_Room();
  void SetNbrRoom(int nbr);
  bool Full_Room();
private:
  int NumberRoom;

  std::list<Player> players;
  enum {max_length = 1024};
  char data_[max_length];
};

#endif
