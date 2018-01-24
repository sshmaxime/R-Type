//
// Created by chennetier on 21/01/18.
//

#ifndef R_TYPE_IEVENT_HPP
#define R_TYPE_IEVENT_HPP

#include <Sprite>

class IEvent {

public:
    virtual ~IEvent() = default;

    virtual void onEvent(Sprite _sprite) = 0;
};

#endif //R_TYPE_IEVENT_HPP
