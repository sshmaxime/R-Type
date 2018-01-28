//
// Created by chauvin on 25/01/18.
//

#ifndef GAME_CORE_HPP
#define GAME_CORE_HPP



#include <queue>
#include "../Level/Level.hpp"
#include "../GameEngine/TacosEngine.h"
#include "../../Common/JSON/JSONObject.h"

class Core
{
 public:
  Core();
  ~Core();

  void Init(bool);
  const std::shared_ptr<TacosEngine::Engine> &get_engine() const;
  void set_engine(const std::shared_ptr<TacosEngine::Engine> &_engine);
  void addEvent(std::string &msg);
  const std::shared_ptr<std::queue<JSONObject>> &get_send() const;
  void set_send(const std::shared_ptr<std::queue<JSONObject>> &_send);
 private:
  std::shared_ptr<TacosEngine::Engine> _engine;
  std::vector<std::shared_ptr<Level>> _levels;
};


#endif //GAME_CORE_HPP
