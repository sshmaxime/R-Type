#pragma once

#include <SFML\Window\Keyboard.hpp>
#include "Input.h"

namespace TacosEngine
{
	class InputManager
	{
	public:
		virtual ~InputManager(){}
		virtual void setProcessInput(Input &input) = 0;
	};
}