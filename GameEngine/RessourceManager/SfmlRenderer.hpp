//
// Created by chennetier on 14/01/18.
//

#ifndef R_TYPE_SFMLRENDERER_HPP
#define R_TYPE_SFMLRENDERER_HPP

#include <SFML/Graphics.hpp>
#include <memory>

#include "IRenderer.hpp"

namespace TacosEngine {

    class SfmlRenderer : public IRenderer {

    private:
        sf::RenderWindow *_window;

    public:
        explicit SfmlRenderer(sf::RenderWindow *window);

        ~SfmlRenderer() override;

        static bool sort_prof (int i,int j) { return (i<j); }

        void draw(std::list<std::shared_ptr<Sprite>> _sprites) override;
    };
}


#endif //R_TYPE_SFMLRENDERER_HPP
