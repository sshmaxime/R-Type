#include "Server.hpp"

Server::Server(boost::asio::io_service& io_service, short port)
  : socket_(io_service, udp::endpoint(udp::v4(), port))
{
  std::memset(data_, 0, sizeof data_);
  Receive_Message();
}

void        Server::Repartition_in_Room(Player player)
{
  for (std::list<Room>::iterator it = RoomList.begin(); it != RoomList.end(); it++)
  {
    if ((*it).Size_Of_Room() < 4)
    {
      (*it).Add_Player(player);
    }
  }
}

bool        Server::Player_exist(udp::endpoint sender)
{
  if (users.size() == 0)
    return (false);
  for (std::list<udp::endpoint>::iterator it = users.begin(); it != users.end(); it++)
    {
      if ((*it) == sender)
        return (true);
    }
  return false;
}

bool        Server::Room_full(Room Room_check)
{
  if (Room_check.Size_Of_Room() < 4)
    return true;
  return false;
}

bool        Server::All_Room_Full()
{
  if (RoomList.size() == 0)
    return (false);
  for (std::list<Room>::iterator it = RoomList.begin(); it != RoomList.end(); it++)
  {
    if ((*it).Size_Of_Room() < 4)
      return true;
  }
  return false;
}

void        Server::Treatment_Message(udp::endpoint sender)
{
    if (!Player_exist(sender))
        {
          Player player(sender);
          player.SetName(data_);
          if (!All_Room_Full())
          {
            Room room;
            room.SetNbrRoom(RoomList.size() + 1);
            room.Add_Player(player);
            RoomList.push_back(room);
            const char * send = "Welcome to you " + lol;
            Send_Message(send, sender);
            lol += 1;
          }
          else
          {
            const char * tien = "In Room " + lol;
            Repartition_in_Room(player);
            Send_Message(tien, sender);
            lol += 1;
          }
        }
    /*else
    {

    ///la il faudra evoyer les information au thread
  }

    */
}

void        Server::Receive_Message()
{
  socket_.async_receive_from(
      boost::asio::buffer(data_, max_length), sender_endpoint_,
      [this](boost::system::error_code ec, std::size_t bytes_recvd)
      {
        if (!ec && bytes_recvd > 0)
        {
          MessagePacket a;
          std::cout.write(data_, std::strlen(data_));
          std::cout << "\n";

          a.buildObjectFromJSON(std::string(data_).substr(3));
          std::cout << a << std::endl;
        /*  users.push_back(sender_endpoint_);
          if (users.size() == 2)
          {
            for(std::list<udp::endpoint>::iterator it = users.begin(); it != users.end(); it++)
            {
              Send_Message(*it);
            }
          }*/
          Treatment_Message(sender_endpoint_);
          //Send_Message(bytes_recvd);
        }
        else
        {
          Receive_Message();
        }
      });
}

void          Server::Send_Message(const char* msg, udp::endpoint send)
{
  socket_.async_send_to(
      boost::asio::buffer(msg, std::strlen(msg)), send,
      [this](boost::system::error_code /*ec*/, std::size_t /*bytes_sent*/)
      {
        Receive_Message();
      });
}

void          Server::Send_Message(udp::endpoint end)
{
  socket_.async_send_to(
      boost::asio::buffer("la\n", 3), end,
      [this](boost::system::error_code /*ec*/, std::size_t /*bytes_sent*/)
      {
        Receive_Message();
      });
}

void          Server::Send_Message(std::size_t length)
{
  socket_.async_send_to(
      boost::asio::buffer(data_, length), sender_endpoint_,
      [this](boost::system::error_code /*ec*/, std::size_t /*bytes_sent*/)
      {
        Receive_Message();
      });
}
