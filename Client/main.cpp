#include "Client.h"

using boost::asio::ip::udp;

int                 main()
{
    Client          myClient;

    myClient.Initialize("127.0.0.1", 9999);
    myClient.Run();
    myClient.Delete();

    return (0);
}
