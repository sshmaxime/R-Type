//
// Created by sshsupreme on 07/02/18.
//

#ifndef R_TYPE_CMDSTARTGAME_H
#define R_TYPE_CMDSTARTGAME_H


#include "Request.h"

class CmdStartGame : public JSONObject{
public:
    CmdStartGame()                 {__HEADER__ = "01x01";}
    ~CmdStartGame()                = default;

public:
    int                             buildObjectFromJSON(const std::string&) override;
};





#endif //R_TYPE_CMDSTARTGAME_H
