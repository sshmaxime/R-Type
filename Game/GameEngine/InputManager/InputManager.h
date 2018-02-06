#pragma once

#include <SFML/Window/Keyboard.hpp>
#include "../Input/Input.h"

namespace TacosEngine
{
	class InputManager
	{
	public:
		virtual ~InputManager() = default;

	  virtual void setProcessInput(Input &input) = 0;
	};
}