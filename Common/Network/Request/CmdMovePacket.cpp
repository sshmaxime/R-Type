//
// Created by sshsupreme on 14/01/18.
//

#include "CmdMovePacket.h"

int                     CmdMovePacket::buildObjectFromJSON(const std::string& JSONString)
{
    try {
        _JSON = JSON::parse(JSONString);

        this->_Username = _JSON.at("username");
	this->_sprite = _JSON.at("sprite");
	this->_x = _JSON.at("x");
	this->_y = _JSON.at("y");
    } catch (std::exception &exception) {
        std::cout << "Error Parsing CmdLobbyPacket" << std::endl;
        return (-1);
    }
    return (0);
}

void                    CmdMovePacket::setUsername(const std::string& newUsername)
{
    this->_Username = newUsername;
    _JSON["username"] = this->_Username;
}


const std::string &CmdMovePacket::get_sprite() const
{
  return _sprite;
}

void CmdMovePacket::set_sprite(const std::string &_sprite)
{
  CmdMovePacket::_sprite = _sprite;
    _JSON["sprite"] = this->_sprite;
}

const std::string &CmdMovePacket::get_x() const
{
  return _x;
}

void CmdMovePacket::set_x(const std::string &_x)
{
  CmdMovePacket::_x = _x;
    _JSON["x"] = this->_x;
}

const std::string &CmdMovePacket::get_y() const
{
  return _y;
}

void CmdMovePacket::set_y(const std::string &_y)
{
  CmdMovePacket::_y = _y;
    _JSON["y"] = this->_y;
}

const std::string &CmdMovePacket::getUsername() const
{
  return _Username;
}
