//
// Created by chennetier on 14/01/18.
//

#ifndef R_TYPE_IRENDERER_HPP
#define R_TYPE_IRENDERER_HPP

#include <list>
#include <Scene/Scene.hpp>

namespace TacosEngine {

    class IRenderer {

    public:
        virtual ~IRenderer() = default;;

        virtual void draw(std::list<std::shared_ptr<Sprite>> _sprites) = 0;

    };

}

#endif //R_TYPE_IRENDERER_HPP