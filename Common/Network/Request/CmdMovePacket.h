//
// Created by sshsupreme on 14/01/18.
//

#ifndef R_TYPE_CMDMOVEPACKET_H
#define R_TYPE_CMDMOVEPACKET_H

#include "Request.h"

class CmdMovePacket : public JSONObject{
 public:
  CmdMovePacket()                 {__HEADER__ = "1x1";}
  ~CmdMovePacket()                = default;

 private:
  std::string		_Username;
  std::string           _sprite;
  std::string		_x;
  std::string		_y;

 public:
  int		buildObjectFromJSON(const std::string&) override;
  void          setUsername(const std::string&);

  const std::string &getUsername() const;

  const std::string &get_sprite() const;
  void set_sprite(const std::string &_sprite);
  const std::string &get_x() const;
  void set_x(const std::string &_x);
  const std::string &get_y() const;
  void set_y(const std::string &_y);
};



#endif //R_TYPE_CMDMOVEPACKET_H
