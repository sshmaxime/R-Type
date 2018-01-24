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
}

void TacosEngine::AudioComponent::play(bool loop, int frame)
{
  this->_audio->playSound(loop, frame);
}

void TacosEngine::AudioComponent::stop()
{
  this->_audio->stop();
}
