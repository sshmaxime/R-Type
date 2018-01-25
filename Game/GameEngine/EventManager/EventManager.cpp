//
// Created by chennetier on 23/01/18.
//

#include "EventManager.hpp"

namespace TacosEngine
{
  void EventManager::addEvent(std::shared_ptr<IEvent> event, std::string &name)
  {
    this->_events.insert(std::pair<std::shared_ptr<IEvent>, std::string>(event, name));
  }

  void EventManager::eventUpdate(std::shared_ptr<Scene> currentScene)
  {
    for (auto &_event : _events)
      {
	_event.first->onEvent(currentScene->findByName(_event.second));
      }
    _events.clear();

  }
}