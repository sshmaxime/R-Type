//
// Created by chauvin on 17/01/18.
//

#include "Collider.hpp"

TacosEngine::Collider::Collider(float width, float height, TacosEngine::Vector2 position, bool isTrigger,
				const std::string &name, std::shared_ptr<Sprite> sprite) : Component(name, sprite)
{}

bool TacosEngine::Collider::is_isTrigger() const
{
  return _isTrigger;
}

void TacosEngine::Collider::set_isTrigger(bool _isTrigger)
{
  Collider::_isTrigger = _isTrigger;
}

float TacosEngine::Collider::get_height() const
{
  return _height;
}

void TacosEngine::Collider::set_height(float _height)
{
  Collider::_height = _height;
}

float TacosEngine::Collider::get_width() const
{
  return _width;
}

void TacosEngine::Collider::set_width(float _width)
{
  Collider::_width = _width;
}

const TacosEngine::Vector2 &TacosEngine::Collider::get_position() const
{
  return _position;
}

void TacosEngine::Collider::set_position(const TacosEngine::Vector2 &_position)
{
  Collider::_position = _position;
}
