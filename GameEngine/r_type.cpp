#include <iostream>
#include <utility>
#include <AudioComponent/AudioComponent.hpp>
#include "TacosEngine.h"

namespace TacosEngine
{
  class Behaviour;

  class PlayerBehaviour : public Behaviour
  {
   public:
    PlayerBehaviour(const std::string &name, std::shared_ptr<Sprite> sprite)
	    : Behaviour(name, std::move(sprite))
    {
    }

    ~PlayerBehaviour() override = default;

    void update(const Input &input) override
    {
      Vector2 dir(input.getAxis("Horizontal"), input.getAxis("Vertical"));

      if (input.getAxis("Horizontal") != 0 && input.getAxis("Vertical") != 0)
	dir = dir / 2;
      _sprite->getTransform().setDirection(dir);
      _sprite->getTransform().setSpeed(0.5f);
      Vector2 newPos(_sprite->getTransform().getPosition() + dir * _sprite->getTransform().getSpeed());
      _sprite->getTransform().setPosition(newPos);
    }
  };

  class BackgroundBehaviour : public Behaviour
  {
   public:
    BackgroundBehaviour(const std::string &name, std::shared_ptr<Sprite> sprite)
	    : Behaviour(name, std::move(sprite))
    {
    }

    ~BackgroundBehaviour() override = default;

    void update(const Input &input) override
    {
      auto a = getComponent<AudioComponent>();
      a->play(false, 0);
      _sprite->getTransform().setSpeed(0.01f);
      Vector2 newPos(_sprite->getTransform().getPosition() + Vector2(-1, 0) * _sprite->getTransform().getSpeed());
      _sprite->getTransform().setPosition(newPos);
    }
  };
}

using namespace TacosEngine;

int main()
{
  Engine engine;
  std::shared_ptr<Scene> scene = std::make_shared<Scene>("Scene1");

  engine.initRessources("ressources.txt");

  // Scene
  engine.addScene(scene);

  // Sprite background
  std::shared_ptr<Sprite> back = std::make_shared<Sprite>("Background", scene, Layout::BACKGROUND);
  std::shared_ptr<AudioComponent> Audioback = std::make_shared<AudioComponent>("Audioback", back, scene->getAudio("Audioback"));
  std::shared_ptr<BackgroundBehaviour> backBeha = std::make_shared<BackgroundBehaviour>("backBeh", back);
  back->setTexture(scene->getTexture("back"));
  back->setSize(Vector2(800, 400));
  scene->addSprite(back);
  scene->addComponent(Audioback);
  scene->addComponent(backBeha);

  // Sprite ship
  std::shared_ptr<Sprite> player = std::make_shared<Sprite>("Player", scene, Layout::SCENE);
  if (!player->setTexture(scene->getTexture("ship")))
    return EXIT_FAILURE;
  player->setSize(Vector2(20, 20));
  std::shared_ptr<PlayerBehaviour> playerBeha = std::make_shared<PlayerBehaviour>("playerBeh", player);
  scene->addComponent(playerBeha);
  scene->addSprite(player);

  // Load and run scene
  engine.loadScene(scene);
  engine.run();
  return 0;
}