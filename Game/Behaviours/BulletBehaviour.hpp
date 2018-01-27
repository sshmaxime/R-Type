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
    BulletBehaviour(const std::string &name, const std::shared_ptr<GameObject> &object, Vector2 dir);

   private:
    void Start() override;

    void update(const Input &) override;

    void onCollide(GameObject &other) override;

   private:
    Vector2 _dir;
  };
}

#endif //GAME_BULLETBEHAVIOUR_HPP
