//
// Created by Corentin on 28/01/2018.
//

#ifndef R_TYPE_ILIBRARY_HPP
#define R_TYPE_ILIBRARY_HPP


#include "../../Behaviours/MonsterIA.h"
#include "../Scene/Scene.hpp"

#ifdef WIN32
# define LIB_EXTENSION ".dll"
# define LIB_PREFIX ""
#else
# define LIB_EXTENSION ".so"
# define LIB_PREFIX "lib"
#endif

class ILibrary {

public:
    virtual ~ILibrary() = default;
    virtual MonsterIa *LoadLib(const std::string &pathlib, std::shared_ptr<TacosEngine::Scene> scene) = 0;
};


#endif //R_TYPE_ILIBRARY_HPP
