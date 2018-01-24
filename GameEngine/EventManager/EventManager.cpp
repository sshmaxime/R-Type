//
// Created by chennetier on 23/01/18.
//

#include "EventManager.hpp"

namespace TacosEngine {

    EventManager::EventManager() = default;

    void EventManager::addEvent(std::shared_ptr<IEvent> event, std::string &name) {

        this->_events.insert(std::pair<std::shared_ptr<IEvent>, std::string>(event, name));
    }

    void EventManager::eventUpdate(Scene currentScene) {


        /*for (auto &_event : _events) {
            _event.first->onEvent(currentScene->getEntityByName(_event.second));
        }
        _events.clear();*/
    }
}