//
// Created by chauvin on 23/01/18.
//

#ifndef GAME_ENTITY_HPP
#define GAME_ENTITY_HPP

#include <memory>
#include <iostream>
#include <vector>

namespace TEntity
{
  namespace TacosEngine
  {
    class EntityBehaviour : public Behaviour
    {
     public:
      EntityBehaviour(const std::string &name, std::shared_ptr<Sprite> sprite) : Behaviour(name, std::move(sprite));
      ~EntityBehaviour() override = default;
    };
  }

  class Entity
  {
   public:
    Entity();
    ~Entity();
    void	Init();
   private:
    std::shared_ptr<TacosEngine::Sprite> _sprite;
    std::vector<TacosEngine::EntityBehaviour> _behaviours;
    std::vector<TacosEngine::Collider> _colliders;
    std::vector<TacosEngine::AudioComponent> _audioSound;
    TacosEngine::Animation	_anim;

    std::string	_name;
    size_t	_health;
    size_t 	_maxhealth;
    size_t 	_damages;
    size_t 	_attackSpeed = 0;
    bool	_ableAttack = true;
    bool	isMoving;
    bool	isShooting;
  };
}

#endif //GAME_ENTITY_HPP
