cmake_minimum_required(VERSION 3.9)
project(R_Type)

include_directories("Network/Request")

set(CMAKE_CXX_STANDARD 11)

add_executable(R_Type
        main.cpp
        json.hpp Network/Request/WelcomePacket.cpp Network/Request/WelcomePacket.h Network/JSONObject.h Network/Request/Request.h Network/Request/MessagePacket.cpp Network/Request/MessagePacket.h Network/Request/CmdLobbyPacket.cpp Network/Request/CmdLobbyPacket.h Network/Request/CmdInGamePacket.cpp Network/Request/CmdInGamePacket.h Network/JSONObject.cpp Network/Request/CmdMovePacket.cpp Network/Request/CmdMovePacket.h Network/Request/CmdShotPacket.cpp Network/Request/CmdShotPacket.h)

