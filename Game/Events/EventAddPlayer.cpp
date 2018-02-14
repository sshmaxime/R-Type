//
// Created by chauvin on 12/02/18.
//

#include "EventAddPlayer.hpp"

//
// Created by chauvin on 28/01/18.
//

#include "../Entity/Entity.hpp"
#include "../Behaviours/PlayerBehaviour.hpp"


TacosEngine::EventAddPlayer::EventAddPlayer(std::shared_ptr<Scene> scene, const std::string &name, int number,
					    bool active)
{
  _scene = scene;
  _name = name;
  _nb = number;
  _active = active;
}

void TacosEngine::EventAddPlayer::onEvent()
{
  auto newEntity = std::make_shared<TEntity::Entity>();

  newEntity->set_name(_name);
  newEntity->set_sprite(std::make_shared<TacosEngine::Sprite>(_name, this->_scene, Layout::SCENE));
  newEntity->get_sprite()->setTexture(this->_scene->getTexture("player" + _nb));
  newEntity->get_sprite()->setSize(Vector2(29, 13));
  auto playerBeha = std::make_shared<PlayerBehaviour>("playerBeh", newEntity->get_sprite(), this->_active);
  newEntity->addBehaviour(playerBeha);
  newEntity->addCollider(std::make_shared<Collider>("ok", newEntity->get_sprite(), newEntity->get_sprite()->getSize(),
						    newEntity->get_sprite()->getTransform().getPosition(), true));
  newEntity->addRigidBody(std::make_shared<Rigidbody>("Rb", newEntity->get_sprite()));
  this->_scene->addGameObject(newEntity->get_sprite());
}
