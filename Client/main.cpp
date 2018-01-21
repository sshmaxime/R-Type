#include "Client.h"

void                exitSignal(int)
{
    //Set
}

void                signalsHandler()
{
    struct sigaction sa;
    memset( &sa, 0, sizeof(sa) );
    sa.sa_handler = exitSignal;
    sigfillset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);

    //set
}

int                 main()
{
    Client          myClient;

    signalsHandler();

    if (myClient.Initialize("127.0.0.1", 8888) == -1)
        return (-1);
    myClient.Run();

    return (0);
}
