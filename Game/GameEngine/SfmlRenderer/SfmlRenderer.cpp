//
// Created by chennetier on 14/01/18.
//

#include <GameEngine/Sprite/Sprite.hpp>
#include "SfmlRenderer.hpp"

TacosEngine::SfmlRenderer::SfmlRenderer(sf::RenderWindow *window)
{
    this->_window = window;
}

TacosEngine::SfmlRenderer::~SfmlRenderer() = default;

void TacosEngine::SfmlRenderer::draw(std::list<std::shared_ptr<GameObject>> gameObjects)
{
    gameObjects.sort(SortByLayout());
    this->_window->clear();
    for (auto &gameObject : gameObjects)
    {
        if (gameObject->isActive())
        {
            if (dynamic_cast<Sprite *>(gameObject.get()))
            {
                sf::Sprite sprite;
                std::shared_ptr<Sprite> sp = std::dynamic_pointer_cast<Sprite>(gameObject);

                sprite.setTexture(*(static_cast<sf::Texture *>(sp->getTexture())));
                sprite.setPosition(gameObject->getTransform().getPosition().get_x(),
                                   gameObject->getTransform().getPosition().get_y());
                sprite.setScale(
                        sp->getSize().get_x() / sprite.getLocalBounds().width,
                        sp->getSize().get_y() / sprite.getLocalBounds().height
                );
                this->_window->draw(sprite);
            }
            else if (dynamic_cast<Text *>(gameObject.get()))
            {
                sf::Text text;
                std::shared_ptr<Text> t = std::dynamic_pointer_cast<Text>(gameObject);

                text.setFont(*(static_cast<sf::Font *>(t->getFont()->getFont())));
                text.setString(t->getText());
                text.setCharacterSize(static_cast<unsigned int>(t->getSize().get_x()));
                text.setColor(getColor(t->getColor()));
                text.setPosition(
                        (*t).getTransform().getPosition().get_x(),
                        (*t).getTransform().getPosition().get_y()
                );
                _window->draw(text);
            }
        }
    }
    this->_window->display();
}

sf::Color TacosEngine::SfmlRenderer::getColor(TacosEngine::Color color) {
    switch (color)
    {
        case Color::BLACK :
            return sf::Color::Black;
        case Color::WHITE :
            return sf::Color::White;
        case Color::RED :
            return sf::Color::Red;
        case Color::GREEN :
            return sf::Color::Green;
        case Color::BLUE :
            return sf::Color::Blue;
        case Color::YELLOW :
            return sf::Color::Yellow;
        case Color::MAGENTA :
            return sf::Color::Magenta;
        case Color::CYAN :
            return sf::Color::Cyan;
    }
    return sf::Color::Black;
}
