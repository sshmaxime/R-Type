#pragma once

#include <memory>
#include <list>
#include <Entity/Entity.hpp>
#include <Transform/Transform.h>
#include "../RessourceManager/RessourceManager.hpp"

namespace TacosEngine
{
  // Fix : inclusion multiple
  class Sprite;
  class Component;
  class Scene;

  class Sprite : public Entity
  {
   public:
    Sprite(const std::string &myname, std::shared_ptr<Scene> scene);

    ~Sprite() override
    = default;
    void setScene(std::shared_ptr<Scene> scene);

    template<typename T>
    std::shared_ptr<T> getComponent();

    std::list<std::shared_ptr<Component>> getComponentList();

    void setTexture(ITexture *text)
    {
      _texture = text;
    }

    void	*getTexture()
    {
      return _texture->getTexture();
    }

    Transform	getTransform()
    {
      return _transform;
    }

    void 		addTexture(ITexture *texture)
    {
      this->_texture = texture;
    }


   private:
    Transform                   _transform;
    //      Tag                         _tag;
    ITexture					*_texture;
    //      Layout                      _layout;
    std::shared_ptr<Scene>      _scene;
  };

  class Component : public Entity
  {
   public:
    Component(const std::string &myname, std::shared_ptr<Sprite> sprite);
    ~Component() override = default;
    std::shared_ptr<Sprite> getSprite();
    void addSprite(std::shared_ptr<Sprite> toAdd);
    const std::string &getSpriteName();
    bool  isSprited();

    template <typename T>
    std::shared_ptr<T> getComponent();

   protected:
    std::shared_ptr<Sprite> _sprite;
  };

  class Scene
  {
   private:
    std::list<std::shared_ptr<Sprite>> _sprites;
    std::list<std::shared_ptr<Component>> _components;
    //std::list<std::shared_ptr<IEvent> _events;
    std::string _name;
    std::shared_ptr<RessourceManager>	_ressources;

   public:
    explicit Scene(const std::string &myname);
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
    std::shared_ptr<T> getComponent(unsigned int id);

    size_t getNSprite();
    size_t getNComponent();
    void displaySprites();
    void displayComponents();
  };
}

template <typename T>
std::shared_ptr<T> TacosEngine::Scene::getComponent(unsigned int id)
{
  for (auto it : _components)
    {
      if ((it)->getSprite()->getInstanceId() == id && dynamic_cast<T *>(it))
	return it;
    }
  return (NULL);
};

template <typename T>
std::shared_ptr<T> TacosEngine::Component::getComponent()
{
  return _sprite->getComponent<T>();
}

template<typename T>
std::shared_ptr<T> TacosEngine::Sprite::getComponent()
{
  return (_scene->getComponent<T>(_id));
}