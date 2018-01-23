#include <Scene/Scene.hpp>

namespace TacosEngine
{
  Sprite::Sprite(const std::string &name, std::shared_ptr<Scene> scene, Layout layout)
	  : Entity(name)
  {
    _layout = layout;
    if (scene)
      _scene = scene;
  }


  void Sprite::setScene(std::shared_ptr<Scene> scene)
  {
    _scene = std::move(scene);
  }

  bool Sprite::setTexture(ITexture *text)
  {
    if (text)
      {
	_texture = text;
	return true;
      }
    return false;
  }

  void *Sprite::getTexture()
  {
    return _texture->getTexture();
  }

  Transform &Sprite::getTransform()
  {
    return _transform;
  }

  void Sprite::addTexture(ITexture *texture)
  {
    this->_texture = texture;
  }

  void Sprite::setLayout(Layout layout)
  {
    _layout = layout;
  }

  const Layout &Sprite::getLayout() const
  {
    return _layout;
  }

  void Sprite::setSize(const Vector2 &size)
  {
    _size = size;
  }

  Vector2 &Sprite::getSize()
  {
    return _size;
  }

  bool Sprite::operator<(const Sprite &j)
  {
    return (static_cast<int>(this->getLayout()) < static_cast<int>(j.getLayout()));
  }
}