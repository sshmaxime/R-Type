//
// Created by simon on 26/01/18.
//

#ifndef GAME_MONSTERIA_H
#define GAME_MONSTERIA_H

class MonsterIa
{
 public:
  MonsterIa()
  {
    _lenx = 400;
    _leny = 800;
  }

  virtual std::pair<float, float> getBestMove(float x, float y)
  {
    std::cout << "LOLMONSTERIA" << std::endl;
    return (std::make_pair<float, float>(0, 0));
  };

  virtual ~MonsterIa()
  {}

 protected:
  float _lenx;
  float _leny;
};

#endif //GAME_MONSTERIA_H
