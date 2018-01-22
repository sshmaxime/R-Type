#include <Sprite/Sprite.hpp>

namespace TacosEngine
{
	Component::Component(const std::string &myname, std::shared_ptr<Sprite> sprite) : Entity(myname)
	{
		if (sprite)
			_sprite = sprite;
	}

	const std::string &Component::getSpriteName()
	{
		return _sprite->getInstanceName();
	}

	bool Component::isSprited()
	{
		if (_sprite)
			return (true);
		return (false);
	}

	void Component::addSprite(std::shared_ptr<Sprite> toAdd)
	{
		_sprite = std::move(toAdd);
	}

	std::shared_ptr<Sprite>	Component::getSprite()
	{
		return _sprite;
	}
}