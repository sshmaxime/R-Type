#pragma once

#include <Scene/Scene.hpp>
#include "../Input/Input.h"

namespace TacosEngine
{
	class Behaviour : public Component
	{
	public:
		Behaviour(const std::string &name, std::shared_ptr<Sprite> sprite);
		~Behaviour();
		virtual void update(const Input &input);
		virtual void onCollide(Sprite &other);
	};
}