
#include "PhysicsEngine.h"

#include <GameEngine/Rigidbody/Rigidbody.hpp>
#include <GameEngine/Collider/Collider.hpp>
#include <GameEngine/Behaviour/Behaviour.h>

namespace TacosEngine
{
    PhysicsEngine::PhysicsEngine()
    = default;

    PhysicsEngine::~PhysicsEngine()
    = default;

    void PhysicsEngine::update(std::list<std::shared_ptr<GameObject>> objects)
    {
        bool collide;

        for (auto &it : objects)
        {
            auto body = it->getComponent<Rigidbody>();
            if (body)
            {
                Vector2 newPos = body->getGameObject()->getTransform().getPosition() + body->getForce();
                for (auto &compo : objects)
                {
                    if (compo->getInstanceId() != it->getInstanceId())
                    {
                        if (it->getComponent<Collider>() && compo->getComponent<Collider>())
                        {
                            if (newPos.get_x() != it->getTransform().getPosition().get_x() ||
                                    newPos.get_y() != it->getTransform().getPosition().get_y())
                            {
                                collide = checkCollision(it, body->getForce(), compo, objects);
                            }
                            else
                                collide = checkCollision(it, Vector2(0, 0), compo, objects);
                            if (collide)
                            {
                                if (!compo->getComponent<Collider>()->is_isTrigger())
                                    newPos = it->getTransform().getPosition();
                            }
                        }
                    }
                    makeMove(it, newPos);
                }
            }
        }
    }

    bool	PhysicsEngine::checkCollision(std::shared_ptr<GameObject> s1, const Vector2 &force,
                                          std::shared_ptr<GameObject> s2, std::list<std::shared_ptr<GameObject>> objects)
    {
        Vector2 posS1 = s1->getComponent<Collider>()->get_position() + force;
        Vector2	posS2 = s2->getComponent<Collider>()->get_position();
        Vector2 sizeS1 = s1->getComponent<Collider>()->get_size();
        Vector2 sizeS2 = s2->getComponent<Collider>()->get_size();

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

    void PhysicsEngine::callOnCollide(std::list<std::shared_ptr<GameObject>> objects, std::shared_ptr<GameObject> s, std::shared_ptr<GameObject> other)
    {
        for (auto &object : objects)
        {
            if (object->getInstanceId() == s->getInstanceId() && object->getComponent<Behaviour>())
            {
                object->getComponent<Behaviour>()->onCollide(*(other.get()));
            }
        }
    }

    void PhysicsEngine::makeMove(std::shared_ptr<GameObject> s, const Vector2 &pos)
    {
        Vector2 diff = pos - s->getTransform().getPosition();

        s->getTransform().setPosition(pos);
        if (s->getComponent<Collider>())
            s->getComponent<Collider>()->set_position(s->getComponent<Collider>()->get_position() + diff);
    }
}