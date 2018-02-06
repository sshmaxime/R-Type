//
// Created by chennetier on 14/01/18.
//

#ifndef R_TYPE_SFMLRENDERER_HPP
#define R_TYPE_SFMLRENDERER_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include "../Scene/Scene.hpp"
#include "../IRenderer/IRenderer.hpp"
#include "../Text/Text.hpp"

namespace TacosEngine {

    struct SortByLayout {
        bool	operator()(const std::shared_ptr<GameObject> &i, const std::shared_ptr<GameObject> &j) const
        {
            return *i < *j;
        }
    };

    class SfmlRenderer : public IRenderer {
    private:
        sf::RenderWindow *_window;

    public:
        explicit SfmlRenderer(sf::RenderWindow *window);
        ~SfmlRenderer() override;
        void draw(std::list<std::shared_ptr<GameObject>> _sprites) override;
        sf::Color getColor(Color color);
    };
}


#endif //R_TYPE_SFMLRENDERER_HPP
