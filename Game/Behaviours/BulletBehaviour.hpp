//
// Created by chauvin on 26/01/18.
//

#ifndef GAME_BULLETBEHAVIOUR_HPP
#define GAME_BULLETBEHAVIOUR_HPP

#include <GameEngine/Behaviour/Behaviour.h>

namespace TacosEngine
{
  class BulletBehaviour : public TacosEngine::Behaviour
  {
   public:
    BulletBehaviour(const std::string &name, const std::shared_ptr<GameObject> &object);

   private:
    void Start() override;

    void update(const Input &) override;

    void onCollide(GameObject &other) override;
  };
}

#endif //GAME_BULLETBEHAVIOUR_HPP
