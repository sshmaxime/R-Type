//
// Created by simon on 26/01/18.
//

#ifndef GAME_MONSTERBEHAVIOUR_H
#define GAME_MONSTERBEHAVIOUR_H


#include "../GameEngine/Behaviour/Behaviour.h"
#include "../GameEngine/Sprite/Sprite.hpp"
#include "MonsterIA.h"

namespace TacosEngine {
    class MonsterBehaviour : public Behaviour
    {
    public:
        MonsterBehaviour(const std::string &name, std::shared_ptr<Sprite> sprite, MonsterIa *ia)
                : Behaviour(name, std::move(sprite))
        {
            can_shoot = 0;
            tick_per_shoot = 100;
            _ia = ia;
            _health = 40;
            _maxHealth = 40;
            _damages = 10;
        }

        ~MonsterBehaviour() override = default;

        void Start() override
        {}

        void update(const Input &) override;

        void shoot();

        void onCollide(GameObject &other) override;

    private:
        int can_shoot;
        int tick_per_shoot;
        int _health;
        int _maxHealth;
        int _damages;
        MonsterIa *_ia;
    };
}

#endif //GAME_MONSTERBEHAVIOUR_H
