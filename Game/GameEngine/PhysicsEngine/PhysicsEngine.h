#pragma once

#include <GameEngine/Collider/Collider.hpp>
#include "../Scene/Scene.hpp"
#include "../Vector2/Vector2.hpp"

namespace TacosEngine
{
	class PhysicsEngine
	{
	public:
		PhysicsEngine();
		~PhysicsEngine();

	  void update(std::list<std::shared_ptr<GameObject>> &components);

	private:
	  bool checkCollision(std::shared_ptr<GameObject> s1, const Vector2 &posS1, std::shared_ptr<GameObject> s2,
                          std::list<std::shared_ptr<GameObject>> &components, std::shared_ptr<Collider> &,
                          std::shared_ptr<Collider> &);

        void callOnCollide(std::list<std::shared_ptr<GameObject>> &components, std::shared_ptr<GameObject> s,
                           std::shared_ptr<GameObject> other);

	  void makeMove(std::shared_ptr<GameObject> s, const Vector2 &pos, std::shared_ptr<Collider> &);
    };
}