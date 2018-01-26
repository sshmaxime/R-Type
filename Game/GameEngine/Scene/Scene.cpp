
#include "Scene.hpp"
#include "../Behaviour/Behaviour.h"

namespace TacosEngine
{
	Scene::Scene(const std::string &myname)
		: _name(myname), _newScene(false), _newSceneName("")
	{
	}

	Scene::~Scene()
	= default;

	void Scene::addGameObject(std::shared_ptr<GameObject> toAdd)
	{
		_objects.push_back(toAdd);
	}

	void	Scene::setRessources(std::shared_ptr<RessourceManager> res)
	{
		this->_ressources = std::move(res);
	}



	void Scene::addComponent(std::shared_ptr<Component> toAdd)   
	{
		_components.push_back(toAdd);
	}

	std::shared_ptr<GameObject> Scene::getGameObject(unsigned int id)
	{
		std::list<std::shared_ptr<GameObject>>::iterator it;
		for (it = _objects.begin(); it != _objects.end(); it++)
		{
			if ((*it)->getInstanceId() == id)
				return (*it);
		}
		return (nullptr);
	}

	std::list<std::shared_ptr<GameObject>>	Scene::getGameObjects()
	{
		return _objects;
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

    void    Scene::startObjects()
    {
        for (auto &compo : _components)
        {
            std::shared_ptr<Behaviour> b = std::dynamic_pointer_cast<Behaviour>(compo);
            if (b && b->isActive() && !b->isStarted())
            {
                b->Start();
                b->setStart(true);
            }
        }
    }

    void    Scene::destroyObjects()
    {
        auto compo = _components.begin();
        while (compo != _components.end())
        {
            std::shared_ptr<Behaviour> b = std::dynamic_pointer_cast<Behaviour>(*compo);
            if (b && b->isActive() && b->toDestroy())
            {
               std::shared_ptr<GameObject>  obj = b->getGameObject();

                auto it = _components.begin();
                while (it != _components.end())
                {
                    if ((*it)->getGameObject() == obj)
                    {
                        it = _components.erase(it);
                    }
                    else
                        it++;
                }
                _objects.remove(obj);
                compo = _components.begin();
            }
            else
            {
                compo++;
            }
        }
    }

    std::shared_ptr<GameObject> Scene::findByName(const std::string &name)
    {
        for (auto &gameObject : _objects)
        {
            if (gameObject->getInstanceName() == name)
                return gameObject;
        }
        return nullptr;
    }

    std::shared_ptr<GameObject> Scene::findByTag(Tag tag)
    {
        for (auto &gameObject : _objects)
        {
            if (gameObject->getTag() == tag)
                return gameObject;
        }
        return nullptr;
    }

    std::list<std::shared_ptr<GameObject>>  Scene::findGameObjetcsByTag(Tag tag)
    {
        std::list<std::shared_ptr<GameObject>>  gameObjects;

        for (auto &gameObject : _objects)
        {
            if (gameObject->getTag() == tag)
                gameObjects.push_back(gameObject);
        }
        return gameObjects;
    }

    bool        Scene::isNewScene() const
    {
        return _newScene;
    }

    void        Scene::loadNewScene(const std::string &name)
    {
        _newScene = true;
        _newSceneName = name;
    }

    const std::string   &Scene::getName() const
    {
        return _name;
    }

    const std::string   &Scene::getNewSceneName() const
    {
        return _newSceneName;
    }

    void    Scene::setWindowSize(const Vector2 &size)
    {

    }

    const Vector2 &Scene::getWindowSize() const
    {
        return _windowSize;
    }
}