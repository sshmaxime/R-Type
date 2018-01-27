//
// Created by chauvin on 26/01/18.
//


#include "BackgroundBehaviour.hpp"
#include "../GameEngine/Rigidbody/Rigidbody.hpp"

namespace TacosEngine
{

  void BackgroundBehaviour::Start()
  {
    this->_object->getTransform().setSpeed(1);
    auto rb = this->_object->getComponent<Rigidbody>();
    rb->addForce(Vector2(-1, 0) * _object->getTransform().getSpeed());

    this->_background2 = std::make_shared<Sprite>("background2" + this->getGameObjectName(), this->_object->getScene(),
						  Layout::BACKGROUND);
    _background2->setTexture(this->_object->getScene()->getTexture("back"));
    _background2->setSize(Vector2(800, 400));
    _background2->getTransform().setSpeed(1);
    _background2->getTransform().setPosition(Vector2(1600, 0));
    auto rbody = std::make_shared<Rigidbody>("Rigidbody" + _background2->getInstanceName(), _background2);
    rbody->addForce(Vector2(-1, 0) * _background2->getTransform().getSpeed());
    this->_object->getScene()->addGameObject(_background2);
    this->_object->getScene()->addComponent(rbody);
  }

  void BackgroundBehaviour::update(const Input &)
  {
    if (this->_object->getTransform().getPosition().get_x() < 0)
      {
	this->_background2->getTransform().setPosition(
		Vector2(this->_object->getTransform().getPosition().get_x() + 800, 0));
      }
    if (this->_background2->getTransform().getPosition().get_x() < 0)
      this->_object->getTransform().setPosition(
	      Vector2(this->_background2->getTransform().getPosition().get_x() + 800, 0));
  }

  void BackgroundBehaviour::onCollide(GameObject &other)
  {

  }
}