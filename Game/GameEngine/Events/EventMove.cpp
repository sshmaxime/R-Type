//
// Created by chauvin on 28/01/18.
//

#include "EventMove.hpp"
#include "../Rigidbody/Rigidbody.hpp"
#include "../Input/Input.h"

TacosEngine::EventMove::EventMove(const std::shared_ptr<TacosEngine::GameObject> &obj, const Vector2 &dir)
{
  this->_object = obj;
  this->_dir = dir;
}

void TacosEngine::EventMove::onEvent()
{
  auto rb = _object->getComponent<Rigidbody>();

  _object->getTransform().setDirection(_dir);
  _object->getTransform().setSpeed(2.5);
  rb->addForce(_dir * _object->getTransform().getSpeed());
  _object->getScene();
}
