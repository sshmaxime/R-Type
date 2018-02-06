//
// Created by chauvin on 14/01/18.
//

#ifndef RESSOURCEMANAGER_SFMLTEXTURE_HPP
#define RESSOURCEMANAGER_SFMLTEXTURE_HPP

#include <memory>
#include <SFML/Graphics/Texture.hpp>
#include "ITexture.hpp"

namespace TacosEngine
{
  class sfmlTexture : public TacosEngine::ITexture
  {
    std::shared_ptr<sf::Texture> _texture;

   public:
    sfmlTexture();

    ~sfmlTexture();

    bool load(const std::string &path) override;

    void *getTexture() override;
  };
}

#endif //RESSOURCEMANAGER_SFMLTEXTURE_HPP
