//
// Created by chauvin on 14/01/18.
//

#ifndef RESSOURCEMANAGER_IAUDIO_HPP
#define RESSOURCEMANAGER_IAUDIO_HPP

#include <iostream>

namespace TacosEngine
{
  class IAudio
  {
   public:
    virtual bool load(const std::string &path) = 0;
    virtual void *getAudio() = 0;
  };
}

#endif //RESSOURCEMANAGER_IAUDIO_HPP
