//
// Created by chauvin on 27/01/18.
//

#ifndef GAME_OBSTACLEBEHAVIOUR_HPP
#define GAME_OBSTACLEBEHAVIOUR_HPP


#include "../GameEngine/Behaviour/Behaviour.h"

namespace TacosEngine
{
  class ObstacleBehaviour : public TacosEngine::Behaviour
  {
   public:
    ObstacleBehaviour(const std::string &name, const std::shared_ptr<GameObject> &object, Vector2 dir);

    ~ObstacleBehaviour() override = default;

    void Start() override;

    void update(const Input &) override;

      int get_damages() const;

      void set_damages(int _damages);

      void onCollide(GameObject &other) override;

    float get_random()
    {
      static std::default_random_engine e;
      static std::uniform_real_distribution<> dis(-1, 1);
      return static_cast<float>(dis(e));
    }

   private:
    Vector2 _dir;
      int _damages;
  };
}

#endif //GAME_OBSTACLEBEHAVIOUR_HPP
