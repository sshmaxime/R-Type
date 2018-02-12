//
// Created by chauvin on 12/02/18.
//

#ifndef R_TYPE_EVENTADDPLAYER_HPP
#define R_TYPE_EVENTADDPLAYER_HPP


#include "../GameEngine/IEvent/IEvent.hpp"

namespace TacosEngine
{
  class EventAddPlayer : public IEvent
  {
   public:
    EventAddPlayer(std::shared_ptr<Scene> &scene, const std::string &name, int number, bool active);

    ~EventMove() override = default;

    void onEvent() override;

   private:
    std::shared_ptr<Scene> _scene;
    std::string _name;
    int _nb;
    bool _active;
  };
}


#endif //R_TYPE_EVENTADDPLAYER_HPP
