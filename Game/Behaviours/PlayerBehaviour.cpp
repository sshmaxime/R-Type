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

    CheckWindowCollide(dir);
    _object->getTransform().setDirection(dir);
    _object->getTransform().setSpeed(2.5);
    rb->addForce(dir * _object->getTransform().getSpeed());

    if (input.getAxis("Horizontal")  != 0 || input.getAxis("Vertical") != 0)
      {
	auto *a = new CmdMovePacket;
	a->set_sprite(_object->getInstanceName());
	a->setUsername(_object->getInstanceName());
	std::ostringstream ss;
	ss << dir.get_x();
	std::cout << "X send " + ss.str() << std::endl;
	a->set_x(ss.str());
	std::ostringstream s2;
	s2 << dir.get_y();
	std::cout << "Y send " + s2.str() << std::endl;
	a->set_y(s2.str());
	//while (!CGlobal::Instance()->_mutexSend.try_lock());
	CGlobal::Instance()->_mutexSend.lock();
	this->_object->getScene()->get_send()->emplace(a);
	CGlobal::Instance()->_mutexSend.unlock();
      }
    if (input.getKey(Key::KEY_SPACE) && !isShooting)
      {
	shoot();
	auto *b = new CmdShotPacket;
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

  void PlayerBehaviour::onCollide(GameObject &other)
  {
    if (other.getInstanceName().find("bullet") != std::string::npos &&
	other.getInstanceName().find(getInstanceName()) == std::string::npos)
      {
	std::cout << "Oui" << std::endl;
	std::cout << _health << std::endl;
	this->_health = this->_health - other.getComponent<BulletBehaviour>()->get_damages();
      }
    else if (other.getInstanceName().find("Obs") != std::string::npos &&
	     other.getInstanceName().find(getInstanceName()) == std::string::npos)
	{
	  this->_health = this->_health - other.getComponent<ObstacleBehaviour>()->get_damages();
	}
      else if (other.getInstanceName().find("ammo") != std::string::npos &&
		   other.getInstanceName().find(getInstanceName()) == std::string::npos)
	  {
	    this->_damages = this->_damages * 2;
	    this->_bulletType = 2;
	    other.setActive(false);
	  }
    if (this->_health <= 0)
      {
	auto explosion = std::make_shared<Sprite>("explosion", this->_object->getScene(),
						  Layout::SCENE);

	std::vector<ITexture*>      explosionFrames;
	explosionFrames.push_back(_object->getScene()->getTexture("explosion1"));
	explosionFrames.push_back(_object->getScene()->getTexture("explosion2"));
	explosionFrames.push_back(_object->getScene()->getTexture("explosion3"));

	explosion->setTexture(_object->getScene()->getTexture("explosion1"));
	explosion->setSize(Vector2(40, 40));
	explosion->getTransform().setPosition(_object->getTransform().getPosition());
	explosion->getTransform().setSpeed(0.0);
	explosion->setActive(true);
	std::shared_ptr<Animation>       explosionAnim =
		std::make_shared<Animation>("explosionAnim", explosion,
					    false, 20, explosionFrames);
	auto beha = std::make_shared<AnimationBehaviour>("endAnim", explosion);


	this->_object->getScene()->addGameObject(explosion);
	this->_object->getScene()->addComponent(explosionAnim);
	this->_object->getScene()->addComponent(beha);
      }
  }
}