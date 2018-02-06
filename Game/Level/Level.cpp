//
// Created by chauvin on 23/01/18.
//

#include "Level.hpp"

Level::~Level()
= default;

const std::shared_ptr<TacosEngine::Scene> &Level::get_scene() const
{
  return _scene;
}

void Level::set_scene(const std::shared_ptr<TacosEngine::Scene> &_scene)
{
  Level::_scene = _scene;
}

std::shared_ptr<TEntity::Entity>
Level::addEntity(const std::string &name, TacosEngine::Layout layout, const std::string &texture,
		 const TacosEngine::Vector2 &size)
{
  auto newEntity = std::make_shared<TEntity::Entity>();

  newEntity->set_name(name);
  newEntity->set_sprite(std::make_shared<TacosEngine::Sprite>(name, this->_scene, layout));
  newEntity->get_sprite()->setTexture(this->_scene->getTexture(texture));
  newEntity->get_sprite()->setSize(size);
  this->_scene->addGameObject(newEntity->get_sprite());
  this->_entities.push_back(newEntity);

  return newEntity;
}

std::shared_ptr<TEntity::Entity> Level::getEntityByName(const std::string &name) const
{
  for (auto &it : _entities)
    {
      if (it->get_name() == name)
	return it;
    }
  return _entities.front();
}

Level::Level(const std::string &name, const std::shared_ptr<TacosEngine::Engine> &engine)
{
  this->_scene = std::make_shared<TacosEngine::Scene>(name);
  engine->addScene(this->_scene);
}

const std::vector<std::shared_ptr<TEntity::Entity>> &Level::get_entities() const
{
  return _entities;
}

void Level::loadComponents()
{
  for (auto &it : _entities)
    {
      it->loadComponents(this->_scene);
    }
}


