#pragma once

#include "Vector2.hpp"

namespace TacosEngine
{
	class Transform
	{
	private:
		Vector2 position;
		Vector2 direction;
		Vector2 rotation;
		float	speed;

	public:
		Transform(Vector2 position = Vector2(), Vector2 direction = Vector2(), Vector2 rotation = Vector2(), float speed = 0);
		~Transform();
		Vector2	getPosition();
		void	setPosition(const Vector2 &pos);
		Vector2	getDirection();
		void	setDirection(const Vector2 &dir);
		Vector2	getRotation();
		void	setRotation(const Vector2 &rot);
		float	getSpeed();
		void	setSpeed(float speed);
	};
}