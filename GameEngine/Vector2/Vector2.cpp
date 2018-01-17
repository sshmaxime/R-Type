//
// Created by chennetier on 14/01/18.
//

#include "Vector2.hpp"

float TacosEngine::Vector2::get_x() const {
    return _x;
}

void TacosEngine::Vector2::set_x(float _x) {
    Vector2::_x = _x;
}

float TacosEngine::Vector2::get_y() const {
    return _y;
}

void TacosEngine::Vector2::set_y(float _y) {
    Vector2::_y = _y;
}

TacosEngine::Vector2::Vector2(float x, float y) {
    this->_x = x;
    this->_y = y;
}

TacosEngine::Vector2	&TacosEngine::Vector2::operator=(const TacosEngine::Vector2 &other)
{
	this->_x = other._x;
	this->_y = other._y;
	return *this;
}

TacosEngine::Vector2	&TacosEngine::Vector2::operator+(const TacosEngine::Vector2 &other)
{
	this->_x += other._x;
	this->_y += other._y;
	return *this;
}

TacosEngine::Vector2	&TacosEngine::Vector2::operator-(const TacosEngine::Vector2 &other)
{
	this->_x -= other._x;
	this->_y -= other._y;
	return *this;
}

TacosEngine::Vector2	&TacosEngine::Vector2::operator*(const TacosEngine::Vector2 &other)
{
	this->_x *= other._x;
	this->_y *= other._y;
	return *this;
}

