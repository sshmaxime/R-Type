#pragma once

#include <memory>
#include <list>
#include <queue>
#include "../Entity/Entity.hpp"
#include "../Transform/Transform.h"
#include "../RessourceManager/RessourceManager.hpp"
#include "../../../Common/JSON/JSONObject.h"

namespace TacosEngine
{
    // Fix : inclusion multiple
    class Scene;

    enum class Layout : int
    {
        UNKNOWN = -1,
        BACKGROUND = 0,
        SCENE = 1,
        UI = 2,
    };

    enum class Tag : int
    {
        UNKNOWN = -1,
        PLAYER = 0,
        BACKGROUND = 1,
    };


  class GameObject : public Entity
    {
    public:
        GameObject(const std::string &name, std::shared_ptr<Scene> scene, Layout layout, Tag tag = Tag::UNKNOWN);
        ~GameObject() override = default;
        std::shared_ptr<Scene>  getScene() const;

        template<typename T>
        std::shared_ptr<T> getComponent();

        const Layout      &getLayout() const;
        void        setLayout(Layout layout);
        Transform	&getTransform();
        Tag         &getTag();
        void        setTag(Tag);
        std::shared_ptr<GameObject> findByName(const std::string &);
        std::shared_ptr<GameObject> findByTag(Tag tag);
        std::list<std::shared_ptr<GameObject>>  findGameObjetcsByTag(Tag tag);
        bool		operator<(const GameObject &);
        void    setActive(bool);
        bool    isActive() const;


    protected:
        Transform                   _transform;
        Tag                         _tag;
        Layout                      _layout;
        std::shared_ptr<Scene>      _scene;
        bool                        _isActive;
    };


    class Component : public Entity
    {
    public:
        Component(const std::string &name, std::shared_ptr<GameObject> object);
        ~Component() override = default;
        Component(const Component &) = default;
        std::shared_ptr<GameObject> getGameObject();
        void addGameObject(std::shared_ptr<GameObject> toAdd);
        const std::string &getGameObjectName();
        bool  isObjected() const;
        void    setActive(bool);
        bool    isActive() const;

        template <typename T>
        std::shared_ptr<T> getComponent();

    protected:
        std::shared_ptr<GameObject> _object;
        bool                        _isActive;
    };

    class Scene
    {
    private:
        std::list<std::shared_ptr<GameObject>> _objects;
        std::list<std::shared_ptr<Component>> _components;
        //std::list<std::shared_ptr<IEvent> _events;
        std::string _name;
        std::shared_ptr<RessourceManager>	_ressources;
        bool    _newScene;
        std::string _newSceneName;
        Vector2                     _windowSize;
      	std::shared_ptr<std::queue<JSONObject*>> _send;
      bool _end;

    public:
        explicit Scene(const std::string &myname);
        virtual ~Scene();
        void addGameObject(std::shared_ptr<GameObject> toAdd);
        void addComponent(std::shared_ptr<Component> toAdd);
        void setRessources(std::shared_ptr<RessourceManager> ress);
        ITexture *getTexture(const std::string &name);
        IFont *getFont(const std::string &name);
        IAudio *getAudio(const std::string &name);

      std::list<std::shared_ptr<GameObject>> &getGameObjects();

      std::list<std::shared_ptr<Component>> &getComponents();
        std::shared_ptr<GameObject> getGameObject(unsigned int id);
        void    startObjects();
        void    destroyObjects();
        std::shared_ptr<GameObject> findByName(const std::string &);
        std::shared_ptr<GameObject> findByTag(Tag tag);
        std::list<std::shared_ptr<GameObject>>  findGameObjetcsByTag(Tag tag);
        bool        isNewScene() const;
        void        loadNewScene(const std::string &name);
        const std::string   &getName() const;
        const std::string   &getNewSceneName() const;
        void    setWindowSize(const Vector2 &);
        const Vector2 &getWindowSize() const;

        template <typename T>
        std::shared_ptr<T> getComponent(unsigned int id);

      bool is_end() const;

      void set_end(bool _end);

      const std::shared_ptr<std::queue<JSONObject *>> &get_send() const;
    };
}

template <typename T>
std::shared_ptr<T> TacosEngine::Scene::getComponent(unsigned int id)
{
    for (auto it : _components)
    {
        if ((it)->getGameObject()->getInstanceId() == id && dynamic_cast<T *>(it.get()))
        {
            return std::dynamic_pointer_cast<T>(it);
        }
    }
    return (NULL);
}

template <typename T>
std::shared_ptr<T> TacosEngine::Component::getComponent()
{
    return _object->getComponent<T>();
}

template<typename T>
std::shared_ptr<T> TacosEngine::GameObject::getComponent()
{
    return (_scene->getComponent<T>(_id));
}
