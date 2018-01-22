#include "Server.h"
#include "Global/Global.h"

void                exitSignal(int)
{
    Global::Instance().quit = true;
    if (Global::Instance()._Socket != NULL)
        Global::Instance()._Socket->cancel();
}

void                signalsHandler()
{
    struct sigaction sa;
    memset( &sa, 0, sizeof(sa) );
    sa.sa_handler = exitSignal;
    sigfillset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);
}

int                 main(int ac, char* av[])
{
    Server            myServer;

    signalsHandler();

    if (myServer.Initialize(av, ac) == -1)
        return (-1);
    myServer.Run();

    return 0;
}
