//
// Created by chauvin on 26/01/18.
//

#ifndef GAME_OBSTACLEOBSERVER_HPP
#define GAME_OBSTACLEOBSERVER_HPP


#include <GameEngine/Behaviour/Behaviour.h>

namespace TacosEngine
{
  class ObstacleObserver : TacosEngine::Behaviour
  {
   public:
    ObstacleObserver(const std::string &name, const std::shared_ptr<GameObject> &object);

    ~ObstacleObserver() override = default;

    void Start() override;

    void update(const Input &) override;

    void onCollide(GameObject &other) override;

   private:
  };
}

#endif //GAME_OBSTACLEOBSERVER_HPP
