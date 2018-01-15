//
// Created by chauvin on 14/01/18.
//

#include "sfmlAudio.hpp"

bool sfmlAudio::load(const std::string &path)
{
  if (!this->_sound->loadFromFile(path))
    {
      std::cerr << "Failed to load texture from " << path << std::endl;
      return false;
    }
  return true;
}

void *sfmlAudio::getAudio()
{
  return static_cast<void *>(this->_sound.get());
}

sfmlAudio::sfmlAudio() = default;

sfmlAudio::~sfmlAudio() = default;
