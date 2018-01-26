#include "Input.h"

namespace TacosEngine
{
	Input::Input()
		: axisHorizontal(0.0), axisVertical(0.0)
	{
		for (bool &key : keys) {
			key = false;
		}
	}

	Input::~Input()
	= default;

	float	Input::getAxis(const std::string &axis)const {
		if (axis == "Horizontal")
			return axisHorizontal;
		else if (axis == "Vertical")
			return axisVertical;
		return 0;
	}

  bool Input::getKey(Key key) const
	{
		return keys[static_cast<int>(key)];
	}

	void	Input::setKey(Key key, bool state)
	{
		keys[static_cast<int>(key)] = state;
	}

	void	Input::setAxis(float value, const std::string &axis)
	{
		if (axis == "Horizontal")
			axisHorizontal = value;
		else if (axis == "Vertical")
			axisVertical = value;
	}
}