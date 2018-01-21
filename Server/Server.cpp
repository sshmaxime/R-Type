//
// Created by sshsupreme on 20/01/18.
//

#include "Server.h"

void                Help()
{
    std::cout << "./Server <ip> <port>" << std::endl;
}

bool                isCommandLineValid(char *av[], int ac)
{
    return (true);
}

int                 Server::Initialize(char *av[], int ac)
{
    if (!isCommandLineValid(av, ac))
    {
        Help();
        return (-1);
    }

    _Network.Initialize(8888);

    return 0;
}

int                 Server::Run()
{
    // Do whatever we want to
    return 0;
}

Server::~Server()
{

}
