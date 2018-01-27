//
// Created by simon on 27/01/18.
//
#include <iostream>
#include <string>
#include <list>
#include "../Behaviours/MonsterIA.h"

class MonsterZig : public MonsterIa
{
public:
    MonsterZig() : MonsterIa()
    {
        m_y = -0.4;
        ampl = 1;
        maxample = 150;
    }
    ~MonsterZig(){}
    std::pair<float, float> getBestMove(float x, float y)
    {
        std::pair<float, float> ret;

        ret.first = -0.3;
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