#include <utility>
#include <GameEngine/Scene/Scene.hpp>

namespace TacosEngine
{
	Component::Component(const std::string &name, std::shared_ptr<GameObject> object) : Entity(name)
	{
		/*if (!object)
            throw std::exception; */
        _object = std::move(object);
	}

	const std::string &Component::getGameObjectName()
	{
		return _object->getInstanceName();
	}

	bool Component::isObjected() const
	{
		if (_object)
			return (true);
		return (false);
	}

	void Component::addGameObject(std::shared_ptr<GameObject> toAdd)
	{
		_object = std::move(toAdd);
	}

	std::shared_ptr<GameObject>	Component::getGameObject()
	{
		return _object;
	}
}