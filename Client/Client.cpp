//
// Created by sshsupreme on 17/01/18.
//

#include <HelloPacket.h>
#include "Client.h"
#include "Global/CGlobal.h"

int                 Client::Initialize(const std::string& ip, int port)
{
  if (_Network.Initialize(ip, port) == -1)
    return (-1);
  return 0;
}

int                 Client::Run()
{
  // Do whatever we want to

  auto *a = new HelloPacket;

  a->setUsername("player2");
  _Network.Send(a);
  _GameThread = std::thread(&Client::LaunchGame, this);
  _sendThread = std::thread(&Client::sendListener, this);
  _Network.Run();
  this->_GameThread.join();
  this->_sendThread.join();
  return 0;
}

int                 Client::LaunchGame()
{
  this->_Game.Init(true);
  CGlobal::Instance()->_init = true;
  this->_Network.set_game(this->_Game);
  this->_Game.get_engine()->run();
  this->Delete();
}

void 		Client::sendListener()
{
  while(!CGlobal::Instance()->quit)
    {
      if (CGlobal::Instance()->_init)
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
}

int                 Client::Delete()
{
  CGlobal::Instance()->quit = true;
  CGlobal::Instance()->_Service->stop();
  return 0;
}
