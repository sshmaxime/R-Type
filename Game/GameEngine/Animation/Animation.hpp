//
// Created by chauvin on 22/01/18.
//

#ifndef GAMEENGINE_ANIMATION_HPP
#define GAMEENGINE_ANIMATION_HPP


#include "../Scene/Scene.hpp"

namespace TacosEngine
{
	class Animation : public TacosEngine::Component
	{
	 public:
	  Animation(const std::string &myname, const std::shared_ptr<GameObject> &gameObject, bool loop,
			  int frame_speed, const std::vector<TacosEngine::ITexture*> &frames);
	  ~Animation() override = default;
	  void update(int tick);
	  bool is_loop() const;
	  void set_loop(bool _loop);
	  int get_frame_speed() const;
	  void set_frame_speed(int _frame_speed);
	  const std::vector<TacosEngine::ITexture *> &get_frames() const;
	  void set_frames(const std::vector<TacosEngine::ITexture *> &_frames);
	  int get_frame() const;

	  void set_frame(unsigned int _frame);

	 private:
	  bool	_loop;
	  int	_frame_speed;
		int _check_speed;
	  std::vector<TacosEngine::ITexture*> _frames;
	  unsigned int 	_frame;
	};
}


#endif //GAMEENGINE_ANIMATION_HPP
