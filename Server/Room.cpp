#include "Room.hpp"

Room::Room()
{
}

void Room::Launch_game()
{

}

void Room::Send_ToAll_Time_ToPlay()
{

}

int Room::Size_Of_Room()
{
  return (players.size());
}

void Room::SetNbrRoom(int nbr)
{
  NumberRoom = nbr;
}

void Room::Add_Player(Player player)
{
  if (players.size() < 4)
  {
    players.push_front(player);
  }
  if (players.size() == 4)
  {
    std::cout << "allez on envoi le jeux la!\n";
    //la je thread et j'envoi le jeux
  }
}

bool Room::Full_Room()
{
  if (players.size() < 4)
    return true;
  return false;
}

/*void  Room::Receive_Message()
{
  socket_.async_receive_from(
      boost::asio::buffer(data_, max_length), sender_endpoint_,
      [this](boost::system::error_code ec, std::size_t bytes_recvd)
      {
        if (!ec && bytes_recvd > 0)
        {
          std::cout << "Dans la Room -> " << data_ << "\n";
        }
      });
}*/
