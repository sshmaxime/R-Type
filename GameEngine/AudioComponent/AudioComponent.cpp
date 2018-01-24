//
// Created by chauvin on 23/01/18.
//

#include "AudioComponent.hpp"

TacosEngine::AudioComponent::AudioComponent(const std::string &myname, const std::shared_ptr<GameObject> &object,
					    IAudio *sound)
	: Component(myname,
		    object)
{
  this->_audio = sound;
  _playing = false;
}

void TacosEngine::AudioComponent::play(bool loop, int frame)
{
  if (!_playing)
    {
      _playing = true;
      this->_audio->playSound(loop, frame);
    }
}

void TacosEngine::AudioComponent::stop()
{
  if (_playing)
    {
      this->_audio->stop();
      _playing = false;
    }
}
