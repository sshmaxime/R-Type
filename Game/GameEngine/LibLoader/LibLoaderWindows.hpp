//
// Created by Corentin on 28/01/2018.
//

#ifndef R_TYPE_LIBLOADERWINDOWS_HPP
#define R_TYPE_LIBLOADERWINDOWS_HPP

#ifdef WIN32

#include <windows.h>
#include "ILibrary.hpp"

typedef MonsterIa *(*fun_ptr)();

class LibLoaderWindows : public ILibrary
{
public:
    LibLoaderWindows() = default;
    ~LibLoaderWindows() = default;
    MonsterIa *LoadLib(const std::string &pathlib, std::shared_ptr<TacosEngine::Scene> scene) override;
};

#endif //WIN32
#endif //R_TYPE_LIBLOADERWINDOWS_HPP
