//
// Created by chauvin on 23/01/18.
//

#ifndef GAME_CORE_HPP
#define GAME_CORE_HPP


#include <queue>
#include <iostream>

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
    Core(std::queue<JSONObject>	&cmdServer_in, std::queue<JSONObject> &cmdServer_out);
    ~Core() = default;
    void	InitGame();
    void	StartGame();

   private:
    Engine	_engine;
    std::queue<JSONObject>	*_cmdServer_in;
    std::queue<JSONObject>	*_cmdServer_out;
    std::vector<Rtype::Level>	_levels;
  };
}

#endif //GAME_CORE_HPP
