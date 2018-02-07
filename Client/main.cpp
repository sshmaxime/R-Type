#include "Client.h"
#include "Global/CGlobal.h"

void                exitSignal(int)
{
    CGlobal::Instance()->quit = true;
    CGlobal::Instance()->_Service->stop();
}

void                signalsHandler()
{
#ifndef WIN32
    struct sigaction sa{};
    memset( &sa, 0, sizeof(sa) );
    sa.sa_handler = exitSignal;
    sigfillset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);
#endif
}


int                 main(int ac, char **av)
{
    signalsHandler();
    if (ac < 3)
        return (-1);

    Client          myClient;
    if (myClient.Initialize("127.0.0.1", std::atoi(av[1]), av[2]) == -1)
        return (-1);
    if (ac > 3)
    {
        if (std::string(av[3]) == "true")
            myClient._isOnline =    true;
    }
    myClient.Run();
    return (0);
}
