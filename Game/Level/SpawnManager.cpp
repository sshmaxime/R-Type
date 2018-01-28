//
// Created by simon on 27/01/18.
//

#include "SpawnManager.h"
#include "../Behaviours/MonsterIA.h"
#include "../Behaviours/MonsterBossBehaviour.h"
#include <ctime>
#include <cstdlib>

using namespace TacosEngine;

SpawnManager::SpawnManager(const std::string &name, const std::shared_ptr<TacosEngine::GameObject> &object, std::shared_ptr<Level> Level)
 : Behaviour(name, object)
{
    _Level = Level;
    _tick = 0;
    _tickToAdd = 300;
    _order = std::vector<std::vector<std::string> >();
    _loader = std::make_shared<LibLoader>();
    _wayve = 0;
    std::srand(std::time(nullptr));
    setOrder("./lvl1.txt");
    std::cout << "spawn create" <<std::endl;
}
void SpawnManager::Start()
{}
void SpawnManager::setOrder(const std::string &path)
{
    std::ifstream file(path);
    while (file)
    {
        std::string line;
        while (std::getline(file, line, '\n')) {
            bool ok = true;
            auto toAdd = std::vector<std::string>();
            std::string tmp;
            if (!line.empty()) {
                std::cout << "OKnewline:[" << line << ']' << std::endl;
                int space = 0;
                int next = 0;
                while ((next = line.find(' ', space)) != std::string::npos) {
                    std::string lib = line.substr(space, next - space);
                    std::cout << "will add:[" << "./libMonster" + lib + LIB_EXT << "]" << std::endl;
                    toAdd.push_back(lib + LIB_EXT);
                    space = next + 1;
                }
                _order.push_back(toAdd);
            }
            else
                ok = false;
        }
        }
    }
void SpawnManager::update(const TacosEngine::Input &)
{
    if (_tick++ > _tickToAdd)
    {

        _tick = 0;
        if (_wayve > 5)
            return ;
        std::vector<std::string> toAdd = _order.at(_wayve);
        if (toAdd.empty()) {
            std::cout << "SPOWNER BUGG" << std::endl;
            return;
        std::cout << "spawn!!" << _order.size() << " wayve size" << toAdd.size()<<std::endl;
        }
        for(auto n = toAdd.begin(); n != toAdd.end(); n++)
        {
            float rand = std::rand() % 400;
            std::string lib = "./libMonster" + *n;
//            std::cout << "lib:" <<lib<< std::endl;
            std::shared_ptr<Sprite>monster;
            MonsterIa *ia = _loader->LoadLib(lib, _Level->get_scene());
            if (*n != "Boss")
            {
                monster = std::make_shared<Sprite>("monster" + this->getGameObjectName(), this->_object->getScene(),
                                                   Layout::SCENE);
                monster->setTexture(_object->getScene()->getTexture("crab"));
                monster->setSize(Vector2(40, 40));
                monster->getTransform().setSpeed(_object->getTransform().getSpeed() + 3);
            }
            else
            {
                monster = std::make_shared<Sprite>("boss" + this->getGameObjectName(), this->_object->getScene(),
                                                Layout::SCENE);
                monster->setTexture(_object->getScene()->getTexture("crab"));
                monster->setSize(Vector2(140, 140));

            }
            monster->getTransform().setSpeed(_object->getTransform().getSpeed() + 3);
            monster->getTransform().setPosition(Vector2(700, rand));
            auto col = std::make_shared<Collider>("Collider" + monster->getInstanceName(), monster, monster->getSize(),
                                                      monster->getTransform().getPosition(), true);
            auto rbody = std::make_shared<Rigidbody>("Rigidbody" + monster->getInstanceName(), monster);
            auto beha = std::make_shared<MonsterBehaviour>("monsterbeha" + monster->getInstanceName(), monster,ia);
            this->_object->getScene()->addGameObject(monster);
            this->_object->getScene()->addComponent(col);
            this->_object->getScene()->addComponent(rbody);
            this->_object->getScene()->addComponent(beha);
            }
        _wayve++;
    }
}