//
// Created by chauvin on 14/01/18.
//

#include "sfmlTexture.hpp"

namespace TacosEngine
{
  bool sfmlTexture::load(const std::string &path)
  {
    if (!this->_texture->loadFromFile(path))
      {
	std::cerr << "Failed to load texture from " << path << std::endl;
	return false;
      }
    return true;
  }

  void *sfmlTexture::getTexture()
  {
    return static_cast<void *>(this->_texture.get());
  }

  sfmlTexture::sfmlTexture() = default;

  sfmlTexture::~sfmlTexture() = default;
}