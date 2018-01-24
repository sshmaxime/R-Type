#include <Sprite/Sprite.hpp>

namespace TacosEngine
{
	Sprite::Sprite(const std::string &name, std::shared_ptr<Scene> scene, Layout layout, Tag tag)
		: GameObject(name, std::move(scene), layout, tag)
    {
	}


    void Sprite::setTexture(ITexture *text)
    {
        _texture = text;
    }

    void	*Sprite::getTexture()
    {
        return _texture->getTexture();
    }

    void 		Sprite::addTexture(ITexture *texture)
    {
        this->_texture = texture;
    }

    void Sprite::setSize(const Vector2 &size)
    {
        _size = size;
    }

    Vector2 &Sprite::getSize()
    {
        return _size;
    }
}