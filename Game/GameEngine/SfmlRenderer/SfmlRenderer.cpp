//
// Created by chennetier on 14/01/18.
//

#include <Sprite/Sprite.hpp>
#include "SfmlRenderer.hpp"

TacosEngine::SfmlRenderer::SfmlRenderer(sf::RenderWindow *window)
{
    this->_window = window;
}

TacosEngine::SfmlRenderer::~SfmlRenderer() = default;

void TacosEngine::SfmlRenderer::draw(std::list<std::shared_ptr<GameObject>> gameObjects) {
    gameObjects.sort(SortByLayout());
    for (auto it=gameObjects.begin(); it!=gameObjects.end(); it++)
    {
        if (dynamic_cast<Sprite *>(it->get())) {

            sf::Sprite sprite;
            std::shared_ptr<Sprite> sp = std::dynamic_pointer_cast<Sprite>(*it);

            sprite.setTexture(*(static_cast<sf::Texture *>(sp->getTexture())));
            sprite.setPosition((*it)->getTransform().getPosition().get_x(),
                               (*it)->getTransform().getPosition().get_y());
            sprite.setScale(
                    sp->getSize().get_x() / sprite.getLocalBounds().width,
                    sp->getSize().get_y() / sprite.getLocalBounds().height
            );
            this->_window->draw(sprite);
        }
    }
    this->_window->display();
}