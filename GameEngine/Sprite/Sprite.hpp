//
// Created by Corentin on 24/01/2018.
//

#ifndef GAMEENGINE_SPRITE_HPP
#define GAMEENGINE_SPRITE_HPP

#include <Scene/Scene.hpp>

namespace TacosEngine
{
    class Sprite : public GameObject
    {
    public:
        Sprite(const std::string &name, std::shared_ptr<Scene> scene, Layout layout, Tag tag = Tag::UNKNOWN);
        ~Sprite() override
        = default;

        void setTexture(ITexture *text);
        void	*getTexture();
        Vector2     &getSize();
        void        setSize(const Vector2 &);
        void 		addTexture(ITexture *texture);

    private:
        Vector2                     _size;
        ITexture					*_texture;
    };
}

#endif //GAMEENGINE_SPRITE_HPP
