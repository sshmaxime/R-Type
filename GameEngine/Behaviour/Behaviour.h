#pragma once

#include "Component.hpp"
#include "Input.h"

namespace TacosEngine
{
	class Behaviour : public Component
	{
		Behaviour(const std::string &name, std::shared_ptr<Sprite> sprite);
		~Behaviour();
		virtual void update(const Input &input);
		virtual void onCollide(Sprite &other);
	};
}