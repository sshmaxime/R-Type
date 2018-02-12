//
// Created by chauvin on 12/02/18.
//

#include "CmdAddPlayerPacket.hpp"

CmdAddPlayerPacket::CmdAddPlayerPacket()
{
  __HEADER__ = "1x3";
}

const std::string &CmdAddPlayerPacket::get_Username() const
{
  return _Username;
}

void CmdAddPlayerPacket::set_Username(const std::string &_Username)
{
  this->_Username = _Username;
  _JSON["username"] = this->_Username;
}

const std::string &CmdAddPlayerPacket::get_Number() const
{
  return _Number;
}

void CmdAddPlayerPacket::set_Number(const std::string &_Number)
{
  this->_Number = _Number;
  _JSON["number"] = this->_Number;
}

const std::string &CmdAddPlayerPacket::get_Active() const
{
  return _Active;
}

void CmdAddPlayerPacket::set_Active(const std::string &_Active)
{
  CmdAddPlayerPacket::_Active = _Active;
  _JSON["active"] = this->_Active;
}

int CmdAddPlayerPacket::buildObjectFromJSON(const std::string &JSONString)
{
  try
    {
      _JSON = JSON::parse(JSONString);

      this->_Username = _JSON.at("username");
      this->_Number = _JSON.at("number");
      this->_Active = _JSON.at("active");
    } catch (std::exception &exception)
    {
      std::cout << "Error Parsing CmdLobbyPacket" << std::endl;
      return (-1);
    }
  return (0);
}
