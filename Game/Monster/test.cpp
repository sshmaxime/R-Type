/*#include <iostream>
#include <string>
#include <list>
#include "../Behaviours/MonsterIA.h"

class MonsterBasic : public MonsterIa
{
    public:
    MonsterBasic() : MonsterIa()
    {m_y = 1;}
    ~MonsterBasic(){}
    std::pair<float, float> getBestMove(float x, float y)
    {
        std::cout << "MONSTERBASIC x" <<x<<"y"<<y<<std::endl;
        std::pair<float, float> ret;

        ret.first = -0.3;
        ret.second = 0;
/*        if (y < 30)
            ret.second = -1;
        else if (y > _leny - 30)
            ret.second = 1;
        else
            ret.second = m_y;
        m_y = ret.second;
        return ret;
    }

private:
    float m_y;
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
}*/