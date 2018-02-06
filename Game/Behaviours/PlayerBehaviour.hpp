//
// Created by chauvin on 26/01/18.
//

#ifndef GAME_PLAYERBEHAVIOUR_HPP
#define GAME_PLAYERBEHAVIOUR_HPP


#include "../GameEngine/Behaviour/Behaviour.h"
#include "../GameEngine/Sprite/Sprite.hpp"
#include "BulletBehaviour.hpp"
#include "ObstacleBehaviour.hpp"
#include "../GameEngine/Animation/Animation.hpp"
#include "AnimationBehaviour.hpp"

namespace TacosEngine
{
  class PlayerBehaviour : public Behaviour
  {
   public:
    PlayerBehaviour(const std::string &name, std::shared_ptr<Sprite> sprite, bool a)
	    : Behaviour(name, std::move(sprite))
    {
      this->_health = 100;
      this->_damages = 20;
      this->_bulletType = 1;
      sizeX = 0;
      sizeY = 0;
      _isActive = a;
    }

    ~PlayerBehaviour() override = default;

    void Start() override
    {
      std::cout << "In Start()" << std::endl;
      auto sp = std::dynamic_pointer_cast<Sprite>(_object);
      sizeX = sp->getSize().get_x();
      sizeY = sp->getSize().get_y();
    }

    void update(const Input &input) override;

    void shoot();

    void onCollide(GameObject &other) override;

    Vector2    &CheckWindowCollide(Vector2 &dir)
    {
      if (dir.get_x() < 0 && _object->getTransform().getPosition().get_x() <= 0.5 ||
	  dir.get_x() > 0 && _object->getTransform().getPosition().get_x() >= (799.5 - sizeX))
	dir.set_x(0);
      if (dir.get_y() > 0 && _object->getTransform().getPosition().get_y() >= (399.5 - sizeY) ||
	  dir.get_y() < 0 && _object->getTransform().getPosition().get_y() <= 0.5)
	dir.set_y(0);
      return dir;
    }

   private:
    int _health;
    int _damages;
    size_t _attackSpeed = 0;
    bool _ableAttack = true;
    bool isMoving{};
    bool isShooting{};
    int  _bulletType;
    Vector2 _lastdir;
    float sizeX;
    float sizeY;
  };
}

#endif //GAME_PLAYERBEHAVIOUR_HPP
