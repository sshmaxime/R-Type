//
// Created by chauvin on 28/01/18.
//

#include "EventShoot.hpp"
#include "../GameEngine/Sprite/Sprite.hpp"
#include "../GameEngine/Collider/Collider.hpp"
#include "../GameEngine/Rigidbody/Rigidbody.hpp"
#include "../Behaviours/BulletBehaviour.hpp"

TacosEngine::EventShoot::EventShoot(const std::shared_ptr<TacosEngine::GameObject> &obj)
{
  _object = obj;
}

void TacosEngine::EventShoot::onEvent()
{
  auto bullet = std::make_shared<Sprite>("bullet" + this->_object->getInstanceName(), this->_object->getScene(),
					 Layout::SCENE);
  bullet->setTexture(_object->getScene()->getTexture("bullet"));
  bullet->setSize(Vector2(20, 20));
  bullet->getTransform().setPosition(_object->getTransform().getPosition() + Vector2(42, 0));
  bullet->getTransform().setSpeed(2);
  auto col = std::make_shared<Collider>("Collider" + bullet->getInstanceName(), bullet, bullet->getSize(),
					bullet->getTransform().getPosition(), true);
  auto rbody = std::make_shared<Rigidbody>("Rigidbody" + bullet->getInstanceName(), bullet);
  auto beha = std::make_shared<BulletBehaviour>("bulletbeha" + bullet->getInstanceName(), bullet, Vector2(1, 0));
  this->_object->getScene()->addGameObject(bullet);
  this->_object->getScene()->addComponent(col);
  this->_object->getScene()->addComponent(rbody);
  this->_object->getScene()->addComponent(beha);
}
