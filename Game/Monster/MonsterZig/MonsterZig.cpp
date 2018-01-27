//
// Created by simon on 27/01/18.
//
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "../Behaviours/MonsterIA.h"

class MonsterZig : public MonsterIa
{
public:
    MonsterZig() : MonsterIa()
    {
      m_y = -0.6;
        ampl = 1;
        maxample = 150;
    }
    ~MonsterZig(){}

  float getbestY(std::vector<std::pair<float, float> > playerpos, std::pair<float, float> mypos)
  {
    std::pair<float, float> close(0, 0);
    std::pair<float, float> best(0, 0);
    float ret;
    for (auto p = playerpos.begin(); p != playerpos.end(); p++)
      {
	std::pair<float, float> tmp(mypos.first - p->first, mypos.second - p->second);
	if (tmp.first < 0)
	  tmp.first = -tmp.first;
	if (tmp.second < 0)
	  tmp.second = -tmp.first;
	if (tmp.first + tmp.second < (mypos.first - close.first + mypos.second - close.second))
	  {
	    close = tmp;
	    best = *p;

	  }
      }
    if (best.first != 0 || best.second != 0)
      {
	if (best.second < mypos.second)
	  ret = -0.2;
	if (best.second > mypos.second)
	  ret = 0.2;
      } else
      {
	std::cout << "no player.." << std::endl;
	ret = 0;
      }
    return (ret);
  }

  std::pair<float, float> getBestMove(std::vector<std::pair<float, float> > playerpos, std::pair<float, float> mypos)
    {
        std::pair<float, float> ret;

        ret.first = -0.3;
      float besty = getbestY(playerpos, mypos);
      if (besty * m_y < 0)
	maxample = 50;
      else
	maxample = 150;
        if (ampl++ > maxample)
        {
            ampl = 1;
            m_y = -m_y;
        }
        ret.second = m_y;
        return ret;
    }

private:
    float m_y;
    int ampl;
    int maxample;

    //    test() : aLib("testt"){};
};

extern "C" MonsterIa* create() {

        std::cout << "WILL CREATE MONSTERBASIC" << std::endl;
        return new MonsterZig();
}
extern "C" void destroy(MonsterIa* p) {
    delete p;
}