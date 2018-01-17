#include "Scene.hpp"

namespace TacosEngine
{
	Scene::Scene(const std::string &myname)
		: _name(myname)
	{
	}

	Scene::~Scene()
	{
	}

	void Scene::addSprite(std::shared_ptr<Sprite> toAdd)
	{
		_sprites.push_back(toAdd);
	}

	void	Scene::setRessources(std::shared_ptr<RessourceManager> res)
	{
		this->_ressources = res;
	}



	void Scene::addComponent(std::shared_ptr<Component> toAdd)   
	{
		_components.push_back(toAdd);
	}

	std::shared_ptr<Sprite> Scene::getSprite(unsigned int id)
	{
		std::list<std::shared_ptr<Sprite>>::iterator it;
		for (it = _sprites.begin(); it != _sprites.end(); it++)
		{
			if ((*it)->getInstanceId() == id)
				return (*it);
		}
		return (NULL);
	}

	size_t Scene::getNSprite()
	{
		return (this->_sprites.size());
	}

	size_t Scene::getNComponent()
	{
		return (this->_components.size());
	}

	void Scene::displayComponents()
	{
		for (auto it = _components.begin(); it != _components.end(); it++)
		{
			std::cout << "Component n°" << (*it)->getInstanceId() << " with the name:"
					  << (*it)->getInstanceName();
			try
			{
				auto test = dynamic_cast<Component *>(it->get());

				if (test->isSprited())
					std::cout << " which contains:" << test->getSpriteName() << std::endl;
				else
					std::cout << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << "who is not comp: " << e.what() << std::endl;
			}
		}
	}

	void Scene::displaySprites()
	{
		std::list<std::shared_ptr<Sprite>>::iterator it;
		for (it = _sprites.begin(); it != _sprites.end(); it++)
		{
			std::cout << "Sprite n°" << (*it)->getInstanceId() << " with the name:"
					  << (*it)->getInstanceName() << std::endl;
		}
	}

	std::list<std::shared_ptr<Component>> &Scene::getComponentList(unsigned int id)
	{
	/*    std::list<std::shared_ptr<Component>> toRet = std::list<std::shared_ptr<Component>>();
		for (auto it = this->_components.begin(); it != _components.end(); it++)
		{
			if ((*it)->getInstanceId() == id)
			{
				auto test = dynamic_cast<std::shared_ptr<Component>>(it->get());
				toRet.push_back(test);
	//            toRet.push_back(dynamic_cast<std::shared_ptr<Component*>>((*it));
	//            toRet.push_back(it->get());
			}
		}
		return toRet;*/
	}

	std::list<std::shared_ptr<Sprite>>	Scene::getSprites()
	{
		return _sprites;
	}
}