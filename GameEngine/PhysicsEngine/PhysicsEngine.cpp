#include "PhysicsEngine.h"

namespace TacosEngine
{
    PhysicsEngine::PhysicsEngine()
    = default;

    PhysicsEngine::~PhysicsEngine()
    = default;

    void PhysicsEngine::update(std::list<std::shared_ptr<Component>> components)
    {
        bool collide;

        for (auto &it : components)
        {
            auto *body = dynamic_cast<Rigidbody *>(it.get());
            if (body)
            {
                Vector2 newPos = body->getSprite()->getTransform().getPosition() + body->getForce();
                for (auto &compo : components)
                {
                    if (compo->getSprite()->getInstanceId() != it->getSprite()->getInstanceId())
                    {
                        if (it->getComponent<Collider>() && compo->getComponent<Collider>())
                        {
                            if (newPos.get_x() != it->getSprite()->getTransform().getPosition().get_x() ||
                                    newPos.get_y() != it->getSprite()->getTransform().getPosition().get_y())
                            {
                                collide = checkCollision(it->getSprite(), body->getForce(), compo->getSprite(), components);
                            }
                            else
                                collide = checkCollision(it->getSprite(), Vector2(0, 0), compo->getSprite(), components);
                            if (collide)
                            {
                                if (!compo->getComponent<Collider>()->is_isTrigger())
                                    newPos = it->getSprite()->getTransform().getPosition();
                            }
                        }
                        makeMove(it->getSprite(), newPos);
                    }
                }
            }
        }
    }

    bool	PhysicsEngine::checkCollision(std::shared_ptr<Sprite> s1, const Vector2 &force,
                                          std::shared_ptr<Sprite> s2, std::list<std::shared_ptr<Component>> components)
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
            callOnCollide(components, s1, s2);
            callOnCollide(components, s2, s1);
            return true;
        }
        return false;
    }

    void PhysicsEngine::callOnCollide(std::list<std::shared_ptr<Component>> components, std::shared_ptr<Sprite> s, std::shared_ptr<Sprite> other)
    {
        for (auto &component : components)
        {
            if (component->getSprite()->getInstanceId() == s->getInstanceId() && dynamic_cast<Behaviour *>(component.get()))
            {
                dynamic_cast<Behaviour *>(component.get())->onCollide(*(other.get()));
            }
        }
    }

    void PhysicsEngine::makeMove(std::shared_ptr<Sprite> s, const Vector2 &pos)
    {
        Vector2 diff = pos - s->getTransform().getPosition();

        s->getTransform().setPosition(pos);
        if (s->getComponent<Collider>())
            s->getComponent<Collider>()->set_position(s->getComponent<Collider>()->get_position() + diff);
    }
}