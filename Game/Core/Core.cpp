//
// Created by chauvin on 25/01/18.
//

#include <HelloPacket.h>
#include <CmdMovePacket.h>
#include <CmdShotPacket.h>
#include "Core.hpp"
#include "../GameEngine/LibLoader/LibLoader.hpp"
#include "../Behaviours/MonsterBossBehaviour.h"
#include "../Behaviours/BackgroundBehaviour.hpp"
#include "../Behaviours/PlayerBehaviour.hpp"
#include "../GameEngine/Events/EventMove.hpp"
#include "../../Client/Global/CGlobal.h"
#include "../GameEngine/Events/EventShoot.hpp"
#include "../Behaviours/MonsterBonusBehaviour.hpp"

using namespace TacosEngine;

Core::Core() = default;

Core::~Core()
= default;

void Core::Init(bool displayMode)
{
  this->_engine = std::make_shared<Engine>(displayMode);
    _engine->initRessources("./../Game/Extra/ressources.txt");

    auto lvl1 = std::make_shared<Level>("lvl1", _engine);

    // LVL1

    auto loader = std::make_shared<LibLoader>();

  auto boss = lvl1->addEntity("boss", Layout::SCENE, "boss1", Vector2(150, 150));
  MonsterIa *createboss = loader->LoadLib("./libMonsterZig.so", lvl1->get_scene());
  boss->get_sprite()->getTransform().setPosition(Vector2(700, 200));
  boss->addRigidBody(std::make_shared<Rigidbody>("Rb", boss->get_sprite()));
  boss->addBehaviour(std::make_shared<MonsterBossBehaviour>("monsterBeh", boss->get_sprite(), createboss));
  boss->addCollider(std::make_shared<Collider>("Monster", boss->get_sprite(), boss->get_sprite()->getSize(),
					       boss->get_sprite()->getTransform().getPosition(), true));

  auto Monster = lvl1->addEntity("Monster", Layout::SCENE, "crab", Vector2(40, 40));
  MonsterIa *create = loader->LoadLib("./libMonsterBasic.so", lvl1->get_scene());
  Monster->get_sprite()->getTransform().setPosition(Vector2(700, 340));
  Monster->addRigidBody(std::make_shared<Rigidbody>("Rb", Monster->get_sprite()));
  Monster->addBehaviour(std::make_shared<MonsterBehaviour>("monsterBeh", Monster->get_sprite(), create));
  Monster->addCollider(std::make_shared<Collider>("Monster", Monster->get_sprite(), Monster->get_sprite()->getSize(),
						  Monster->get_sprite()->getTransform().getPosition(), true));

  auto Monster2 = lvl1->addEntity("Monster2", Layout::SCENE, "crab", Vector2(40, 40));
  MonsterIa *create2 = loader->LoadLib("./libMonsterZig.so", lvl1->get_scene());
  Monster2->get_sprite()->getTransform().setPosition(Vector2(700, 100));
  Monster2->addRigidBody(std::make_shared<Rigidbody>("Rb", Monster2->get_sprite()));
  Monster2->addBehaviour(std::make_shared<MonsterBehaviour>("monsterBeh", Monster2->get_sprite(), create2));
  Monster2->addCollider(std::make_shared<Collider>("Monster", Monster2->get_sprite(), Monster2->get_sprite()->getSize(),
						   Monster2->get_sprite()->getTransform().getPosition(), true));

    auto Monster3 = lvl1->addEntity("Monster", Layout::SCENE, "droid", Vector2(30, 30));
    MonsterIa *create3 = loader->LoadLib("./libMonsterBasic.so", lvl1->get_scene());
    Monster3->get_sprite()->getTransform().setPosition(Vector2(700, 200));
    Monster3->addRigidBody(std::make_shared<Rigidbody>("Rb", Monster3->get_sprite()));
    Monster3->addBehaviour(std::make_shared<MonsterBonusBehaviour>("monsterBeh", Monster3->get_sprite(), create3));
    Monster3->addCollider(std::make_shared<Collider>("Monster", Monster3->get_sprite(), Monster3->get_sprite()->getSize(),
                                                     Monster3->get_sprite()->getTransform().getPosition(), true));


    auto back = lvl1->addEntity("Background", Layout::BACKGROUND, "background2", Vector2(800, 400));
    back->addRigidBody(std::make_shared<Rigidbody>("RigidBodyback", back->get_sprite()));
    back->addBehaviour(std::make_shared<BackgroundBehaviour>("backgroundbeh", back->get_sprite()));


  auto player = lvl1->addEntity("Player", Layout::SCENE, "player1", Vector2(29, 13));
  auto playerBeha = std::make_shared<PlayerBehaviour>("playerBeh", player->get_sprite(), false);
  player->get_sprite()->getTransform().setPosition(Vector2(40, 40));
  player->addBehaviour(playerBeha);
  player->addCollider(std::make_shared<Collider>("ok", player->get_sprite(), player->get_sprite()->getSize(),
						 player->get_sprite()->getTransform().getPosition(), true));
  player->addRigidBody(std::make_shared<Rigidbody>("Rb", player->get_sprite()));

  auto player2 = lvl1->addEntity("Player2", Layout::SCENE, "player2", Vector2(29, 13));
  auto playerBeha2 = std::make_shared<PlayerBehaviour>("playerBeh2", player2->get_sprite(), false);
  player2->addBehaviour(playerBeha2);
  player2->addCollider(std::make_shared<Collider>("ok", player2->get_sprite(), player2->get_sprite()->getSize(),
						  player2->get_sprite()->getTransform().getPosition(), true));
  player2->addRigidBody(std::make_shared<Rigidbody>("Rb", player2->get_sprite()));


  auto obs = lvl1->addEntity("Obs", Layout::SCENE, "asteroid1", Vector2(40, 40));
  obs->get_sprite()->getTransform().setPosition(Vector2(400, 200));
  obs->addCollider(std::make_shared<Collider>("Collider", obs->get_sprite(), obs->get_sprite()->getSize(),
					      obs->get_sprite()->getTransform().getPosition(), true));
  obs->addRigidBody(std::make_shared<Rigidbody>("Rigidbody", obs->get_sprite()));
  obs->addBehaviour(std::make_shared<ObstacleBehaviour>("BehaObs", obs->get_sprite(), Vector2(-1.4f, 0)));

  std::vector<ITexture *> asteroidFrames;

  asteroidFrames.push_back(lvl1->get_scene()->getTexture("asteroid1"));
  asteroidFrames.push_back(lvl1->get_scene()->getTexture("asteroid2"));
  asteroidFrames.push_back(lvl1->get_scene()->getTexture("asteroid3"));
  asteroidFrames.push_back(lvl1->get_scene()->getTexture("asteroid4"));
  asteroidFrames.push_back(lvl1->get_scene()->getTexture("asteroid5"));
  asteroidFrames.push_back(lvl1->get_scene()->getTexture("asteroid6"));
  asteroidFrames.push_back(lvl1->get_scene()->getTexture("asteroid7"));
  asteroidFrames.push_back(lvl1->get_scene()->getTexture("asteroid8"));
  asteroidFrames.push_back(lvl1->get_scene()->getTexture("asteroid9"));
  std::shared_ptr<Animation> asteroidAnim = std::make_shared<Animation>("asteroidAnim", obs->get_sprite(), true, 40,
									asteroidFrames);

    obs->addAnimation(asteroidAnim);


  auto obs2 = lvl1->addEntity("Obs2", Layout::SCENE, "asteroid5", Vector2(40, 40));
  obs2->get_sprite()->getTransform().setPosition(Vector2(400, 100));
  obs2->addCollider(std::make_shared<Collider>("Collider", obs2->get_sprite(), obs2->get_sprite()->getSize(),
					       obs2->get_sprite()->getTransform().getPosition(), true));
  obs2->addRigidBody(std::make_shared<Rigidbody>("Rigidbody", obs2->get_sprite()));
  obs2->addBehaviour(std::make_shared<ObstacleBehaviour>("BehaObs2", obs2->get_sprite(), Vector2(-1.4f, 0)));


  std::shared_ptr<Animation> asteroidAnim2 = std::make_shared<Animation>("asteroidAnim", obs2->get_sprite(), true, 30,
									 asteroidFrames);


  std::vector<ITexture *> explosionFrames;

  explosionFrames.push_back(lvl1->get_scene()->getTexture("explosion1"));
  explosionFrames.push_back(lvl1->get_scene()->getTexture("explosion2"));
  explosionFrames.push_back(lvl1->get_scene()->getTexture("explosion3"));
  std::shared_ptr<Animation> explosionAnim = std::make_shared<Animation>("explosionAnim", obs2->get_sprite(), false, 30,
									 explosionFrames);

    //obs2->addAnimation(explosionAnim);
    obs2->addAnimation(asteroidAnim2);


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

void Core::addEvent(std::string &msg)
{
  std::string header = msg.substr(0, 3);
  std::string packetContent = msg.substr(3);

  std::cout << "ADD EVENT :" + msg << std::endl;
  if (header == "1x1")
    {
      CmdMovePacket a;
      a.buildObjectFromJSON(packetContent);
      Vector2 v(stof(a.get_x()), stof(a.get_y()));
      auto event = std::make_shared<EventMove>(this->get_engine()->getSceneInProcess()->findByName(a.get_sprite()), v);
      auto name = "EventMove" + a.getUsername();
      while (!CGlobal::Instance()->_mutexSend.try_lock());
      this->_engine->getEventManager()->addEvent(event, name);
      CGlobal::Instance()->_mutexSend.unlock();
    }
  if (header == "1x2")
    {
      CmdShotPacket a;
      a.buildObjectFromJSON(packetContent);
      auto event = std::make_shared<EventShoot>(this->get_engine()->getSceneInProcess()->findByName(a.getUsername()));
      auto name = "EventMove" + a.getUsername();
      while (!CGlobal::Instance()->_mutexSend.try_lock());
      this->_engine->getEventManager()->addEvent(event, name);
      CGlobal::Instance()->_mutexSend.unlock();
    }
}
