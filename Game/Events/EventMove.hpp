//
// Created by chauvin on 27/01/18.
//

#ifndef R_TYPE_EVENTMOVE_HPP
#define R_TYPE_EVENTMOVE_HPP


#include "../GameEngine/IEvent/IEvent.hpp"
#include "../../Common/JSON/JSONObject.h"

namespace TacosEngine
{
  class EventMove_in : public IEvent
  {
    EventMove_in(JSONObject &obj);
    ~EventMove_in();
    void onEvent(std::shared_ptr<GameObject> obj) override;
  };

  class EventMove_out : public IEvent
  {
    EventMove_out(JSONObject &obj);
    ~EventMove_out();
    void onEvent(std::shared_ptr<GameObject> obj) override;
  };
}

#endif //R_TYPE_EVENTMOVE_HPP
