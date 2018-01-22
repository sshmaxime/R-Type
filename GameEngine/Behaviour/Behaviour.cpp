#include "Behaviour.h"

namespace TacosEngine
{
	Behaviour::Behaviour(const std::string &name, std::shared_ptr<Sprite> sprite)
		: Component(name, std::move(sprite))
	{

	}

	Behaviour::~Behaviour()
	= default;

	void	Behaviour::update(const Input &input)
	{

	}

	void	Behaviour::onCollide(Sprite &other)
	{

	}
}