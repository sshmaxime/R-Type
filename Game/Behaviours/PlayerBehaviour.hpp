//
// Created by chauvin on 26/01/18.
//

#ifndef GAME_PLAYERBEHAVIOUR_HPP
#define GAME_PLAYERBEHAVIOUR_HPP


#include "../GameEngine/Behaviour/Behaviour.h"
#include "../GameEngine/Sprite/Sprite.hpp"
#include "BulletBehaviour.hpp"
#include "ObstacleBehaviour.hpp"
#include "../GameEngine/Animation/Animation.hpp"
#include "AnimationBehaviour.hpp"

namespace TacosEngine
{
    class PlayerBehaviour : public Behaviour
    {
    public:
        PlayerBehaviour(const std::string &name, std::shared_ptr<Sprite> sprite, bool a)
                : Behaviour(name, std::move(sprite))
        {
            this->_health = 100;
            this->_maxHealth = 100;
            this->_damages = 20;
            this->_bulletType = 1;
            sizeX = 0;
            sizeY = 0;
            _isActive = a;
        }

        ~PlayerBehaviour() override = default;

        void Start() override
        {
            std::cout << "In Start()" << std::endl;
            auto sp = std::dynamic_pointer_cast<Sprite>(_object);
            sizeX = sp->getSize().get_x();
            sizeY = sp->getSize().get_y();
        }

        void update(const Input &input) override;

        void shoot();

        void onCollide(GameObject &other) override
        {
            if (other.getInstanceName().find("bullet") != std::string::npos &&
                other.getInstanceName().find(getInstanceName()) == std::string::npos)
            {
                std::cout << "Oui" << std::endl;
                std::cout << _health << std::endl;
                this->_health = this->_health - other.getComponent<BulletBehaviour>()->get_damages();
            }
            else if (other.getInstanceName().find("Obs") != std::string::npos &&
                     other.getInstanceName().find(getInstanceName()) == std::string::npos)
            {
                this->_health = this->_health - other.getComponent<ObstacleBehaviour>()->get_damages();
            }
            else if (other.getInstanceName().find("ammo") != std::string::npos &&
                     other.getInstanceName().find(getInstanceName()) == std::string::npos)
            {
                this->_damages = this->_damages * 2;
                this->_bulletType = 2;
                other.setActive(false);
            }
            if (this->_health <= 0)
            {
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
        }

        Vector2    &CheckWindowCollide(Vector2 &dir)
        {
            if (dir.get_x() < 0 && _object->getTransform().getPosition().get_x() <= 0.5 ||
                dir.get_x() > 0 && _object->getTransform().getPosition().get_x() >= (799.5 - sizeX))
                dir.set_x(0);
            if (dir.get_y() > 0 && _object->getTransform().getPosition().get_y() >= (399.5 - sizeY) ||
                dir.get_y() < 0 && _object->getTransform().getPosition().get_y() <= 0.5)
                dir.set_y(0);
            return dir;
        }

    private:
        int _health;
        int _maxHealth;
        int _damages;
        size_t _attackSpeed = 0;
        bool _ableAttack = true;
        bool isMoving{};
        bool isShooting{};
        int  _bulletType;
        Vector2 _lastdir;
        float sizeX;
        float sizeY;
    };
}

#endif //GAME_PLAYERBEHAVIOUR_HPP
