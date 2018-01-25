//
// Created by chauvin on 23/01/18.
//

#ifndef GAME_ENTITY_HPP
#define GAME_ENTITY_HPP

#include <memory>
#include <iostream>
#include <vector>
#include <GameEngine/Rigidbody/Rigidbody.hpp>
#include "../GameEngine/Behaviour/Behaviour.h"
#include "../GameEngine/Sprite/Sprite.hpp"
#include "../GameEngine/Collider/Collider.hpp"
#include "../GameEngine/AudioComponent/AudioComponent.hpp"
#include "../GameEngine/Animation/Animation.hpp"

namespace TacosEngine
{
  class EntityBehaviour : public TacosEngine::Behaviour
  {
   public:
    EntityBehaviour(const std::string &name, std::shared_ptr<Sprite> sprite);

    ~EntityBehaviour() override = default;

   private:
    size_t _health;
    size_t _maxhealth;
    size_t _damages;
    size_t _attackSpeed = 0;
    bool _ableAttack = true;
    bool isMoving;
    bool isShooting;
  };

  class PlayerBehaviour : public Behaviour
  {
   public:
    PlayerBehaviour(const std::string &name, std::shared_ptr<Sprite> sprite)
	    : Behaviour(name, std::move(sprite))
    {
    }

    ~PlayerBehaviour() override = default;

    void Start() override
    {
      std::cout << "In Start()" << std::endl;
    }

    void update(const Input &input) override
    {
      Vector2 dir(input.getAxis("Horizontal"), input.getAxis("Vertical"));
      auto rb = getComponent<Rigidbody>();

      if (input.getAxis("Horizontal") != 0 && input.getAxis("Vertical") != 0)
	dir = dir / 2;
      _object->getTransform().setDirection(dir);
      _object->getTransform().setSpeed(0.5f);
      rb->addForce(dir * _object->getTransform().getSpeed());
    }

    void onCollide(GameObject &other) override
    {
      std::cout << "OnCollide() => " << other.getInstanceName() << std::endl;
      if (other.getInstanceName() == "Obs")
	{
	  if (auto obs2 = _object->findByName("Obs2"))
	    obs2->getTransform().setPosition(Vector2(10, 10));
	  setDestroy(true);
	}
    }

   private:
    size_t _health{};
    size_t _maxhealth{};
    size_t _damages{};
    size_t _attackSpeed = 0;
    bool _ableAttack = true;
    bool isMoving{};
    bool isShooting{};
  };
}

namespace TEntity
{
  class Entity
  {
   public:
    Entity() = default;

    ~Entity() = default;

    const std::shared_ptr<TacosEngine::Sprite> &get_sprite() const;

    void set_sprite(const std::shared_ptr<TacosEngine::Sprite> &_sprite);

    const std::string &get_name() const;

    void set_name(const std::string &_name);

    void addBehaviour(std::shared_ptr<TacosEngine::PlayerBehaviour> ptr);

    void addCollider(std::shared_ptr<TacosEngine::Collider> ptr);

    void addRigidBody(std::shared_ptr<TacosEngine::Rigidbody> ptr);

    void addSound(std::shared_ptr<TacosEngine::AudioComponent> ptr);

    void addAnimation(std::shared_ptr<TacosEngine::Animation> ptr);

    void loadComponents(std::shared_ptr<TacosEngine::Scene> ptr);

   private:
    std::shared_ptr<TacosEngine::Sprite> _sprite;
    std::vector<std::shared_ptr<TacosEngine::Behaviour>> _behaviours;
    std::vector<std::shared_ptr<TacosEngine::Collider>> _colliders;
    std::vector<std::shared_ptr<TacosEngine::AudioComponent>> _audioSound;
    std::vector<std::shared_ptr<TacosEngine::Rigidbody>> _rigidBodies;
    std::vector<std::shared_ptr<TacosEngine::Animation>> _animations;

    std::string _name;
  };
}

#endif //GAME_ENTITY_HPP
