//
// Created by chauvin on 27/01/18.
//


#include "ObstacleBehaviour.hpp"
#include "../GameEngine/Scene/Scene.hpp"
#include "../GameEngine/Behaviour/Behaviour.h"
#include "../GameEngine/Rigidbody/Rigidbody.hpp"
#include "../GameEngine/Sprite/Sprite.hpp"
#include "../GameEngine/Animation/Animation.hpp"
#include "../GameEngine/Collider/Collider.hpp"
#include "BulletBehaviour.hpp"
#include "AnimationBehaviour.hpp"

namespace TacosEngine
{
    TacosEngine::ObstacleBehaviour::ObstacleBehaviour(const std::string &name,
                                                      const std::shared_ptr<TacosEngine::GameObject> &object, Vector2 dir)
            : Behaviour(
            name, object)
    {
        _damages = 30;
        _dir = dir / 2;
    }

    void TacosEngine::ObstacleBehaviour::Start()
    {
        auto rb = getComponent<Rigidbody>();
        rb->addForce(_dir);
    }

    void TacosEngine::ObstacleBehaviour::update(const TacosEngine::Input &)
    {
        auto rb = getComponent<Rigidbody>();
        rb->addForce(_dir + Vector2(0, this->get_random()));
        auto pos = _object->getTransform().getPosition();
        if (pos.get_x() < 0)
            setDestroy(true);
    }

    void ObstacleBehaviour::onCollide(GameObject &other)
    {
        std::cout << "DESTROY" << std::endl;
        this->setDestroy(true);
        auto explosion = std::make_shared<Sprite>("explosion", this->_object->getScene(),
                                                  Layout::SCENE);

        std::vector<ITexture*>      explosionFrames;
        explosionFrames.push_back(_object->getScene()->getTexture("explosion1"));
        explosionFrames.push_back(_object->getScene()->getTexture("explosion2"));
        explosionFrames.push_back(_object->getScene()->getTexture("explosion3"));

        explosion->setTexture(_object->getScene()->getTexture("explosion1"));
        explosion->setSize(Vector2(40, 40));
        explosion->getTransform().setPosition(_object->getTransform().getPosition());
        explosion->getTransform().setSpeed(0.0);
        explosion->setActive(true);
        std::shared_ptr<Animation>       explosionAnim =
                std::make_shared<Animation>("explosionAnim", explosion,
                                            false, 20, explosionFrames);

        auto beha = std::make_shared<AnimationBehaviour>("endAnim", explosion);


        this->_object->getScene()->addGameObject(explosion);
        this->_object->getScene()->addComponent(explosionAnim);
        this->_object->getScene()->addComponent(beha);
    }

    int ObstacleBehaviour::get_damages() const {
        return _damages;
    }

    void ObstacleBehaviour::set_damages(int _damages) {
        ObstacleBehaviour::_damages = _damages;
    }
}
