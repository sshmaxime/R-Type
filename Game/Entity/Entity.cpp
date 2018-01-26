//
// Created by chauvin on 23/01/18.
//

#include "Entity.hpp"
#include "../Level/Level.hpp"

const std::shared_ptr<TacosEngine::Sprite> &TEntity::Entity::get_sprite() const
{
  return _sprite;
}

void TEntity::Entity::set_sprite(const std::shared_ptr<TacosEngine::Sprite> &_sprite)
{
  Entity::_sprite = _sprite;
}

const std::string &TEntity::Entity::get_name() const
{
  return _name;
}

void TEntity::Entity::set_name(const std::string &_name)
{
  Entity::_name = _name;
}

void TEntity::Entity::addBehaviour(std::shared_ptr<TacosEngine::Behaviour> ptr)
{
  this->_behaviours.push_back(ptr);
}

void TEntity::Entity::addCollider(std::shared_ptr<TacosEngine::Collider> ptr)
{
  this->_colliders.push_back(ptr);
}

void TEntity::Entity::addRigidBody(std::shared_ptr<TacosEngine::Rigidbody> ptr)
{
  this->_rigidBodies.push_back(ptr);
}

void TEntity::Entity::addSound(std::shared_ptr<TacosEngine::AudioComponent> ptr)
{
  this->_audioSound.push_back(ptr);
}

void TEntity::Entity::addAnimation(std::shared_ptr<TacosEngine::Animation> ptr)
{
  this->_animations.push_back(ptr);
}

void TEntity::Entity::loadComponents(std::shared_ptr<TacosEngine::Scene> ptr)
{
  for (auto &it : _behaviours)
    ptr->addComponent(it);
  for (auto &it : _colliders)
    ptr->addComponent(it);
  for (auto &it : _audioSound)
    ptr->addComponent(it);
  for (auto &it : _rigidBodies)
    ptr->addComponent(it);
  for (auto &it : _animations)
    ptr->addComponent(it);
}
