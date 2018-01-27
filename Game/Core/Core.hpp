//
// Created by chauvin on 25/01/18.
//

#ifndef GAME_CORE_HPP
#define GAME_CORE_HPP



#include <queue>
#include "../Level/Level.hpp"
#include "../GameEngine/TacosEngine.h"

class Core
{
 public:
  Core();

  ~Core();

  void Init();

  const std::shared_ptr<TacosEngine::Engine> &get_engine() const;

  void set_engine(const std::shared_ptr<TacosEngine::Engine> &_engine);

 private:
  std::shared_ptr<TacosEngine::Engine> _engine;
  std::vector<std::shared_ptr<Level>> _levels;
  //std::shared_ptr<std::queue<JSONObject>> _cmdServerIn;
  //std::shared_ptr<std::queue<JSONObject>> _cmdServerOut;
};


#endif //GAME_CORE_HPP
