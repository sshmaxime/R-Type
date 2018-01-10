//
// Created by sshsupreme on 10/01/18.
//

#ifndef R_TYPE_CMDINGAME_H
#define R_TYPE_CMDINGAME_H

#include "Request.h"

class CmdInGame : public JSONObject{
public:
    CmdInGame();
    ~CmdInGame();

private:
    std::string                     _Username = NULL;
    std::string                     _Command = NULL;
    std::string                     _CommandContent = NULL;

public:
    int                             buildObjectFromJSON(const std::string&);
    std::string                     buildJSONFromObject();
};


#endif //R_TYPE_CMDINGAME_H
