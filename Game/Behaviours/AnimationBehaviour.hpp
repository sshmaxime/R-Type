//
// Created by chennetier on 28/01/18.
//

#ifndef R_TYPE_ANIMATIONBEHAVIOUR_HPP
#define R_TYPE_ANIMATIONBEHAVIOUR_HPP


#include "../GameEngine/Behaviour/Behaviour.h"
#include "../GameEngine/Sprite/Sprite.hpp"
#include "../GameEngine/Animation/Animation.hpp"

namespace TacosEngine {
    class AnimationBehaviour : public Behaviour {

    public:
        AnimationBehaviour(const std::string &name, std::shared_ptr<Sprite> sprite)
                : Behaviour(name, std::move(sprite))
        {

        }

        ~AnimationBehaviour() override = default;

        void Start() override
        {
            anim = getComponent<Animation>();
        }

        void update(const Input &input) override {

            anim = getComponent<Animation>();
            if (!anim->isActive())
            {
                this->setDestroy(true);
            }
        }

    private:
        std::shared_ptr<Animation> anim;
    };

}

#endif //R_TYPE_ANIMATIONBEHAVIOUR_HPP
