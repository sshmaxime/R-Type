//
// Created by chauvin on 14/01/18.
//

#ifndef RESSOURCEMANAGER_ITEXTURE_HPP
#define RESSOURCEMANAGER_ITEXTURE_HPP

#include <iostream>

namespace TacosEngine
{
  class ITexture
  {
   public:
    virtual bool load(const std::string &path) = 0;
    virtual void *getTexture() = 0;
  };
}

#endif //RESSOURCEMANAGER_ITEXTURE_HPP
