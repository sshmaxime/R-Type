//
// Created by chauvin on 28/01/18.
//

#ifndef R_TYPE_EVENTMOVE_HPP
#define R_TYPE_EVENTMOVE_HPP

#include "../IEvent/IEvent.hpp"

namespace TacosEngine
{
  class EventMove : public IEvent
  {
   public:
    EventMove(const std::shared_ptr<GameObject> &obj,const Vector2 &dir);
    ~EventMove() override = default;
    void onEvent() override;

   private:
    std::shared_ptr<GameObject> _object;
    Vector2 _dir;
  };
}

#endif //R_TYPE_EVENTMOVE_HPP
