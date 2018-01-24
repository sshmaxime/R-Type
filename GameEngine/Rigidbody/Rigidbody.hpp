//
// Created by Corentin on 23/01/2018.
//

#ifndef GAMEENGINE_RIGIDBODY_HPP
#define GAMEENGINE_RIGIDBODY_HPP

#include <Scene/Scene.hpp>

namespace TacosEngine
{
    class Rigidbody : public Component
    {
    public:
        Rigidbody(const std::string &name, std::shared_ptr<GameObject> object);
        ~Rigidbody();
        const Vector2 &getForce() const;
        void addForce(const Vector2 &_force);


    private:
        Vector2 _force;
    };
}

#endif //GAMEENGINE_RIGIDBODY_HPP
