//
// Created by chauvin on 14/01/18.
//

#ifndef RESSOURCEMANAGER_SFMLAUDIO_HPP
#define RESSOURCEMANAGER_SFMLAUDIO_HPP


#include <SFML/Audio.hpp>
#include <memory>
#include "IAudio.hpp"

class sfmlAudio : public TacosEngine::IAudio
{
  std::shared_ptr<sf::SoundBuffer> _sound;

 public:
  sfmlAudio();
  ~sfmlAudio();
  bool load(const std::string &path) override;
  void *getAudio() override;
};


#endif //RESSOURCEMANAGER_SFMLAUDIO_HPP
