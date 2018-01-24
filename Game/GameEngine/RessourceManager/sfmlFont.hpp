//
// Created by chauvin on 14/01/18.
//

#ifndef RESSOURCEMANAGER_SFMLFONT_HPP
#define RESSOURCEMANAGER_SFMLFONT_HPP

#include <memory>
#include <SFML/Graphics/Font.hpp>
#include "IFont.hpp"

namespace TacosEngine
{
  class sfmlFont : public TacosEngine::IFont
  {
    std::shared_ptr<sf::Font> _font;

   public:
    sfmlFont();

    ~sfmlFont();

    bool load(const std::string &path) override;

    void *getFont() override;
  };
}

#endif //RESSOURCEMANAGER_SFMLFONT_HPP
