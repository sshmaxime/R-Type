//
// Created by chauvin on 23/01/18.
//

#ifndef GAME_CORE_HPP
#define GAME_CORE_HPP


#include <queue>
#include <iostream>
#include <GameEngine/TacosEngine.h>
#include <Level/Level.hpp>

namespace Rtype
{
  enum class GAMESTATE{
    MENU,
    GAMELOOP,
    EXIT
  };

  class	Core
  {
   public:
    Core();
    ~Core() = default;
    void	InitGame();
    void	StartGame();

   private:
    TacosEngine::Engine	_engine;
    /*std::queue<JSONObject>	*_cmdServer_in;
    std::queue<JSONObject>	*_cmdServer_out;*/
    std::vector<::>	_levels;
  };
}

#endif //GAME_CORE_HPP
