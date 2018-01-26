//
// Created by chauvin on 25/01/18.
//

#include <GameEngine/Rigidbody/Rigidbody.hpp>
#include <Behaviours/PlayerBehaviour.hpp>
#include "Core.hpp"

using namespace TacosEngine;

Core::Core() = default;

Core::~Core()
= default;

void Core::Init()
{
  this->_engine = std::make_shared<Engine>();
  _engine->initRessources("ressources.txt");

  auto lvl1 = std::make_shared<Level>("lvl1", _engine);

  // LVL1
  lvl1->addEntity("Background", Layout::BACKGROUND, "back", Vector2(800, 400));

  auto player = lvl1->addEntity("Player", Layout::SCENE, "ship", Vector2(40, 40));
  auto playerBeha = std::make_shared<PlayerBehaviour>("playerBeh", player->get_sprite());
  player->addBehaviour(playerBeha);
  player->addCollider(std::make_shared<Collider>("ok", player->get_sprite(), player->get_sprite()->getSize(),
						 player->get_sprite()->getTransform().getPosition(), true));
  player->addRigidBody(std::make_shared<Rigidbody>("Rb", player->get_sprite()));

  auto obs = lvl1->addEntity("Obs", Layout::SCENE, "ship", Vector2(40, 40));
  obs->get_sprite()->getTransform().setPosition(Vector2(400, 200));
  obs->addCollider(std::make_shared<Collider>("Collider", obs->get_sprite(), obs->get_sprite()->getSize(),
					      obs->get_sprite()->getTransform().getPosition(), true));
  obs->addRigidBody(std::make_shared<Rigidbody>("Rigidbody", obs->get_sprite()));

  auto obs2 = lvl1->addEntity("Obs2", Layout::SCENE, "ship", Vector2(40, 40));
  obs2->get_sprite()->getTransform().setPosition(Vector2(400, 100));
  obs2->addCollider(std::make_shared<Collider>("Collider", obs2->get_sprite(), obs2->get_sprite()->getSize(),
					       obs2->get_sprite()->getTransform().getPosition(), true));
  obs2->addRigidBody(std::make_shared<Rigidbody>("Rigidbody", obs2->get_sprite()));

  lvl1->loadComponents();
  // LVL2

  // Load and run level1
  _engine->loadScene(lvl1->get_scene());
}

const std::shared_ptr<TacosEngine::Engine> &Core::get_engine() const
{
  return _engine;
}

void Core::set_engine(const std::shared_ptr<TacosEngine::Engine> &_engine)
{
  Core::_engine = _engine;
}

