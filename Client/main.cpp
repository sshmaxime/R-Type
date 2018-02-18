#include "Client.h"
#include "Global/CGlobal.h"
#include <arpa/inet.h>

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

int                help()
{
    std::cout << "SoloPlayer Usage :" << std::endl;
    std::cout << "./client 'username'" << std::endl;
    std::cout << "MultiPlayer Usage :" << std::endl;
    std::cout << "./client 'username' ['ip' 'port']" << std::endl;

    return (-1);
}

int                 main(int ac, char **av)
{
    signalsHandler();
    if ((ac > 2 && ac != 4) || ac == 1)
        return (help());
    Client          myClient;

    std::cout << av[1] << std::endl;
    if (ac == 2) {
        std::cout << "SOLO mode" << std::endl;
        myClient.Initialize(std::string(), 0, std::string(av[1]), false);
    }

    else if (myClient.Initialize("127.0.0.1", std::atoi(av[1]), av[2], true) == -1)
        return (-1);

    myClient.Run();
    return (0);
}
