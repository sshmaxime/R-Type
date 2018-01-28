//
// Created by sshsupreme on 17/01/18.
//

#include <iostream>
#include <MessagePacket.h>
#include <CmdInGamePacket.h>
#include "CNetwork.h"
#include "../Global/CGlobal.h"

int                     CNetwork::Receive()
{
  try {
      _Socket->async_receive_from(
	      boost::asio::buffer(_DATA, max_length), _SenderEndpoint,
	      boost::bind(&CNetwork::handleReceive, this,
			  boost::asio::placeholders::error,
			  boost::asio::placeholders::bytes_transferred));
    } catch (const std::exception& ex) {
      std::cout << ex.what() << std::endl;
    }
  return (0);
}

int                     CNetwork::Initialize(const std::string &ip, int port)
{
  try {
      _Service = new boost::asio::io_service();
      CGlobal::Instance()->_Service = _Service;

      _Socket = new udp::socket(*this->_Service);
      _Socket->open(udp::v4());
      CGlobal::Instance()->_Socket = _Socket;

      _Endpoint = udp::endpoint(boost::asio::ip::address_v4::from_string(ip.c_str()), port);
      this->Receive();
    } catch (std::exception &exception) {
      std::cout << exception.what() << std::endl;
      return (-1);
    }
  return 0;
}

int                     CNetwork::Run()
{
  try {
      _Service->run();
    } catch (std::exception &exception) {
      std::cout << exception.what() << std::endl;
      return (-1);
    }
  return (0);
}

void                    CNetwork::handleReceive(const boost::system::error_code &error, size_t bytes)
{
  if (CGlobal::Instance()->quit)
    {
      _Socket->close();
      return;
    }
  _DATA[bytes] = '\0';

  std::string msg = std::string(_DATA.c_array());
  this->_game.addEvent(msg);
  this->Receive();
}

int                     CNetwork::Send(JSONObject *toSend)
{
  std::string         JSONtoString = toSend->getHEADER() + toSend->getJSON();

  if (CGlobal::Instance()->quit)
    return (-1);
  try {
      _Socket->send_to(boost::asio::buffer(JSONtoString), _Endpoint);
    } catch (std::exception& exception) {
      this->ClearNetwork();
      std::cout << exception.what() << std::endl;
    }
  return (0);
}

int                     CNetwork::ClearNetwork()
{
  this->_Service->stop();
  return (0);
}

int                     CNetwork::Bye()
{
  try {
      _Socket->send_to(boost::asio::buffer("bye"), _Endpoint);
    } catch (std::exception& exception) {
      std::cout << exception.what() << std::endl;
    }
  return (0);
}


CNetwork::~CNetwork()
{
  this->Bye();
  delete _Socket;
}

void CNetwork::set_game(const Core &_game)
{
  CNetwork::_game = _game;
}