//
// Created by chauvin on 14/01/18.
//

#include "sfmlAudio.hpp"

bool sfmlAudio::load(const std::string &path)
{
  this->_soundBuffer = std::make_shared<sf::SoundBuffer>();
  if (!this->_soundBuffer->loadFromFile(path))
    {
      std::cerr << "Failed to open sound from " << path << std::endl;
      return false;
    } else
    {
      this->_sound = std::make_shared<sf::Sound>();
      this->_sound->setBuffer(*this->_soundBuffer.get());
    }
  return true;
}

void *sfmlAudio::getAudio()
{
  return static_cast<void *>(this->_soundBuffer.get());
}

void sfmlAudio::playSound(bool loop, int /* frame */)
{
  this->_sound->setLoop(loop);
  //this->_sound->setPlayingOffset(frame);
  this->_sound->play();
}

void sfmlAudio::stop()
{
  this->_sound->stop();
}

sfmlAudio::sfmlAudio() = default;

sfmlAudio::~sfmlAudio() = default;
