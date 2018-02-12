//
// Created by Corentin on 28/01/2018.
//

#ifdef WIN32

#include "LibLoaderWindows.hpp"

MonsterIa *LibLoaderWindows::LoadLib(const std::string &pathlib, std::shared_ptr<TacosEngine::Scene> scene)
{
    HMODULE myDLL = LoadLibrary(pathlib.c_str());
    if (myDLL)
        std::cout << "Dll loaded" << std::endl;
    if (!myDLL)
    {
        throw std::exception();
    }
    fun_ptr function = (fun_ptr) GetProcAddress(myDLL, "create");
    auto ia = function();
    return (ia);
}

#endif