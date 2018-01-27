//
// Created by simon on 26/01/18.
//

#include "MonsterBehaviour.h"
#include "BulletBehaviour.hpp"
#include "MonsterIA.h"
namespace TacosEngine
{
    void MonsterBehaviour::update(const Input &)
    {
        ++can_shoot;
        auto pos = _object->getTransform().getPosition();
        auto rb = getComponent<Rigidbody>();
      auto playerPos = std::vector<std::pair<float, float> >();
      auto player = _object->getScene()->findByName("Player");
      if (player)
	{
	  auto tmp = player->getTransform().getPosition();
	  playerPos.push_back(std::make_pair<float, float>(tmp.get_x(), tmp.get_y()));
	} else
	{
	  playerPos.push_back(std::make_pair<float, float>(100, 100));
	}
      std::pair<float, float> bestmove = _ia->getBestMove(playerPos, std::make_pair(pos.get_x(), pos.get_y()));
      //      std::pair<float, float> bestmove = _ia->getBestMove(pos.get_x(), pos.get_y());
        auto dir = Vector2(bestmove.first, bestmove.second);
  //      std::cout << "OKEK"<<std::endl;
        _object->getTransform().setDirection(dir);
        _object->getTransform().setSpeed(1);
        rb->addForce(dir * _object->getTransform().getSpeed());
        if (can_shoot == tick_per_shoot) {
            shoot();
            can_shoot = 0;
        }
    }

    void MonsterBehaviour::shoot()
    {
        auto bullet = std::make_shared<Sprite>("bullet" + this->getGameObjectName(), this->_object->getScene(),
                                               Layout::SCENE);
        bullet->setTexture(_object->getScene()->getTexture("bullet"));
        bullet->setSize(Vector2(30, 30));
        bullet->getTransform().setPosition(_object->getTransform().getPosition() - Vector2(42, 0));
        bullet->getTransform().setSpeed(_object->getTransform().getSpeed() + 3);
        auto col = std::make_shared<Collider>("Collider" + bullet->getInstanceName(), bullet, bullet->getSize(),
                                              bullet->getTransform().getPosition(), true);
        auto rbody = std::make_shared<Rigidbody>("Rigidbody" + bullet->getInstanceName(), bullet);
        auto beha = std::make_shared<BulletBehaviour>("bulletbeha" + bullet->getInstanceName(), bullet, Vector2(-1, 0));
        this->_object->getScene()->addGameObject(bullet);
        this->_object->getScene()->addComponent(col);
        this->_object->getScene()->addComponent(rbody);
        this->_object->getScene()->addComponent(beha);
    }

  void MonsterBehaviour::onCollide(GameObject &other)
  {
    if (other.getInstanceName().find("bullet") != std::string::npos &&
	other.getInstanceName().find("Player") == std::string::npos)
      {
	if (--life == 0)
	  setDestroy(true);
      }
  }
}