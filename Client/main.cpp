#include "User.hpp"

using boost::asio::ip::udp;

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 3)
    {
      std::cerr << "Usage: blocking_udp_echo_client <host> <port>\n";
      return 1;
    }

    boost::asio::io_service io_service;
		User	user(io_service, argv[1], argv[2]);

		user.Send_Message_Login();
		user.Receive_Message();
		while (1)
		{
			user.Send_Message();
			user.Receive_Message();
		}
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
  }
  return 0;
}
