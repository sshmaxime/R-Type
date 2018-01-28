//
// Created by chauvin on 26/01/18.
//

#include "PlayerBehaviour.hpp"
#include "BulletBehaviour.hpp"
#include "../GameEngine/Rigidbody/Rigidbody.hpp"
#include "../GameEngine/Collider/Collider.hpp"

namespace TacosEngine
{
  void PlayerBehaviour::update(const Input &input)
  {
    Vector2 dir(input.getAxis("Horizontal"), input.getAxis("Vertical"));
    auto rb = getComponent<Rigidbody>();

    if (input.getAxis("Horizontal") != 0 && input.getAxis("Vertical") != 0)
      dir = dir / 2;
      CheckWindowCollide(dir);
      _object->getTransform().setDirection(dir);
    _object->getTransform().setSpeed(2.5);
    rb->addForce(dir * _object->getTransform().getSpeed());
    if (dir.get_y() != 0 || dir.get_x() != 0)
      _lastdir = dir * _object->getTransform().getSpeed() * 1.5;

    _object->getScene();
    if (input.getKey(Key::KEY_SPACE) && !isShooting)
      {
	shoot();
      }
    isShooting = input.getKey(Key::KEY_SPACE);
    if (_health <= 0) {
        //animation de mort
        this->setDestroy(true);
    }
  }

  void PlayerBehaviour::shoot()
  {
    auto bullet = std::make_shared<Sprite>("bulletPlayer" + this->getGameObjectName(), this->_object->getScene(),
					   Layout::SCENE);
    if (this->_bulletType == 1) {
        bullet->setTexture(_object->getScene()->getTexture("laser1"));
        bullet->setSize(Vector2(10, 10));
    }
    else {
        bullet->setTexture(_object->getScene()->getTexture("laser"));
        bullet->setSize(Vector2(16, 16));
    }
    bullet->getTransform().setPosition(_object->getTransform().getPosition() + Vector2(42, 0));
    bullet->getTransform().setSpeed(_object->getTransform().getSpeed());
    auto col = std::make_shared<Collider>("Collider" + bullet->getInstanceName(), bullet, bullet->getSize(),
					  bullet->getTransform().getPosition(), true);
    auto rbody = std::make_shared<Rigidbody>("Rigidbody" + bullet->getInstanceName(), bullet);
    auto beha = std::make_shared<BulletBehaviour>("bulletbeha" + bullet->getInstanceName(), bullet, Vector2(1, 0));
    this->_object->getScene()->addGameObject(bullet);
    this->_object->getScene()->addComponent(col);
    this->_object->getScene()->addComponent(rbody);
    this->_object->getScene()->addComponent(beha);
  }
}