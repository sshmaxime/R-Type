//
// Created by chauvin on 14/01/18.
//

#include "RessourceManager.hpp"

int main(int ac, char **av)
{
  TacosEngine::RessourceManager _test;

  _test.init("./init.ressources");
  _test.destroy();
  return 0;
}