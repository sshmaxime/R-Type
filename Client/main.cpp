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
    struct sigaction sa;
    memset( &sa, 0, sizeof(sa) );
    sa.sa_handler = exitSignal;
    sigfillset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);
#endif
}


int                 main()
{
    Client          myClient;

    signalsHandler();

    if (myClient.Initialize("127.0.0.1", 8887) == -1)
        return (-1);
    myClient.Run();

    return (0);
}
