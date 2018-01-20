//
// Created by chauvin on 14/01/18.
//

#include <iostream>
#include "sfmlFont.hpp"

namespace TacosEngine
{
  bool sfmlFont::load(const std::string &path)
  {
    if (!this->_font->loadFromFile(path))
      {
	std::cerr << "Failed to load texture from " << path << std::endl;
	return false;
      }
    return true;
  }

  void *sfmlFont::getFont()
  {
    return static_cast<void *>(this->_font.get());
  }

  sfmlFont::sfmlFont() = default;

  sfmlFont::~sfmlFont() = default;
}