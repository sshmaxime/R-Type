//
// Created by chauvin on 23/01/18.
//

#include "Entity.hpp"
#include "../Level/Level.hpp"

namespace TacosEngine
{
void PlayerBehaviour::update(const Input &input)
{
  Vector2 dir(input.getAxis("Horizontal"), input.getAxis("Vertical"));
  auto sprite =  _lvl->getEntityByName("Player")->get_sprite()->getLayout();
    //sprite->getTransform().setDirection(dir);
  auto rb = getComponent<Rigidbody>();

  if (input.getAxis("Horizontal") != 0 && input.getAxis("Vertical") != 0)
    dir = dir / 2;
  _object->getTransform().setDirection(dir);
  _object->getTransform().setSpeed(2.5);
  rb->addForce(dir * _object->getTransform().getSpeed());
    if (dir.get_y() != 0 || dir.get_x() != 0)
        _lastdir = dir * _object->getTransform().getSpeed() * 1.5;

  _object->getScene();
  if (input.getKey(static_cast<TacosEngine::Key>(Key::KEY_SPACE)) && !isShooting)
  {
      shoot();
  }
  isShooting = input.getKey(static_cast<TacosEngine::Key>(Key::KEY_SPACE));
}
    void PlayerBehaviour::shoot()
    {
        auto lvl = this->getLvl();
        auto bul = lvl->addEntity("bullet"  + getGameObjectName(), Layout::SCENE, "bullet", Vector2(20, 20));
        bul->get_sprite()->getTransform().setPosition(_object->getTransform().getPosition());
        bul->addCollider(std::make_shared<Collider>("Collider", bul->get_sprite(), bul->get_sprite()->getSize(),
                                                    bul->get_sprite()->getTransform().getPosition(), true));
        auto rbody = std::make_shared<Rigidbody>("Rigidbody", bul->get_sprite());
        rbody->addForce(_lastdir);
        bul->addRigidBody(rbody);
        bul->addBehaviour(std::make_shared<EntityBehaviour>("bullet", bul->get_sprite(), (lvl->getEntityByName("Background")->get_sprite()->getSize())));
        lvl->loadComponents();
        std::cout << "bullet " <<std::endl;
    }

    void EntityBehaviour::update(const Input &)
    {
        auto pos = _object->getTransform().getPosition();
        if (pos.get_x() < 0 || pos.get_y() < 0 ||
                pos.get_x() > _sizeWindow.get_x() || pos.get_y() > _sizeWindow.get_y())
        {
            std::cout << "will destroy entity" << std::endl;
            setDestroy(true);
        }

    }
}

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
