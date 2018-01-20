//
// Created by chauvin on 14/01/18.
//

#ifndef RESSOURCEMANAGER_IFONT_HPP
#define RESSOURCEMANAGER_IFONT_HPP

#include <iostream>

namespace TacosEngine
{
  class IFont
  {
   public:
    virtual bool load(const std::string &path) = 0;
    virtual void *getFont() = 0;
  };
}

#endif //RESSOURCEMANAGER_IFONT_HPP
