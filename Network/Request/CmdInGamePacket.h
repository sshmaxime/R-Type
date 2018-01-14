//
// Created by sshsupreme on 10/01/18.
//

#ifndef R_TYPE_CMDINGAME_H
#define R_TYPE_CMDINGAME_H

#include "Request.h"

class CmdInGamePacket : public JSONObject{
public:
    CmdInGamePacket()               {__HEADER__ = "1x0";}
    ~CmdInGamePacket()              {}

private:
    std::string                     _Username;
    std::string                     _Command;
    std::string                     _CommandContent;

public:
    int                             buildObjectFromJSON(const std::string&);
    std::string                     getJSON();

public:
    void                            setCommand(const std::string&);
    void                            setCmmandContent(const std::string&);
    void                            setUsername(const std::string&);
};


#endif //R_TYPE_CMDINGAME_H
