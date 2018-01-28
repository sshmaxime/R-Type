//
// Created by simon on 27/01/18.
//

#include "SpawnManager.h"
#include "../Behaviours/MonsterIA.h"
#include "../Behaviours/MonsterBossBehaviour.h"
#include <ctime>
#include <cstdlib>

using namespace TacosEngine;

SpawnManager::SpawnManager(const std::string &name, const std::shared_ptr<TacosEngine::GameObject> &object)
        : Behaviour(name, object)
{
    _tick = 450;
    _tickToAdd = 500;
    _loader = std::make_shared<LibLoader>();
    _wayve = 0;
    setOrder("./lvl1.txt");
}

void SpawnManager::Start()
{}

void SpawnManager::setOrder(const std::string &path)
{
    std::ifstream file(path);
    while (file)
    {
        std::string line;
        while (std::getline(file, line, '\n'))
        {
            std::vector<std::pair<std::string, std::string> > toAdd;
            std::string tmp;
            if (!line.empty())
            {
                int space = 0;
                int next = 0;
                int vir = 0;
                while ((next = line.find(' ', space)) != std::string::npos)
                {
                    vir = line.find(':', space);
                    std::string texture = line.substr(vir + 1, next - vir  -1);
                    std::string lib = line.substr(space, vir - space) + LIB_EXT;
                    space = next + 1;
                    toAdd.push_back(std::make_pair(lib, texture));
                }
                _order.push_back(toAdd);
            }
        }
    }
}
void SpawnManager::update(const TacosEngine::Input &)
{
    if (_tick++ > _tickToAdd)
    {
        _tick = 0;
        if (_wayve >= 5)
            return ;
        std::vector<std::pair<std::string, std::string> > toAdd = _order.at(_wayve);
        if (toAdd.empty())
        {
            return;
        }
        for (auto &n : toAdd)
        {
            auto rand = get_random();
            std::string lib = "./libMonster" + n.first;
            std::shared_ptr<Sprite>monster;
            MonsterIa *ia = _loader->LoadLib(lib, _object->getScene());
            if (n.first != std::string("Boss.so"))
            {
                monster = std::make_shared<Sprite>("monster" + this->getGameObjectName(), this->_object->getScene(),
                                                   Layout::SCENE);
                monster->setTexture(_object->getScene()->getTexture(n.second));
                monster->setSize(Vector2(40, 40));
                monster->getTransform().setSpeed(_object->getTransform().getSpeed() + 3);
            }
            else
            {
                monster = std::make_shared<Sprite>("boss" + this->getGameObjectName(), this->_object->getScene(),
                                                   Layout::SCENE);
                monster->setTexture(_object->getScene()->getTexture(n.second));
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