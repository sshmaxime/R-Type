//
// Created by chauvin on 25/01/18.
//

#include <HelloPacket.h>
#include <CmdMovePacket.h>
#include <CmdShotPacket.h>
#include <CmdAddPlayerPacket.hpp>
#include "Core.hpp"
#include "../Behaviours/MonsterBossBehaviour.h"
#include "../Behaviours/BackgroundBehaviour.hpp"
#include "../Behaviours/PlayerBehaviour.hpp"
#include "../../Client/Global/CGlobal.h"
#include "../Behaviours/MonsterBonusBehaviour.hpp"
#include "../Level/SpawnManager.h"
#include "../Events/EventMove.hpp"
#include "../Events/EventShoot.hpp"
#include "../Events/EventAddPlayer.hpp"

using namespace TacosEngine;

Core::Core() = default;

Core::~Core()
= default;

void Core::Init(bool displayMode)
{
  this->_engine = std::make_shared<Engine>(displayMode);
    _engine->initRessources("ressources.txt");

  auto lvl1 = std::make_shared<Level>("lvl1", _engine);

  auto spawn = lvl1->addEntity("Spawner", Layout::SCENE, "droid", Vector2(1, 1));
  spawn->addBehaviour(std::make_shared<SpawnManager>("Spawner", spawn->get_sprite()));

    auto back = lvl1->addEntity("Background", Layout::BACKGROUND, "background2", Vector2(800, 400));
    back->addRigidBody(std::make_shared<Rigidbody>("RigidBodyback", back->get_sprite()));
    back->addBehaviour(std::make_shared<BackgroundBehaviour>("backgroundbeh", back->get_sprite()));


  /* auto player = lvl1->addEntity("Player1", Layout::SCENE, "player1", Vector2(29, 13));
   auto playerBeha = std::make_shared<PlayerBehaviour>("playerBeh", player->get_sprite(), false);
   player->addBehaviour(playerBeha);
   player->addCollider(std::make_shared<Collider>("ok", player->get_sprite(), player->get_sprite()->getSize(),
						  player->get_sprite()->getTransform().getPosition(), true));
   player->addRigidBody(std::make_shared<Rigidbody>("Rb", player->get_sprite()));

   auto player2 = lvl1->addEntity("Player2", Layout::SCENE, "player2", Vector2(29, 13));
   auto playerBeha2 = std::make_shared<PlayerBehaviour>("playerBeh2", player2->get_sprite(), true);
   player2->addBehaviour(playerBeha2);
   player2->addCollider(std::make_shared<Collider>("ok", player2->get_sprite(), player2->get_sprite()->getSize(),
						   player2->get_sprite()->getTransform().getPosition(), true));
   player2->addRigidBody(std::make_shared<Rigidbody>("Rb", player2->get_sprite()));
 */

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

void Core::addEvent(const std::string& JSONString)
{
    std::string header = JSONString.substr(0, 3);
    std::string packetContent = JSONString.substr(3);

    std::cout << "--" << packetContent << "--" << std::endl;
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
  if (header == "1x3")
    {
      CmdAddPlayerPacket a;
      a.buildObjectFromJSON(packetContent);
      auto event = std::make_shared<EventAddPlayer>(this->get_engine()->getSceneInProcess(), a.get_Username(),
						    a.get_Number(), a.get_Active());
      auto name = "EventAddPlayer" + a.get_Username();
      while (!CGlobal::Instance()->_mutexSend.try_lock());
      this->_engine->getEventManager()->addEvent(event, name);
      CGlobal::Instance()->_mutexSend.unlock();
    }
}
