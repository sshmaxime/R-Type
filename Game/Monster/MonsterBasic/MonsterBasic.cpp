//
// Created by simon on 26/01/18.
//
#include <iostream>
#include <string>
#include <list>
#include "../Behaviours/MonsterIA.h"

class MonsterBasic : public MonsterIa
{
public:
    MonsterBasic() : MonsterIa()
    {
    }
    ~MonsterBasic(){}
    std::pair<float, float> getBestMove(float x, float y)
    {
        std::pair<float, float> ret;

        ret.first = -0.4;
        ret.second = 0;
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