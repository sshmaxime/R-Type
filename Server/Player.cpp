#include "Player.hpp"

Player::Player(udp::endpoint end)
{
  endpoint = end;
}

void    Player::SetName(std::string Pseudo)
{
  Name = Pseudo;
}

std::string   Player::GetName()
{
  return (Name);
}
