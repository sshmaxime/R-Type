#pragma once

#include <Scene/Scene.hpp>
#include <Rigidbody/Rigidbody.hpp>
#include <Collider/Collider.hpp>
#include <Behaviour/Behaviour.h>

namespace TacosEngine
{
	class PhysicsEngine
	{
	public:
		PhysicsEngine();
		~PhysicsEngine();
		void	update(std::list<std::shared_ptr<Component>> components);

	private:
		bool	checkCollision(std::shared_ptr<Sprite> s1, const Vector2 &posS1, std::shared_ptr<Sprite> s2, std::list<std::shared_ptr<Component>> components);
		void	callOnCollide(std::list<std::shared_ptr<Component>> components, std::shared_ptr<Sprite> s, std::shared_ptr<Sprite> other);
	    void    makeMove(std::shared_ptr<Sprite> s, const Vector2 &pos);
    };
}