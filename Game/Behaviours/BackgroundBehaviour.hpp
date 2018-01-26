//
// Created by chauvin on 26/01/18.
//

#ifndef GAME_BACKGROUNDBEHAVIOUR_HPP
#define GAME_BACKGROUNDBEHAVIOUR_HPP

#include <iostream>
#include <memory>
#include <GameEngine/Behaviour/Behaviour.h>
#include <GameEngine/Sprite/Sprite.hpp>

namespace TacosEngine
{
  class BackgroundBehaviour : public TacosEngine::Behaviour
  {
   public:
    BackgroundBehaviour(const std::string &name, const std::shared_ptr<GameObject> &object);

    ~BackgroundBehaviour() override;

    void Start() override;

    void update(const Input &) override;

    void onCollide(GameObject &other) override
    {};
   private:
    std::shared_ptr<Sprite> _background2;
   public:


  };
}

#endif //GAME_BACKGROUNDBEHAVIOUR_HPP
