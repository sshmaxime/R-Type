//
// Created by chauvin on 26/01/18.
//

#include "CmdMovePacket.h"
#include "CmdShotPacket.h"
#include "PlayerBehaviour.hpp"
#include "BulletBehaviour.hpp"
#include "../GameEngine/Rigidbody/Rigidbody.hpp"
#include "../GameEngine/Collider/Collider.hpp"
#include "../../Client/Global/CGlobal.h"

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

    /*CmdMovePacket *a = new CmdMovePacket;
    a->set_sprite(_object->getInstanceName());
    a->setUsername(_object->getInstanceName());
    std::ostringstream ss;
    ss << _object->getTransform().getPosition().get_x();
    a->set_x(ss.str());
    ss.clear();
    ss << _object->getTransform().getPosition().get_y();
    a->set_y(ss.str());
    while (!CGlobal::Instance()->_mutexSend.try_lock());
    this->_object->getScene()->get_send()->emplace(a);
    CGlobal::Instance()->_mutexSend.unlock();*/

    _object->getScene();
    if (input.getKey(Key::KEY_SPACE) && !isShooting)
      {
	shoot();
	CmdShotPacket *b = new CmdShotPacket;
	b->setUsername(this->_object->getInstanceName());
	while (!CGlobal::Instance()->_mutexSend.try_lock());
	this->_object->getScene()->get_send()->emplace(b);
	CGlobal::Instance()->_mutexSend.unlock();
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