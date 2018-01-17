#include "Input.h"

namespace TacosEngine
{
	Input::Input()
		: axisHorizontal(0.0), axisVertical(0.0)
	{
		for (int i = 0; i < NB_KEY; i++)
		{
			keys[i] = false;
		}
	}

	Input::~Input()
	{

	}

	float	Input::getAxis(const std::string &axis)
	{
		if (axis == "Horizontal")
			return axisHorizontal;
		else if (axis == "Vertical")
			return axisVertical;
		return 0;
	}

	bool	Input::getKey(Key key)
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