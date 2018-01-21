//
// Created by chennetier on 14/01/18.
//

#include "SfmlRenderer.hpp"

TacosEngine::SfmlRenderer::SfmlRenderer(sf::RenderWindow *window)
{
    this->_window = window;
}

TacosEngine::SfmlRenderer::~SfmlRenderer() = default;

void TacosEngine::SfmlRenderer::draw(std::list<std::shared_ptr<Sprite>> sprites) {

    //std::sort(sprites.begin(), sprites.end(), sort_prof);

    for (auto it=sprites.begin(); it!=sprites.end(); it++)
    {
        sf::Sprite  sprite;

        sprite.setTexture(*(static_cast<sf::Texture *>((*it)->getTexture())));
        sprite.setPosition((*it)->getTransform().getPosition().get_x(), (*it)->getTransform().getPosition().get_y());
        this->_window->draw(sprite);

    }
    this->_window->display();
}