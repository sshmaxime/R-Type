//
// Created by chauvin on 17/01/18.
//

#include "Collider.hpp"

TacosEngine::Collider::Collider(const std::string &name, std::shared_ptr<GameObject> gameObject,
                                const Vector2 &size, const Vector2 &position, bool isTrigger)
        : Component(name, std::move(gameObject))
{
    _size = size;
    _position = position;
    _isTrigger = isTrigger;
}

bool TacosEngine::Collider::is_isTrigger() const
{
    return _isTrigger;
}

void TacosEngine::Collider::set_isTrigger(bool _isTrigger)
{
    Collider::_isTrigger = _isTrigger;
}


const TacosEngine::Vector2 &TacosEngine::Collider::get_position() const
{
    return _position;
}

void TacosEngine::Collider::set_position(const TacosEngine::Vector2 &_position)
{
    Collider::_position = _position;
}

const TacosEngine::Vector2 &TacosEngine::Collider::get_size() const {
    return _size;
}

void TacosEngine::Collider::set_size(const TacosEngine::Vector2 &_size) {
    Collider::_size = _size;
}
