//
// Created by chauvin on 28/01/18.
//

#ifndef R_TYPE_EVENTSHOOT_HPP
#define R_TYPE_EVENTSHOOT_HPP

#include "../GameEngine/IEvent/IEvent.hpp"

namespace TacosEngine
{
  class EventShoot : public IEvent
  {
   public:
    explicit EventShoot(const std::shared_ptr<GameObject> &obj);
    ~EventShoot() override = default;
    void onEvent() override;

   private:
    std::shared_ptr<GameObject> _object;
  };
}

#endif //R_TYPE_EVENTSHOOT_HPP
