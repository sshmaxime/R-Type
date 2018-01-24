//
// Created by chennetier on 23/01/18.
//

#ifndef GAMEENGINE_EVENTMANAGER_HPP
#define GAMEENGINE_EVENTMANAGER_HPP

#include <string>
#include <map>
#include <IEvent/IEvent.hpp>
#include <bits/shared_ptr.h>
#include <../Scene/Scene.hpp>

namespace TacosEngine {

    class EventManager {

    public:
        EventManager();
        ~EventManager() = default;

        void addEvent(std::shared_ptr<IEvent> event, std::string &name);
        void eventUpdate(Scene currentScene);

    private:
        std::map<std::shared_ptr<IEvent>, std::string> _events;
    };
}


#endif //GAMEENGINE_EVENTMANAGER_HPP
