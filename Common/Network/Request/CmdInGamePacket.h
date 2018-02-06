//
// Created by sshsupreme on 10/01/18.
//

#ifndef R_TYPE_CMDINGAME_H
#define R_TYPE_CMDINGAME_H

#include "Request.h"

class CmdInGamePacket : public JSONObject{
public:
    CmdInGamePacket()               {__HEADER__ = "1x0";}
    ~CmdInGamePacket()              = default;

private:
    std::string                     _Username;
    std::string                     _Command;
    std::string                     _CommandContent;

public:
    int                             buildObjectFromJSON(const std::string&) override;

public:
    void                            setUsername(const std::string&);
    void                            setCommand(const std::string&);
    void                            setCommandContent(const std::string&);

public:
    const std::string &getUsername() const;

    const std::string &getCommand() const;

    const std::string &getCommandContent() const;
};


#endif //R_TYPE_CMDINGAME_H
