#include "User.hpp"


User::User(boost::asio::io_service& io_service, char *host , char *port)
  :socket_(io_service, udp::endpoint(udp::v4(), 0))
  {
    udp::resolver resolver(io_service);
    endpoint = *resolver.resolve({udp::v4(), host, port});
    std::memset(message, 0, sizeof message);
  }

void      User::Send_Message_Login()
{
  WelcomePacket a;

  std::cout << "Enter Your Login: ";
  std::memset(message, 0, sizeof message);
  std::cin.getline(message, max_length);
  a.setUsername(message);
  SetName(message);
  std::string JSON_ToSend = a.getHEADER() + a.getJSON();
  size_t message_size = std::strlen(JSON_ToSend.c_str());
  socket_.send_to(boost::asio::buffer(JSON_ToSend.c_str(), message_size), endpoint);
}

void      User::SetName(std::string Pseudo)
{
  Name = Pseudo;
}

std::string      User::GetName()
{
  return Name;
}

void      User::Send_Message()
{
  MessagePacket a;

  std::cout << "Enter Message: ";
  std::memset(message, 0, sizeof message);
  std::cin.getline(message, max_length);
  a.setUsername(Name);
  a.setMessage(message);
  std::string JSON_ToSend = a.getHEADER() + a.getJSON();
  size_t message_size = std::strlen(JSON_ToSend.c_str());
  socket_.send_to(boost::asio::buffer(JSON_ToSend.c_str(), message_size), endpoint);
}

void      User::Receive_Message()
{
  size_t response_size = socket_.receive_from(
      boost::asio::buffer(response, max_length), sender_endpoint);
  std::cout << "Reply is: ";
  std::cout.write(response, response_size);
  std::cout << "\n";
}
