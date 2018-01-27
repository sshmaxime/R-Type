//
// Created by simon on 26/01/18.
//
#include <iostream>
#include <string>
#include <list>
#include "../Behaviours/MonsterIA.h"
#include <vector>
class MonsterBasic : public MonsterIa
{
public:
    MonsterBasic() : MonsterIa()
    {
    }
    ~MonsterBasic(){}
    float   getbestY(std::vector<std::pair<float, float> > playerpos, std::pair<float, float> mypos)
    {
        std::pair<float, float>close(0, 0);
        std::pair<float, float>best(0, 0);
        float ret;
        for(auto p = playerpos.begin(); p != playerpos.end(); p++)
        {
            std::pair<float, float>tmp(mypos.first - p->first, mypos.second - p->second);
            if (tmp.first < 0)
                tmp.first = -tmp.first;
            if (tmp.second < 0)
                tmp.second = -tmp.first;
            if (tmp.first + tmp.second < (mypos.first - close.first+ mypos.second - close.second))
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
        }
        else
        {
            std::cout<< "no player.." <<std::endl;
            ret = 0;
        }
        return (ret);
    }

    std::pair<float, float> getBestMove(std::vector<std::pair<float, float> > playerpos, std::pair<float, float> mypos)
    {
        std::pair<float, float> ret;

        ret.first = -0.4;
        ret.second = getbestY(playerpos, mypos);
        ret.second = ret.second * 0.7;

        return ret;
    }

    //    test() : aLib("testt"){};
};

extern "C" MonsterIa* create() {
    {
        std::cout << "WILL CREATE MONSTERBASIC" << std::endl;
        return new MonsterBasic();
    }
}
extern "C" void destroy(MonsterIa* p) {
    delete p;
}