//
// Created by simon on 27/01/18.
//

#ifndef GAME_SPAWNMANAGER_H
#define GAME_SPAWNMANAGER_H

#include <utility>
#include <functional>
#include <random>
#include "Level.hpp"
#include "../GameEngine/LibLoader/LibLoader.hpp"
#include "../GameEngine/LibLoader/LibLoaderWindows.hpp"



class SpawnManager : public TacosEngine::Behaviour
{
public:
    SpawnManager(const std::string &name, const std::shared_ptr<TacosEngine::GameObject> &object);
    void setTick(int ntick);
    void setOrder(const std::string &path);

    float get_random()
    {
        static std::default_random_engine e;
        static std::uniform_real_distribution<> dis(0, 400);
        return static_cast<float>(dis(e));
    }
private:
    void Start() override;

    void update(const TacosEngine::Input &) override;
    int _tick;
    int _tickToAdd;
    int _wayve;
    std::vector<std::vector<std::pair<std::string, std::string> > > _order;
#ifndef WIN32
    std::shared_ptr<LibLoader> _loader;
#else
    std::shared_ptr<LibLoaderWindows> _loader;
#endif
};


#endif //GAME_SPAWNMANAGER_H
