//
// Created by simon on 26/01/18.
//

#ifndef GAME_MONSTERBEHAVIOUR_H
#define GAME_MONSTERBEHAVIOUR_H

#include <GameEngine/Scene/Scene.hpp>
#include <GameEngine/Input/Input.h>
#include <Level/Level.hpp>

class MonsterIa;

namespace TacosEngine {
    class MonsterBehaviour : public Behaviour {
    public:
        MonsterBehaviour(const std::string &name, std::shared_ptr<Sprite> sprite, MonsterIa *ia)
                : Behaviour(name, std::move(sprite)) {
            can_shoot = 0;
            tick_per_shoot = 100;
            _ia = ia;
            life = 10;
        }

        ~MonsterBehaviour() override = default;

        void Start() override {
            std::cout << "MONSTER In Start()" << std::endl;
        }

        void update(const Input &) override;

        void shoot();

        void onCollide(GameObject &other) override {
            std::cout << "MONSTEROnCollide() => " << other.getInstanceName() << std::endl;

            if (other.getInstanceName().find("bullet") != std::string::npos &&
                other.getInstanceName().find("Player") == std::string::npos) {
    std::cout << "DIE life:" << life;
            if (--life == 0)
                setDestroy(true);
            }
        }
    private:
        int can_shoot;
        int tick_per_shoot;
        int life;
        MonsterIa  *_ia;
    };
}

#endif //GAME_MONSTERBEHAVIOUR_H
