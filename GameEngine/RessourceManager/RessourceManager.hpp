//
// Created by chauvin on 14/01/18.
//

#ifndef RESSOURCEMANAGER_RESSOURCEMANAGER_HPP
#define RESSOURCEMANAGER_RESSOURCEMANAGER_HPP

#include <memory>
#include <map>
#include <fstream>
#include "IFont.hpp"
#include "IAudio.hpp"
#include "ITexture.hpp"
#include "sfmlTexture.hpp"

namespace TacosEngine
{
  class RessourceManager
  {
   public:
    RessourceManager() = default;

    ~RessourceManager() = default;

    void init(const std::string &path);
    void destroy();

    IFont	*getFont(const std::string &name)
    {
      return _fonts[name];
    }

    IAudio	*getAudio(const std::string &name)
    {
      return _audios[name];
    }

    ITexture	*getTexture(const std::string &name)
    {
      return _textures[name];
    }

   private:
    std::map<std::string, IFont*> _fonts;
    std::map<std::string, IAudio*> _audios;
    std::map<std::string, ITexture*> _textures;

    template <typename T, typename I>
    void loadRessource(std::ifstream &input, std::map<std::string, I> &type)
    {
      std::string value(" ");
      std::string key(" ");

      while (true)
	{
	  I elem = new T;

	  std::getline(input, key, ':'); //Read up to the : delimiter into key
	  std::getline(input, value, '\n'); // Read up to the new line into value
	  if (value == "/")
	    break;
	  if (elem->load(value))
	    {
	      std::cout << "load " << key << ":" << value << std::endl;
	      type.insert(std::make_pair(key, elem));
	    }
	  else
	    delete(elem);
	}
    }

  };
}

#endif //RESSOURCEMANAGER_RESSOURCEMANAGER_HPP
