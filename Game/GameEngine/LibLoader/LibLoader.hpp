#pragma once

#include <dlfcn.h>
#include <iostream>
#include <utility>
#include <list>
#include "../Behaviour/Behaviour.h"
//#include "../Behaviour/Behaviour.h"
#include "../../Behaviours/MonsterIA.h"

class LibLoader
{
 public:
  LibLoader();

  ~LibLoader();

  MonsterIa *LoadLib(const std::string &pathlib, std::shared_ptr<TacosEngine::Scene> scene);

 private:
  std::list<MonsterIa *> _libHistoric;

};

typedef MonsterIa *create_t();

typedef void destroy_t(MonsterIa *ptr);
