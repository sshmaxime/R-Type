//
// Created by sshsupreme on 17/01/18.
//

#include <HelloPacket.h>
#include "Client.h"
#include "Global/CGlobal.h"
#include "../Server/Global/Global.h"

int                 Client::Initialize(const std::string& ip, int port)
{
  if (_Network.Initialize(ip, port) == -1)
    return (-1);
  return 0;
}

int                 Client::Run()
{
  // Do whatever we want to

  HelloPacket   *a = new HelloPacket;

  a->setUsername("rozita");
  _Network.Send(a);
  _GameThread = std::thread(&Client::LaunchGame, this);
  _sendThread = std::thread(&Client::sendListener, this);
  _Network.Run();
  this->_GameThread.join();
  return 0;
}

int                 Client::LaunchGame()
{
  this->_Game.Init(true);
  this->_Network.set_game(this->_Game);
  this->_Game.get_engine()->run();
  this->Delete();
}

void 		Client::sendListener()
{
  while(!CGlobal::Instance()->quit)
    {
      while (!CGlobal::Instance()->_mutexSend.try_lock());
      while (!this->_Game.get_engine()->getSceneInProcess()->get_send()->empty())
	{
	  auto i = _Game.get_engine()->getSceneInProcess()->get_send()->front();
	  this->_Network.Send(i);
	  _Game.get_engine()->getSceneInProcess()->get_send()->pop();
	}
      CGlobal::Instance()->_mutexSend.unlock();
    }
}

int                 Client::Delete()
{
  CGlobal::Instance()->quit = true;
  CGlobal::Instance()->_Service->stop();
  return 0;
}
