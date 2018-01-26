//
// Created by chauvin on 26/01/18.
//

#ifndef GAME_PLAYERBEHAVIOUR_HPP
#define GAME_PLAYERBEHAVIOUR_HPP

#include <GameEngine/Scene/Scene.hpp>
#include <GameEngine/Input/Input.h>
#include <Level/Level.hpp>

namespace TacosEngine
{
  class PlayerBehaviour : public Behaviour
  {
   public:
    PlayerBehaviour(const std::string &name, std::shared_ptr<Sprite> sprite)
	    : Behaviour(name, std::move(sprite))
    {
    }

    ~PlayerBehaviour() override = default;

    void Start() override
    {
      std::cout << "In Start()" << std::endl;
    }

    void update(const Input &input) override;

    void shoot();

    void onCollide(GameObject &other) override
    {
      std::cout << "OnCollide() => " << other.getInstanceName() << std::endl;
      if (other.getInstanceName().find("bullet") != std::string::npos &&
	  other.getInstanceName().find(getInstanceName()) == std::string::npos)
	{
	  std::cout << "COLLISION WITH BULLET, should destroy" << std::endl;
	  /*if (auto obs2 = _object->findByName("Obs2"))
	    obs2->getTransform().setPosition(Vector2(10, 10));
	  setDestroy(true);*/
	}
    }

   private:
    size_t _health{};
    size_t _maxhealth{};
    size_t _damages{};
    size_t _attackSpeed = 0;
    bool _ableAttack = true;
    bool isMoving{};
    bool isShooting{};
    Vector2 _lastdir;
  };
}

#endif //GAME_PLAYERBEHAVIOUR_HPP
