//
// Created by chauvin on 23/01/18.
//

#ifndef GAME_LEVEL_HPP
#define GAME_LEVEL_HPP

#include <vector>
#include "../GameEngine/Scene/Scene.hpp"
#include "../Entity/Entity.hpp"
#include "../GameEngine/TacosEngine.h"

class Level
{
 public:
  Level(const std::string &name, const std::shared_ptr<TacosEngine::Engine> &_engine);

  ~Level();
  //void 	addEvent();

  const std::shared_ptr<TacosEngine::Scene> &get_scene() const;

  void set_scene(const std::shared_ptr<TacosEngine::Scene> &_scene);

  std::shared_ptr<TEntity::Entity> getEntityByName(const std::string &name) const;

  std::shared_ptr<TEntity::Entity>
  addEntity(const std::string &name, TacosEngine::Layout layout, const std::string &texture,
	    const TacosEngine::Vector2 &size);

  const std::vector<std::shared_ptr<TEntity::Entity>> &get_entities() const;

  void loadComponents();

 private:
  std::vector<std::shared_ptr<TEntity::Entity>> _entities;
  //std::vector<std::shared_ptr<TacosEngine::IEvent>>	_events;
  std::shared_ptr<TacosEngine::Scene> _scene;
};

#endif //GAME_LEVEL_HPP
