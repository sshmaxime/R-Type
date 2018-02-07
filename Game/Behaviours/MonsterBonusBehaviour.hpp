//
// Created by chennetier on 28/01/18.
//

#ifndef R_TYPE_MONSTERBONUSBEHAVIOUR_HPP
#define R_TYPE_MONSTERBONUSBEHAVIOUR_HPP

#include <random>
#include "../GameEngine/Behaviour/Behaviour.h"
#include "../GameEngine/Sprite/Sprite.hpp"
#include "MonsterIA.h"

namespace TacosEngine {
    class MonsterBonusBehaviour : public TacosEngine::Behaviour
    {
    public:
        MonsterBonusBehaviour(const std::string &name, std::shared_ptr<Sprite> sprite, MonsterIa *ia)
                : Behaviour(name, std::move(sprite))
        {
            _ia = ia;
            _maxHealth = 50;
            _health = 50;
            _damages = 20;
            can_shoot = 0;
            tick_per_shoot = 100;
        }

        ~MonsterBonusBehaviour() override = default;

        void Start() override;

        float get_random()
        {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(-1, 1);
            return static_cast<float>(dis(gen));
        }

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


#endif //R_TYPE_MONSTERBONUSBEHAVIOUR_HPP
