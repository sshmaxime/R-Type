#include "InputManagerSFML.h"

namespace TacosEngine
{
	InputManagerSFML::InputManagerSFML()
	= default;

	InputManagerSFML::~InputManagerSFML()
	= default;


	void	InputManagerSFML::setProcessInput(Input &input)
	{
		float	axisHor = 0.0f;
		float	axisVer = 0.0f;

		// Num
		input.setKey(TacosEngine::Key::KEY_0, sf::Keyboard::isKeyPressed(sf::Keyboard::Num0));
		input.setKey(TacosEngine::Key::KEY_1, sf::Keyboard::isKeyPressed(sf::Keyboard::Num1));
		input.setKey(TacosEngine::Key::KEY_2, sf::Keyboard::isKeyPressed(sf::Keyboard::Num2));
		input.setKey(TacosEngine::Key::KEY_3, sf::Keyboard::isKeyPressed(sf::Keyboard::Num3));
		input.setKey(TacosEngine::Key::KEY_4, sf::Keyboard::isKeyPressed(sf::Keyboard::Num4));
		input.setKey(TacosEngine::Key::KEY_5, sf::Keyboard::isKeyPressed(sf::Keyboard::Num5));
		input.setKey(TacosEngine::Key::KEY_6, sf::Keyboard::isKeyPressed(sf::Keyboard::Num6));
		input.setKey(TacosEngine::Key::KEY_7, sf::Keyboard::isKeyPressed(sf::Keyboard::Num7));
		input.setKey(TacosEngine::Key::KEY_8, sf::Keyboard::isKeyPressed(sf::Keyboard::Num8));
		input.setKey(TacosEngine::Key::KEY_9, sf::Keyboard::isKeyPressed(sf::Keyboard::Num9));

		// Alph
		input.setKey(TacosEngine::Key::KEY_A, sf::Keyboard::isKeyPressed(sf::Keyboard::A));
		input.setKey(TacosEngine::Key::KEY_B, sf::Keyboard::isKeyPressed(sf::Keyboard::B));
		input.setKey(TacosEngine::Key::KEY_C, sf::Keyboard::isKeyPressed(sf::Keyboard::C));
		input.setKey(TacosEngine::Key::KEY_D, sf::Keyboard::isKeyPressed(sf::Keyboard::D));
		input.setKey(TacosEngine::Key::KEY_E, sf::Keyboard::isKeyPressed(sf::Keyboard::E));
		input.setKey(TacosEngine::Key::KEY_F, sf::Keyboard::isKeyPressed(sf::Keyboard::F));
		input.setKey(TacosEngine::Key::KEY_G, sf::Keyboard::isKeyPressed(sf::Keyboard::G));
		input.setKey(TacosEngine::Key::KEY_H, sf::Keyboard::isKeyPressed(sf::Keyboard::H));
		input.setKey(TacosEngine::Key::KEY_I, sf::Keyboard::isKeyPressed(sf::Keyboard::I));
		input.setKey(TacosEngine::Key::KEY_J, sf::Keyboard::isKeyPressed(sf::Keyboard::J));
		input.setKey(TacosEngine::Key::KEY_K, sf::Keyboard::isKeyPressed(sf::Keyboard::K));
		input.setKey(TacosEngine::Key::KEY_L, sf::Keyboard::isKeyPressed(sf::Keyboard::L));
		input.setKey(TacosEngine::Key::KEY_M, sf::Keyboard::isKeyPressed(sf::Keyboard::M));
		input.setKey(TacosEngine::Key::KEY_N, sf::Keyboard::isKeyPressed(sf::Keyboard::N));
		input.setKey(TacosEngine::Key::KEY_O, sf::Keyboard::isKeyPressed(sf::Keyboard::O));
		input.setKey(TacosEngine::Key::KEY_P, sf::Keyboard::isKeyPressed(sf::Keyboard::P));
		input.setKey(TacosEngine::Key::KEY_Q, sf::Keyboard::isKeyPressed(sf::Keyboard::Q));
		input.setKey(TacosEngine::Key::KEY_R, sf::Keyboard::isKeyPressed(sf::Keyboard::R));
		input.setKey(TacosEngine::Key::KEY_S, sf::Keyboard::isKeyPressed(sf::Keyboard::S));
		input.setKey(TacosEngine::Key::KEY_T, sf::Keyboard::isKeyPressed(sf::Keyboard::T));
		input.setKey(TacosEngine::Key::KEY_U, sf::Keyboard::isKeyPressed(sf::Keyboard::U));
		input.setKey(TacosEngine::Key::KEY_V, sf::Keyboard::isKeyPressed(sf::Keyboard::V));
		input.setKey(TacosEngine::Key::KEY_W, sf::Keyboard::isKeyPressed(sf::Keyboard::W));
		input.setKey(TacosEngine::Key::KEY_X, sf::Keyboard::isKeyPressed(sf::Keyboard::X));
		input.setKey(TacosEngine::Key::KEY_Y, sf::Keyboard::isKeyPressed(sf::Keyboard::Y));
		input.setKey(TacosEngine::Key::KEY_Z, sf::Keyboard::isKeyPressed(sf::Keyboard::Z));

		// Touch
		input.setKey(TacosEngine::Key::KEY_SPACE, sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
		input.setKey(TacosEngine::Key::KEY_ENTER, sf::Keyboard::isKeyPressed(sf::Keyboard::Return));
		input.setKey(TacosEngine::Key::KEY_ESCAPE, sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));

		// Dir
		input.setKey(TacosEngine::Key::KEY_UP, sf::Keyboard::isKeyPressed(sf::Keyboard::Up));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			axisVer -= 1;
		input.setKey(TacosEngine::Key::KEY_DOWN, sf::Keyboard::isKeyPressed(sf::Keyboard::Down));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			axisVer += 1;
		input.setKey(TacosEngine::Key::KEY_RIGHT, sf::Keyboard::isKeyPressed(sf::Keyboard::Right));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			axisHor += 1;
		input.setKey(TacosEngine::Key::KEY_LEFT, sf::Keyboard::isKeyPressed(sf::Keyboard::Left));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			axisHor -= 1;
		input.setAxis(axisHor, "Horizontal");
		input.setAxis(axisVer, "Vertical");
	}
}