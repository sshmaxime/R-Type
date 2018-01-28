//
// Created by simon on 27/01/18.
//

#ifndef GAME_SPAWNMANAGER_H
#define GAME_SPAWNMANAGER_H

#include "Level.hpp"
#include "../GameEngine/LibLoader/LibLoader.hpp"

#define LIB_EXT ".so"
class SpawnManager : public TacosEngine::Behaviour
{
public:
    SpawnManager(const std::string &name, const std::shared_ptr<TacosEngine::GameObject> &object, std::shared_ptr<Level> Level);
    void setTick(int ntick);
    void setOrder(const std::string &path);

private:
    void Start() override;

    void update(const TacosEngine::Input &) override;
    std::shared_ptr<Level> _Level;
    int _tick;
    int _tickToAdd;
    int _wayve;
    std::vector<std::vector<std::string> > _order;
    std::shared_ptr<LibLoader> _loader;

};


#endif //GAME_SPAWNMANAGER_H
