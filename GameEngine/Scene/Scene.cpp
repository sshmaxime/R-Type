#include "Scene.hpp"

namespace TacosEngine
{
  Scene::Scene(const std::string &myname)
	  : _name(myname)
  {
  }

  Scene::~Scene()
  = default;

  void Scene::addSprite(std::shared_ptr<Sprite> toAdd)
  {
    _sprites.push_back(toAdd);
  }

  void	Scene::setRessources(std::shared_ptr<RessourceManager> res)
  {
    this->_ressources = std::move(res);
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
    return (nullptr);
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
	    auto test = it->get();

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

  std::list<std::shared_ptr<Sprite>>	Scene::getSprites()
  {
    return _sprites;
  }

  std::list<std::shared_ptr<Component>>	Scene::getComponents()
  {
    return _components;
  }

  ITexture *Scene::getTexture(const std::string &name)
  {
    return _ressources->getTexture(name);
  }

  IFont *Scene::getFont(const std::string &name)
  {
    return _ressources->getFont(name);
  }

  IAudio *Scene::getAudio(const std::string &name)
  {
    return _ressources->getAudio(name);
  }
}