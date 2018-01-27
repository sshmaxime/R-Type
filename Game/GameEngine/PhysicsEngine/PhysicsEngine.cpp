
#include "PhysicsEngine.h"

#include <GameEngine/Rigidbody/Rigidbody.hpp>
#include <GameEngine/Behaviour/Behaviour.h>

namespace TacosEngine
{
  PhysicsEngine::PhysicsEngine()
  = default;

  PhysicsEngine::~PhysicsEngine()
  = default;

  void PhysicsEngine::update(std::list<std::shared_ptr<GameObject>> &objects)
  {
    bool collide;

    for (auto &it : objects)
      {
	auto body = it->getComponent<Rigidbody>();
	if (body && body->isActive())
	  {
	    Vector2 newPos = body->getGameObject()->getTransform().getPosition() + body->getForce();
	    auto itCol = it->getComponent<Collider>();
	    for (auto &compo : objects)
	      {
		if (itCol && compo->getInstanceId() != it->getInstanceId())
		  {
		    auto compoCol = compo->getComponent<Collider>();
		    if (itCol && compoCol)
		      {
			if (newPos.get_x() != it->getTransform().getPosition().get_x() ||
			    newPos.get_y() != it->getTransform().getPosition().get_y())
			  {
			    collide = checkCollision(it, body->getForce(), compo, objects, itCol, compoCol);
			  } else
			  collide = checkCollision(it, Vector2(0, 0), compo, objects, itCol, compoCol);
			if (collide)
			  {
			    if (!compoCol->is_isTrigger())
			      newPos = it->getTransform().getPosition();
			  }
		      }
		  }
		makeMove(it, newPos, itCol);
	      }
	  }
      }
  }

  bool PhysicsEngine::checkCollision(std::shared_ptr<GameObject> s1, const Vector2 &force,
				     std::shared_ptr<GameObject> s2, std::list<std::shared_ptr<GameObject>> objects,
				     std::shared_ptr<Collider> &s1Col, std::shared_ptr<Collider> &s2Col)
  {
    Vector2 posS1 = s1Col->get_position() + force;
    Vector2 posS2 = s2Col->get_position();
    Vector2 sizeS1 = s1Col->get_size();
    Vector2 sizeS2 = s2Col->get_size();

    if (posS1.get_x() < posS2.get_x() + sizeS2.get_x() &&
	posS1.get_x() + sizeS1.get_x() > posS2.get_x() &&
	posS1.get_y() < posS2.get_y() + sizeS2.get_y() &&
	posS1.get_y() + sizeS1.get_y() > posS2.get_y())
      {
	callOnCollide(std::move(objects), s1, s2);
	return true;
      }
    return false;
  }

  void PhysicsEngine::callOnCollide(std::list<std::shared_ptr<GameObject>> objects, std::shared_ptr<GameObject> s,
				    std::shared_ptr<GameObject> other)
  {
    for (auto &object : objects)
      {
	if (object->getInstanceId() == s->getInstanceId() && object->getComponent<Behaviour>())
	  {
	    object->getComponent<Behaviour>()->onCollide(*(other.get()));
	  }
      }
  }

  void PhysicsEngine::makeMove(std::shared_ptr<GameObject> s, const Vector2 &pos, std::shared_ptr<Collider> &coll)
  {
    Vector2 diff = pos - s->getTransform().getPosition();

    s->getTransform().setPosition(pos);
    if (coll)
      coll->set_position(coll->get_position() + diff);
  }
}