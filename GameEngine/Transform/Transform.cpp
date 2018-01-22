#include "Transform.h"

namespace TacosEngine
{
	Transform::Transform(Vector2 position, Vector2 direction, Vector2 rotation, float speed)
	{
		this->position = position;
		this->direction = direction;
		this->rotation = rotation;
		this->speed = speed;
	}

	Transform::~Transform()
	= default;

	Vector2	Transform::getDirection()
	{
		return direction;
	}

	Vector2	Transform::getPosition()
	{
		return position;
	}

	Vector2	Transform::getRotation()
	{
		return rotation;
	}

	float	Transform::getSpeed()
	{
		return speed;
	}

	void	Transform::setDirection(const Vector2 &dir)
	{
		direction = dir;
	}

	void	Transform::setPosition(const Vector2 &pos)
	{
		position = pos;
	}

	void	Transform::setRotation(const Vector2 &rot)
	{
		rotation = rot;
	}

	void	Transform::setSpeed(float speed)
	{
		this->speed = speed;
	}
}