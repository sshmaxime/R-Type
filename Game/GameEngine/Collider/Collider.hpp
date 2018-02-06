//
// Created by chauvin on 17/01/18.
//

#ifndef GAMEENGINE_COLLIDER_HPP
#define GAMEENGINE_COLLIDER_HPP

#include "../Entity/Entity.hpp"
#include "../Vector2/Vector2.hpp"
#include "../Scene/Scene.hpp"

namespace TacosEngine
{
  class Collider : public Component
  {
   public:
    Collider(const std::string &name, std::shared_ptr<GameObject> gameObject, const Vector2 &size, const Vector2 &position, bool isTrigger);
    ~Collider() override = default;
    bool is_isTrigger() const;
    void set_isTrigger(bool _isTrigger);
    const Vector2 &get_position() const;
    void set_position(const Vector2 &_position);

   private:
    bool _isTrigger;
   Vector2 _size;
  public:
      const Vector2 &get_size() const;

      void set_size(const Vector2 &_size);

  private:
      Vector2 _position;
  };
}

#endif //GAMEENGINE_COLLIDER_HPP
