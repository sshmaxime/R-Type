
#include "PhysicsEngine.h"
#include "../Rigidbody/Rigidbody.hpp"
#include "../Behaviour/Behaviour.h"


namespace TacosEngine
{
	PhysicsEngine::PhysicsEngine()
	= default;

	PhysicsEngine::~PhysicsEngine()
	= default;

	void PhysicsEngine::update(std::list<std::shared_ptr<GameObject>> &objects)
	{
		bool collide;
		bool resetPos;
		Vector2 newPos;
		Vector2 newPosCol;

		for (auto &it : objects)
		{
			auto body = it->getComponent<Rigidbody>();
			if (body && body->isActive())
			{
				resetPos = false;
				newPos = body->getGameObject()->getTransform().getPosition() + body->getForce();
				auto itCol = it->getComponent<Collider>();
                if (itCol) {
                    for (auto &compo : objects) {
                        if (compo->getInstanceId() != it->getInstanceId()) {
                            auto compoRig = compo->getComponent<Rigidbody>();
                            auto compoCol = compo->getComponent<Collider>();
                            if (compoRig)
                                newPosCol = compo->getTransform().getPosition() + compoRig->getForce();
                            else
                                newPosCol = compo->getTransform().getPosition();
                            if (itCol && compoCol) {
                                collide = checkCollision(it, newPos, newPosCol, compo, objects, itCol, compoCol);
                                if (!compoCol->is_isTrigger() && collide)
                                    resetPos = true;
                            }
                        }
                    }
                }
				if (resetPos)
					finalPos.push_back(it->getTransform().getPosition());
				else
					finalPos.push_back(newPos);
				coll.push_back(itCol);
				gameObjects.push_back(it);
			}

		}
		callOnCollide();
		makeMove();
		gameObjects.clear();
		gameObjects2.clear();
		gameObjects1.clear();
		finalPos.clear();
		coll.clear();
	}

	bool PhysicsEngine::checkCollision(const std::shared_ptr<GameObject> &s1, const Vector2 &posS1, const Vector2 &posS2,
									   const std::shared_ptr<GameObject> &s2,
									   std::list<std::shared_ptr<GameObject>> &objects,
									   std::shared_ptr<Collider> &s1Col, std::shared_ptr<Collider> &s2Col)
	{
		Vector2 sizeS1 = s1Col->get_size();
		Vector2 sizeS2 = s2Col->get_size();

		if (posS1.get_x() <= posS2.get_x() + sizeS2.get_x() &&
			posS1.get_x() + sizeS1.get_x() >= posS2.get_x() &&
			posS1.get_y() <= posS2.get_y() + sizeS2.get_y() &&
			posS1.get_y() + sizeS1.get_y() >= posS2.get_y())
		{
			gameObjects1.push_back(s1);
			gameObjects2.push_back(s2);
			return true;
		}
		return false;
	}

	void PhysicsEngine::callOnCollide()
	{
		auto it = gameObjects1.begin();
		auto it2 = gameObjects2.begin();
		for (; it != gameObjects1.end(); it++, it2++)
		{
			auto beha = (*it)->getComponent<Behaviour>();
			if (beha)
				beha->onCollide(*(*it2));
		}
	}

	void PhysicsEngine::makeMove()
	{
		auto pos = finalPos.begin();
		auto object = gameObjects.begin();
		auto collider = coll.begin();
		Vector2 diff;

		for (; pos != finalPos.end(); pos++, object++, collider++)
		{
			diff = (*pos) - (*object)->getTransform().getPosition();
			(*object)->getTransform().setPosition(*pos);
		    (*object)->getComponent<Rigidbody>()->addForce(Vector2(0, 0));
			if (*collider)
			{
				(*collider)->set_position((*collider)->get_position() + diff);
			}
		}
	}
}