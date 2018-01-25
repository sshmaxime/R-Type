//
// Created by Corentin on 24/01/2018.
//

#include <utility>
#include "../Scene/Scene.hpp"


namespace TacosEngine
{
    GameObject::GameObject(const std::string &name, std::shared_ptr<Scene> scene, Layout layout, Tag tag)
            : Entity(name), _transform(), _tag(tag)
    {
        _layout = layout;
       /* if (!scene)
            throw std::exception; */
        _scene = std::move(scene);
    }

    std::shared_ptr<Scene>  GameObject::getScene() const
    {
        return _scene;
    }

    void  GameObject::setLayout(Layout layout)
    {
        _layout = layout;
    }

    const Layout &GameObject::getLayout() const
    {
        return _layout;
    }


    Tag &GameObject::getTag()
    {
        return _tag;
    }

    void GameObject::setTag(Tag tag)
    {
        _tag = tag;
    }

    bool		GameObject::operator<(const GameObject &j)
    {
        return (static_cast<int>(this->getLayout()) < static_cast<int>(j.getLayout()));
    }

    Transform	&GameObject::getTransform()
    {
        return _transform;
    }

    std::shared_ptr<GameObject> GameObject::findByName(const std::string &name)
    {
        return _scene->findByName(name);
    }

    std::shared_ptr<GameObject> GameObject::findByTag(Tag tag)
    {
        return _scene->findByTag(tag);
    }

    std::list<std::shared_ptr<GameObject>>  GameObject::findGameObjetcsByTag(Tag tag)
    {
        return _scene->findGameObjetcsByTag(tag);
    }
}