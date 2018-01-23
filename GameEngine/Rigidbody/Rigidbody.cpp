//
// Created by Corentin on 23/01/2018.
//

#include "Rigidbody.hpp"

namespace TacosEngine
{
    Rigidbody::Rigidbody(const std::string &name, std::shared_ptr<Sprite> sprite)
        : Component(name, std::move(sprite))
    {
        _force = Vector2(0, 0);
    }

    Rigidbody::~Rigidbody() = default;

    const Vector2 &Rigidbody::getForce() const {
        return _force;
    }

    void Rigidbody::addForce(const Vector2 &_force) {
        Rigidbody::_force = _force;
    }
}