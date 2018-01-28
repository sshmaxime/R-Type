#include <chrono>
#include <memory>
#include <thread>

#include "TacosEngine.h"
#include "RessourceManager/SfmlWindow.hpp"
#include "SfmlRenderer/SfmlRenderer.hpp"
#include "InputManagerSFML/InputManagerSFML.h"
#include "Behaviour/Behaviour.h"
#include "Animation/Animation.hpp"
#include "../../Client/Global/CGlobal.h"

namespace TacosEngine
{
  Engine::Engine(bool displayMode)
	  : inGame(true), displayMode(displayMode)
  {
    if (displayMode)
      {
	window = std::make_shared<SfmlWindow>();
	window->InitWindow("TacosEngine Window", TacosEngine::VIDEO_MODE::PARTIAL);
	renderer = std::make_unique<SfmlRenderer>(dynamic_cast<SfmlWindow *>(window.get())->get_window());
      }
    inputManager = std::make_unique<InputManagerSFML>();
    ressources = std::make_shared<RessourceManager>();
    eventManager = std::make_shared<EventManager>();
  }

  Engine::~Engine()
  {
    if (displayMode)
      window->DeleteWindow();
  }

  void Engine::initRessources(const std::string &path)
  {
    std::ifstream file(path);

    if (file.fail())
      throw std::invalid_argument("Can't open file in path:" + path);
    else
      {
	file.close();
	ressources->init(path);
      }
  }

  void Engine::addScene(std::shared_ptr<Scene> scene)
  {

    if (displayMode)
      {
	sf::RenderWindow *win;
	win = dynamic_cast<SfmlWindow *>(window.get())->get_window();
	scene->setWindowSize(
	    Vector2(static_cast<float>(win->getPosition().x), static_cast<float>(win->getPosition().y)));
      }
    scene->setRessources(ressources);
    scenes.push_back(scene);
  }

  /*
      void Engine::addScene(const std::string &path){
      json                            JSON;
      std::ifstream 					inFile;
      std::stringstream               scene;

      try {
      inFile.open(path);
      }
      catch (std::exception &exception1) {
      std::cout << "Failure while opening " << path << " file." << std::endl;
      throw exception1;
      }

      // read the file
      scene << inFile.rdbuf();
      std::string str = scene.str();
      JSON = json::parse(scene);

      // get the name of the sprites to Add
      try {
      //std::shared_ptr<Scene> SceneToAdd = new Scene(JSON["scene"]["details"]["name"]);
      std::string test = JSON["scene"]["details"]["name"];
      std::shared_ptr<Scene> SceneToAdd = std::make_shared<Scene>(test);
      // Dé-commenter après l'ajout du game
      /*std::string difficulty;
      int level;
      int nbEnemies;
      difficulty = JSON["scene"]["details"]["difficulty"];
      level = std::stoi(std::string(JSON["scene"]["details"]["level"]));
      nbEnemies = std::stoi(std::string(JSON["scene"]["details"]["nbEnemies"]));*/

  /*
      for (auto &it : JSON["scene"]["sprites"])
    {

      std::string name = it;
      std::shared_ptr<Sprite> spriteToAdd = std::make_shared<Sprite>(name, SceneToAdd, Layout::SCENE);
      spriteToAdd->addTexture(this->ressources->getTexture(name));
      SceneToAdd->addSprite(spriteToAdd);
      }

      // Dé-commenter après l'ajout des événements
      /*for (auto it = JSON["scene"]["events"].begin(); it != JSON["scene"]["events"].end(); it++)
      {
      std::string                 name = *it;
      std::shared_ptr<Event>     eventToAdd = new Event(name);
      SceneToAdd->addEvent(eventToAdd);
      }*/
  /*
	  this->scenes.push_back(SceneToAdd);
      }
      catch (std::exception &exception2) {
      inFile.close();
      std::cerr << "Error : wrong scene file." << std::endl;
      throw exception2;
      }
      inFile.close();
  }*/

  void Engine::loadScene(std::shared_ptr<Scene> toAdd)
  {
    sceneInProcess = std::move(toAdd);
  }

  std::shared_ptr<Scene> Engine::getSceneInProcess()
  {
    return sceneInProcess;
  }

  void Engine::run()
  {
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    std::chrono::high_resolution_clock::time_point t2;
    std::chrono::high_resolution_clock::time_point t3 = std::chrono::high_resolution_clock::now();
    int curent_tick = 0;

    while (inGame)
      {
	t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(
		t2 - t1);
	//std::cout << "TIME : " << time_span.count() << std::endl;
	if (displayMode)
	  {
	    windowEvents();
	  }
	processInput();
	if (time_span.count() > _TICK)
	  {
	    if (curent_tick >= _TICK * 100)
	      {
		curent_tick = 0;
	      }
	    curent_tick = curent_tick + 1;
	    startObjects();
	    physics.update(sceneInProcess->getGameObjects());
	    //this->getEventManager()->eventUpdate(this->sceneInProcess);
	    behaviourUpdate();
	    animationUpdate(curent_tick);
	    if (displayMode)
	      {
		renderer->draw(sceneInProcess->getGameObjects());
	      }
	    destroyObjects();
	    if (inputs.getKey(Key::KEY_ESCAPE))
	      {
		inGame = false;
	      }
	    checkNewScene();
	    t1 = std::chrono::high_resolution_clock::now();
	  }
      }
  }

  void Engine::windowEvents()
  {
    sf::RenderWindow *window = std::dynamic_pointer_cast<SfmlWindow>(this->window)->get_window();
    sf::Event event;

    window->pollEvent(event);
    if (event.type == sf::Event::EventType::Closed)
      {
	this->inGame = false;
      } else
      if (event.type == sf::Event::EventType::Resized)
	{
	  sceneInProcess->setWindowSize(
		  Vector2(static_cast<float>(window->getPosition().x), static_cast<float>(window->getPosition().y)));
	}
  }

  std::shared_ptr<RessourceManager> Engine::getRessources()
  {
    return ressources;
  }

  void Engine::processInput()
  {
    inputManager->setProcessInput(inputs);
  }

  void Engine::behaviourUpdate()
  {
    std::list<std::shared_ptr<Component>> compo(sceneInProcess->getComponents());

    for (const auto &i : compo)
      {
	auto behaviour = std::dynamic_pointer_cast<Behaviour>(i);
	if (behaviour && behaviour->isActive())
	  behaviour->update(inputs);
      }
  }

  void Engine::animationUpdate(int tick)
  {
    std::list<std::shared_ptr<Component>> compo(sceneInProcess->getComponents());

    for (const auto &i : compo)
      {
	auto animation = std::dynamic_pointer_cast<Animation>(i);
	if (animation && animation->isActive())
	  animation->update(tick);
      }
  }

  void Engine::startObjects()
  {
    sceneInProcess->startObjects();
  }

  void Engine::destroyObjects()
  {
    sceneInProcess->destroyObjects();
  }

  void Engine::checkNewScene()
  {
    if (sceneInProcess->isNewScene())
      {
	std::string newScene = sceneInProcess->getNewSceneName();
	for (auto &scene : scenes)
	  {
	    if (scene->getName() == newScene)
	      loadScene(scene);
	  }
      }
  }

  const std::shared_ptr<EventManager> &Engine::getEventManager() const
  {
    return eventManager;
  }
}
