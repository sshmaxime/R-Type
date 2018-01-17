#pragma once

#include "InputManager.h"

namespace TacosEngine
{
	class InputManagerSFML : public InputManager
	{
	public:
		InputManagerSFML();
		virtual ~InputManagerSFML();
		virtual void setProcessInput(Input &input);
	};
}