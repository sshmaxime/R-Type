#pragma once

#include <memory>
#include <list>
#include "../RessourceManager/RessourceManager.hpp"
#include "../Sprite/Sprite.hpp"
#include "../Component/Component.hpp"

namespace TacosEngine
{
	// Fix : inclusion multiple
	class Sprite;
	class Component;

	class Scene
	{
	private:
		std::list<std::shared_ptr<Sprite>> _sprites;
		std::list<std::shared_ptr<Component>> _components;
		std::string _name;
		std::shared_ptr<RessourceManager>	_ressources;

	  public:
		Scene(const std::string &myname);
		virtual ~Scene();
		void addSprite(std::shared_ptr<Sprite> toAdd);
		void addComponent(std::shared_ptr<Component> toAdd);
		void setRessources(std::shared_ptr<RessourceManager> ress);
		
		ITexture *getTexture(const std::string &name)
		{
			return _ressources->getTexture(name);
		}

		std::list<std::shared_ptr<Sprite>>	getSprites();

		std::shared_ptr<Sprite> getSprite(unsigned int id);
		std::list<std::shared_ptr<Component>> &getComponentList(unsigned int id);
		
		template <typename T>
		std::shared_ptr<T> getComponent(unsigned int id)
		{
			/*for (auto it = this->_components.begin(); it != _components.end(); it++)
			{
				if ((*it)->getSprite()->getInstanceId() == id && dynamic_cast<T *>(*it))
				  return *it;
			}*/
			return (NULL);
		};

		size_t getNSprite();
		size_t getNComponent();
		void displaySprites();
		void displayComponents();
	};
}