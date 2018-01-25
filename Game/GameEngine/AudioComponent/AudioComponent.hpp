//
// Created by chauvin on 23/01/18.
//

#ifndef GAMEENGINE_AUDIOCOMPONENT_HPP
#define GAMEENGINE_AUDIOCOMPONENT_HPP

#include "../Scene/Scene.hpp"

namespace TacosEngine
{
  class AudioComponent : public Component
  {
   public:
    AudioComponent(const std::string &myname, const std::shared_ptr<GameObject> &object, IAudio *sound);

    ~AudioComponent() override = default;

    void play(bool loop, int frame);

    void stop();

   private:
    IAudio *_audio;
    bool _playing;
  };
}

#endif //GAMEENGINE_AUDIOCOMPONENT_HPP
