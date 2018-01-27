#include "LibLoader.hpp"

LibLoader::LibLoader()
{
  _libHistoric = std::list<MonsterIa *>();
}

LibLoader::~LibLoader()
{
}

//std::shared_ptr<MonsterIa> LibLoader::LoadLib(const std::string &pathlib, std::shared_ptr<TacosEngine::Scene> scene)
MonsterIa *LibLoader::LoadLib(const std::string &pathlib, std::shared_ptr<TacosEngine::Scene> scene)
{
  void *handle = dlopen(pathlib.c_str(), RTLD_LAZY);
  if (!handle)
    {
      std::cerr << "Cannot open library: " << dlerror() << std::endl;
      return nullptr;
    }
  dlerror();

  create_t *create = (create_t *) dlsym(handle, "create");
  char *dlsym_error = dlerror();
  if (dlsym_error)
    {
      std::cout << "Cannot load symbol create: " << dlsym_error << '\n';
      return nullptr;
    }

  destroy_t *destroy = (destroy_t *) dlsym(handle, "destroy");
  dlsym_error = dlerror();
  if (dlsym_error)
    {
      std::cout << "Cannot load symbol destroy: " << dlsym_error << '\n';
      return nullptr;
    }

  auto l = create();
  //    l->draw();
  //  l->update();
  _libHistoric.push_back(l);
  return (l);
}
/*MAIN DE TEST
int main()
{
    TacosEngine::LibLoader l;
    TacosEngine::Behaviour *al = l.LoadLib("./test.so");
    al->draw();
    al->onCollide();
}*/