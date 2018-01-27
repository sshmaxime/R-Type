//
// Created by chauvin on 26/01/18.
//

#include <GameEngine/Scene/Scene.hpp>
#include <GameEngine/Behaviour/Behaviour.h>
#include "ObstacleObserver.hpp"

namespace TacosEngine
{
  ObstacleObserver::ObstacleObserver(const std::string &name,
				     const std::shared_ptr<TacosEngine::GameObject> &object) : Behaviour(
	  name, object)
  {}

  void ObstacleObserver::Start()
  {

  }

  void ObstacleObserver::update(const Input &)
  {

  }

  void ObstacleObserver::onCollide(GameObject &other)
  {
    setDestroy(true);
  }

}