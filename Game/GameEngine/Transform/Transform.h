#pragma once

#include "../Vector2/Vector2.hpp"

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
		explicit Transform(Vector2 position = Vector2(0, 0), Vector2 direction = Vector2(0, 0), Vector2 rotation = Vector2(0, 0), float speed = 0);
		~Transform();
		const Vector2	&getPosition() const;
		void	setPosition(const Vector2 &pos);
		const Vector2	&getDirection() const;
		void	setDirection(const Vector2 &dir);
		const Vector2	&getRotation() const;
		void	setRotation(const Vector2 &rot);
		float	getSpeed() const;
		void	setSpeed(float speed);
	};
}