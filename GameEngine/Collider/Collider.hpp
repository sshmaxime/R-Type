//
// Created by chauvin on 17/01/18.
//

#ifndef GAMEENGINE_COLLIDER_HPP
#define GAMEENGINE_COLLIDER_HPP


#include <Scene/Scene.hpp>
#include "../Entity/Entity.hpp"
#include "../Vector2/Vector2.hpp"

namespace TacosEngine
{
  class Collider : TacosEngine::Component
  {

   public:
    Collider(float width, float height, Vector2 position, bool isTrigger,
	     const std::string &name, std::shared_ptr<Sprite> sprite);
    ~Collider() override = default;
    bool is_isTrigger() const;
    void set_isTrigger(bool _isTrigger);
    float get_height() const;
    void set_height(float _height);
    float get_width() const;
    void set_width(float _width);
    const Vector2 &get_position() const;
    void set_position(const Vector2 &_position);

   private:
    bool _isTrigger;
    float _height;
    float _width;
    Vector2 _position;
  };
}

#endif //GAMEENGINE_COLLIDER_HPP
