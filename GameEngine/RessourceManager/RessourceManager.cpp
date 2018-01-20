//
// Created by chauvin on 14/01/18.
//

#include <fstream>
#include "RessourceManager.hpp"
#include "sfmlAudio.hpp"
#include "sfmlFont.hpp"

void TacosEngine::RessourceManager::init(const std::string &path)
{

  std::ifstream input(path); //The input stream
  while(input) //Keep on going as long as the file stream is good
    {
      std::string key; //The key
      std::string value; //The value
      std::getline(input, key, ':'); //Read up to the : delimiter into key
      input.get();
      if (key == "texture")
	{
	  std::cout << "Initialazing textures..." << std::endl;
	  this->loadRessource<sfmlTexture, ITexture*>(input, _textures);
	}
      else if (key == "audio")
	  {
	    std::cout << "Initialazing audios..." << std::endl;
	    this->loadRessource<sfmlAudio, IAudio*>(input, _audios);
	  }
      else if (key == "font")
	    {
	      std::cout << "Initialazing fonts..." << std::endl;
	      this->loadRessource<sfmlFont, IFont*>(input, _fonts);
	    }
      key.clear();
    }
  input.close(); //Close the file stream
}

void TacosEngine::RessourceManager::destroy()
{
  _fonts.clear();
  _audios.clear();
  _textures.clear();
}
