//
// Created by chennetier on 21/01/18.
//

#ifndef R_TYPE_IEVENT_HPP
#define R_TYPE_IEVENT_HPP

class IEvent {

public:
    virtual ~IEvent() = default;

    virtual void onEvent() = 0;
};

#endif //R_TYPE_IEVENT_HPP
