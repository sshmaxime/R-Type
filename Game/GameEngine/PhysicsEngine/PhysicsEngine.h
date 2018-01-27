#pragma once

#include "../Scene/Scene.hpp"
#include "../Vector2/Vector2.hpp"
#include "../Collider/Collider.hpp"

namespace TacosEngine
{
	class PhysicsEngine
	{
	public:
		PhysicsEngine();
		~PhysicsEngine();

	  void update(std::list<std::shared_ptr<GameObject>> &components);

	private:
	  bool checkCollision(const std::shared_ptr<GameObject> &s1, const Vector2 &posS1, const Vector2 &posS2,
			      const std::shared_ptr<GameObject> &s2,
			      std::list<std::shared_ptr<GameObject>> &components, std::shared_ptr<Collider> &,
			      std::shared_ptr<Collider> &);

	  void callOnCollide();

	  void makeMove();

	 private:
	  std::vector<Vector2> finalPos;
	  std::vector<std::shared_ptr<GameObject>> gameObjects;
	  std::vector<std::shared_ptr<GameObject>> gameObjects1;
	  std::vector<std::shared_ptr<GameObject>> gameObjects2;
	  std::vector<std::shared_ptr<Collider>> coll;
    };
}