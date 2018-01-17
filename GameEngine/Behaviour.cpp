#include "Behaviour.h"

namespace TacosEngine
{
	Behaviour::Behaviour(const std::string &name, std::shared_ptr<Sprite> sprite)
		: Component(name, sprite)
	{

	}

	Behaviour::~Behaviour()
	{

	}

	void	Behaviour::update(const Input &input)
	{

	}

	void	Behaviour::onCollide(Sprite &other)
	{

	}
}