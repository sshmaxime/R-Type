//
// Created by chauvin on 22/01/18.
//

#ifndef GAMEENGINE_ANIMATION_HPP
#define GAMEENGINE_ANIMATION_HPP


#include <Scene/Scene.hpp>

class Animation : public TacosEngine::Component
{
 public:
  Animation(const std::string &myname, const std::shared_ptr<TacosEngine::Sprite> &sprite, bool loop,
	      int frame_speed, const std::vector<TacosEngine::ITexture*> &frames);
  ~Animation() override = default;
  void update(int tick);
 private:
  bool	_loop;
  int	_frame_speed;
  std::vector<TacosEngine::ITexture*> _frames;
  unsigned int 	_frame;
};


#endif //GAMEENGINE_ANIMATION_HPP
