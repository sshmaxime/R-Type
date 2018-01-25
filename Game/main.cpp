//
// Created by chauvin on 25/01/18.
//

#include "Core/Core.hpp"

int main()
{
  Core Game;

  Game.Init();
  Game.get_engine()->run();
  return 0;
}