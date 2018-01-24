#include "Behaviour.h"

namespace TacosEngine
{
	Behaviour::Behaviour(const std::string &name, std::shared_ptr<GameObject> object)
		: Component(name, std::move(object)), start(false), destroy(false)
	{

	}

	Behaviour::~Behaviour()
	= default;

	void	Behaviour::Start()
	{

	}

	void	Behaviour::update(const Input &input)
	{

	}

	void	Behaviour::onCollide(GameObject &other)
	{

	}

	void	Behaviour::setDestroy(bool des)
	{
		destroy = des;
	}

	bool	Behaviour::isStarted() const
	{
		return start;
	}

	void	Behaviour::setStart(bool start)
	{
		this->start = start;
	}

	bool	Behaviour::toDestroy() const
	{
		return destroy;
	}
}