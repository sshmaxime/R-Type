#include "WelcomePacket.h"
#include "MessagePacket.h"
#include "CmdInGamePacket.h"
#include "CmdLobbyPacket.h"

#include <iostream>

int main()
{
    WelcomePacket packet;
    packet.setUsername("maxime");
    packet.BeautifulPrint();
    std::cout << packet.getJSON() << std::endl;

    MessagePacket packet1;
    packet1.setUsername("maxime");
    packet1.setMessage("salut c'est moua");
    packet1.BeautifulPrint();

    CmdInGamePacket packet2;
    packet2.setUsername("maxime");
    packet2.setCmmandContent("no lo se");
    packet2.setCommand("jump");
    packet2.BeautifulPrint();

    CmdLobbyPacket packet3;
    packet3.setCommand("ready");
    packet3.setUsername("maxime");
    packet3.BeautifulPrint();

    return (0);
}