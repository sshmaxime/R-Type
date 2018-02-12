#pragma once

#ifndef WIN32
#include <dlfcn.h>
#include "ILibrary.hpp"

class LibLoader : public ILibrary
{
 public:
  LibLoader();

  ~LibLoader();

  virtual MonsterIa *LoadLib(const std::string &pathlib, std::shared_ptr<TacosEngine::Scene> scene);

 private:
  std::list<MonsterIa *> _libHistoric;

};

typedef MonsterIa *create_t();

typedef void destroy_t(MonsterIa *ptr);
#endif