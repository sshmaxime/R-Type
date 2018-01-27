//
// Created by chauvin on 27/01/18.
//

#include <GameEngine/Rigidbody/Rigidbody.hpp>
#include "ObstacleBehaviour.hpp"

namespace TacosEngine
{
  TacosEngine::ObstacleBehaviour::ObstacleBehaviour(const std::string &name,
						    const std::shared_ptr<TacosEngine::GameObject> &object, Vector2 dir)
	  : Behaviour(
	  name, object)
  {

    _dir = dir / 2;
  }

  void TacosEngine::ObstacleBehaviour::Start()
  {
    auto rb = getComponent<Rigidbody>();
    rb->addForce(_dir);
  }

  void TacosEngine::ObstacleBehaviour::update(const TacosEngine::Input &)
  {
    auto rb = getComponent<Rigidbody>();
    rb->addForce(_dir + Vector2(0, this->get_random()));
    auto pos = _object->getTransform().getPosition();
    if (pos.get_x() < 0)
      setDestroy(true);
  }

  void ObstacleBehaviour::onCollide(GameObject &other)
  {
    std::cout << "DESTROY" << std::endl;
    this->setDestroy(true);
  }
}
