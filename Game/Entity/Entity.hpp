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
class Level;
namespace TacosEngine
{
  class EntityBehaviour : public TacosEngine::Behaviour
  {
   public:
    EntityBehaviour(const std::string &name, std::shared_ptr<Sprite> sprite, Vector2 sizeWindow)
            : Behaviour(name, std::move(sprite))
    {

      _sizeWindow = sizeWindow;
      std::cout << "entity created:  x:" << _sizeWindow.get_x() << "   y:"<<_sizeWindow.get_y();
    }
      void Start() override
      {
        std::cout << "In Start()" << std::endl;
      }

      void update(const Input&) override;

      void onCollide(GameObject &other) override
      {
        std::cout << "ENTITYOnCollide() => " << other.getInstanceName() << std::endl;
        if (other.getInstanceName().find("bullet")== std::string::npos)
          setDestroy(true);
      }
   private:
    size_t _health;
    size_t _maxhealth;
    size_t _damages;
    size_t _attackSpeed = 0;
    bool _ableAttack = true;
    bool isMoving;
    bool isShooting;
      Vector2 _dir;
      Vector2 _sizeWindow;
  };

  class PlayerBehaviour : public Behaviour
  {
   public:
    PlayerBehaviour(const std::string &name, std::shared_ptr<Sprite> sprite)
	    : Behaviour(name, std::move(sprite))
    {
    }

      void setLevel(std::shared_ptr<Level> lvl)
      {
          _lvl = lvl;
      }
      const std::shared_ptr<Level>    &getLvl()
      {
          return _lvl;
      }
    ~PlayerBehaviour() override = default;

    void Start() override
    {
      std::cout << "In Start()" << std::endl;
    }

    void update(const Input &input) override;
      void shoot();

    void onCollide(GameObject &other) override
    {
      std::cout << "OnCollide() => " << other.getInstanceName() << std::endl;
      if (other.getInstanceName().find("bullet")!= std::string::npos && other.getInstanceName().find(getInstanceName()) == std::string::npos)
      {
        std::cout << "COLLISION WITH BULLET, should destroy" <<std::endl;
	  /*if (auto obs2 = _object->findByName("Obs2"))
	    obs2->getTransform().setPosition(Vector2(10, 10));
	  setDestroy(true);*/
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
      std::shared_ptr<Level> _lvl;
      Vector2   _lastdir;

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

    void addBehaviour(std::shared_ptr<TacosEngine::Behaviour> ptr);

    void addCollider(std::shared_ptr<TacosEngine::Collider> ptr);

    void addRigidBody(std::shared_ptr<TacosEngine::Rigidbody> ptr);

    void addSound(std::shared_ptr<TacosEngine::AudioComponent> ptr);

    void addAnimation(std::shared_ptr<TacosEngine::Animation> ptr);

    void loadComponents(std::shared_ptr<TacosEngine::Scene> ptr);


      void setLevel(std::shared_ptr<Level> lvl);
      const std::shared_ptr<Level>    &get_Lvl();
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
