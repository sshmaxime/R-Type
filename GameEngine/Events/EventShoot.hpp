//
// Created by chennetier on 23/01/18.
//

#ifndef GAMEENGINE_EVENTSHOOT_HPP
#define GAMEENGINE_EVENTSHOOT_HPP

#include <IEvent/IEvent.hpp>
#include <string>

namespace rtype {

    class EventShoot : public IEvent {

    public:
        ~EventShoot() override = default;

        explicit EventShoot(std::string &packet);

        void    onEvent() override;

    private:
        std::string _packet;
    };

}

#endif //GAMEENGINE_EVENTSHOOT_HPP
