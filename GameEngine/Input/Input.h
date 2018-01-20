#pragma once

#include <string>

namespace TacosEngine
{
	enum class Key : int
	{
		KEY_0 = 0,
		KEY_1,
		KEY_2,
		KEY_3,
		KEY_4,
		KEY_5,
		KEY_6,
		KEY_7,
		KEY_8,
		KEY_9,
		KEY_A,
		KEY_B,
		KEY_C,
		KEY_D,
		KEY_E,
		KEY_F,
		KEY_G,
		KEY_H,
		KEY_I,
		KEY_J,
		KEY_K,
		KEY_L,
		KEY_M,
		KEY_N,
		KEY_O,
		KEY_P,
		KEY_Q,
		KEY_R,
		KEY_S,
		KEY_T,
		KEY_U,
		KEY_V,
		KEY_W,
		KEY_X,
		KEY_Y,
		KEY_Z,
		KEY_UP,
		KEY_DOWN,
		KEY_LEFT,
		KEY_RIGHT,
		KEY_ENTER,
		KEY_SPACE,
		END
	};

	class Input
	{
		static const int NB_KEY = 42;
		bool								keys[NB_KEY];
		float								axisVertical;
		float								axisHorizontal;
	public:
		Input();
		~Input();
		float		getAxis(const std::string &axis);
		bool		getKey(Key key);
		void		setKey(Key, bool);
		void		setAxis(float, const std::string &axis);
	};
}