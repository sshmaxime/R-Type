//
// Created by chennetier on 23/01/18.
//

#ifndef GAMEENGINE_EVENTMOVE_HPP
#define GAMEENGINE_EVENTMOVE_HPP

#include <IEvent/IEvent.hpp>
#include <string>

namespace rtype {

    class EventMove : public IEvent {

    public:
        ~EventMove() override = default;

        explicit EventMove(std::string &packet);

        void    onEvent() override;

    private:
        std::string _packet;
    };

}

#endif //GAMEENGINE_EVENTMOVE_HPP
