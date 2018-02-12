//
// Created by chauvin on 28/01/18.
//

#include <iostream>
#include "EventMove.hpp"
#include "../GameEngine/Rigidbody/Rigidbody.hpp"

TacosEngine::EventMove::EventMove(const std::shared_ptr<TacosEngine::GameObject> &obj, const Vector2 &dir)
{
  this->_object = obj;
  this->_dir = dir;
  std::cout << "X :" << dir.get_x() << "Y :" << dir.get_y() << std::endl;
}

void TacosEngine::EventMove::onEvent()
{

  std::cout << "MOVE" << std::endl;

  auto rb = this->_object->getComponent<Rigidbody>();
  CheckWindowCollide(_dir);
  _object->getTransform().setDirection(_dir);
  _object->getTransform().setSpeed(2.5);
  rb->addForce(_dir * _object->getTransform().getSpeed());
}

TacosEngine::Vector2 &TacosEngine::EventMove::CheckWindowCollide(TacosEngine::Vector2 &dir)
{
  if (dir.get_x() < 0 && _object->getTransform().getPosition().get_x() <= 0.5 ||
      dir.get_x() > 0 && _object->getTransform().getPosition().get_x() >= (799.5 - _object->getScene()->getWindowSize().get_x()))
    dir.set_x(0);
  if (dir.get_y() > 0 && _object->getTransform().getPosition().get_y() >= (399.5 - _object->getScene()->getWindowSize().get_y()) ||
      dir.get_y() < 0 && _object->getTransform().getPosition().get_y() <= 0.5)
    dir.set_y(0);
  return dir;
}