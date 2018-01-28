//
// Created by chauvin on 26/01/18.
//


#include "BulletBehaviour.hpp"
#include "../GameEngine/Scene/Scene.hpp"
#include "../GameEngine/Behaviour/Behaviour.h"
#include "../GameEngine/Rigidbody/Rigidbody.hpp"

TacosEngine::BulletBehaviour::BulletBehaviour(const std::string &name,
					      const std::shared_ptr<TacosEngine::GameObject> &object, Vector2 dir)
	: Behaviour(name,
		    object)
{ _dir = dir;
    _damages = 10;}

void TacosEngine::BulletBehaviour::Start()
{
  auto rb = this->getComponent<Rigidbody>();
  rb->addForce(_dir * this->_object->getTransform().getSpeed());
}

void TacosEngine::BulletBehaviour::onCollide(GameObject &other)
{
    if ((other.getInstanceName().find("bullet") != std::string::npos ||
            other.getInstanceName().find("Monster") != std::string::npos) &&
        other.getInstanceName().find(getInstanceName()) == std::string::npos)
    {
        return;
    }
    setDestroy(true);
}

void TacosEngine::BulletBehaviour::update(const TacosEngine::Input &input)
{
  auto pos = _object->getTransform().getPosition();
  if (pos.get_x() < 0 || pos.get_y() < 0 ||
      pos.get_x() > 800 || pos.get_y() > 400)
    {
      setDestroy(true);
    }
}

int TacosEngine::BulletBehaviour::get_damages() const {
    return _damages;
}

void TacosEngine::BulletBehaviour::set_damages(int _damages) {
    BulletBehaviour::_damages = _damages;
}
