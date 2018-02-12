//
// Created by chauvin on 12/02/18.
//

#ifndef R_TYPE_CMDADDPLAYER_HPP
#define R_TYPE_CMDADDPLAYER_HPP


#include "../../JSON/JSONObject.h"

class CmdAddPlayerPacket : public JSONObject
{
 public:
  CmdAddPlayerPacket();

  ~CmdAddPlayerPacket() = default;

 private:
  std::string _Username;
  std::string _Number;
  std::string _Active;

 public:
  int buildObjectFromJSON(const std::string &) override;

  const std::string &get_Username() const;

  void set_Username(const std::string &_Username);

  const std::string &get_Number() const;

  void set_Number(const std::string &_Number);

  const std::string &get_Active() const;

  void set_Active(const std::string &_Active);
};


#endif //R_TYPE_CMDADDPLAYER_HPP
