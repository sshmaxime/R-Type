//
// Created by chauvin on 23/01/18.
//

#ifndef GAME_LEVEL_HPP
#define GAME_LEVEL_HPP

#include <vector>
#include <Entity/Entity.hpp>

namespace TLevel
{
  class Level
  {
   public:
    Level();
    ~Level();
    void	Init();
   private:
    std::vector<TEntity::Entity>	_entities;
    std::vector<TacosEngine::IEvent>	_events;
    TacosEngine::Scene			_scene;
    std::string				_ressourceFile;
  };
}

#endif //GAME_LEVEL_HPP
