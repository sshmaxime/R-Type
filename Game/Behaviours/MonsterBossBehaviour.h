//
// Created by simon on 27/01/18.
//

#ifndef GAME_MONSTERBOSSBEHAVIOUR_H
#define GAME_MONSTERBOSSBEHAVIOUR_H

#include "MonsterBehaviour.h"
#include "BulletBehaviour.hpp"
#include "MonsterIA.h"

class MonsterIa;

namespace TacosEngine
{
  class MonsterBossBehaviour : public Behaviour
  {
   public:
    MonsterBossBehaviour(const std::string &name, std::shared_ptr<Sprite> sprite, MonsterIa *ia)
	    : Behaviour(name, std::move(sprite))
    {
      can_shoot = 0;
      tick_per_shoot = 50;
      _ia = ia;
      life = 150;
    }

    ~MonsterBossBehaviour() override = default;

    void Start() override
    {
      std::cout << "MONSTER In Start()" << std::endl;
    }

    void update(const Input &) override;

    void shoot();

    void onCollide(GameObject &other) override
    {
      std::cout << "MONSTEROnCollide() => " << other.getInstanceName() << std::endl;

      if (other.getInstanceName().find("bullet") != std::string::npos &&
	  other.getInstanceName().find("Player") == std::string::npos)
	{
	  std::cout << "DIE life:" << life;
	  if (--life == 0)
	    setDestroy(true);
	}
    }

   private:
    int can_shoot;
    int tick_per_shoot;
    int life;
    MonsterIa *_ia;
  };
}

#endif //GAME_MONSTERBOSSBEHAVIOUR_H
