//
// Created by chennetier on 23/01/18.
//

#ifndef GAMEENGINE_EVENTMANAGER_HPP
#define GAMEENGINE_EVENTMANAGER_HPP

#include <string>
#include <map>
#include <memory>
#include <GameEngine/IEvent/IEvent.hpp>

namespace TacosEngine
{
  class EventManager
  {
   public:
    EventManager() = default;

    ~EventManager() = default;

    void addEvent(std::shared_ptr<IEvent> event, std::string &name);

    void eventUpdate(std::shared_ptr<Scene> currentScene);

   private:
    std::map<std::shared_ptr<IEvent>, std::string> _events;
  };
}


#endif //GAMEENGINE_EVENTMANAGER_HPP
