//
// Created by chennetier on 21/01/18.
//

#ifndef R_TYPE_IEVENT_HPP
#define R_TYPE_IEVENT_HPP

#include "../Scene/Scene.hpp"

namespace TacosEngine {

    class IEvent {

    public:
        virtual ~IEvent() = default;

        virtual void onEvent(std::shared_ptr<GameObject> obj) = 0;
    };
}

#endif //R_TYPE_IEVENT_HPP
