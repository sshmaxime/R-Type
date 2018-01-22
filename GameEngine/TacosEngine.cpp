#include <chrono>
#include <memory>
#include <thread>
#include <RessourceManager/SfmlWindow.hpp>
#include <RessourceManager/SfmlRenderer.hpp>
#include <InputManagerSFML/InputManagerSFML.h>
#include "TacosEngine.h"

namespace TacosEngine
{
	Engine::Engine(bool displayMode)
		: inGame(true), displayMode(displayMode)
	{
		if (displayMode)
		{
			window = std::make_unique<SfmlWindow>();
			window->InitWindow("TacosEngine Window", TacosEngine::VIDEO_MODE::PARTIAL);
			renderer = std::make_unique<SfmlRenderer>(dynamic_cast<SfmlWindow *>(window.get())->get_window());
		}
		inputManager = std::make_unique<InputManagerSFML>();
		ressources = std::make_shared<RessourceManager>();
	}

	Engine::~Engine()
	{
		if (displayMode)
			window->DeleteWindow();
	}

	void	Engine::initRessources(const std::string &path)
	{
		ressources->init(path);
	}

	void	Engine::addScene(std::shared_ptr<Scene> scene)
	{
		scene->setRessources(ressources);
		scenes.push_back(scene);
	}

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
			this->scenes.push_back(SceneToAdd);
        }
        catch (std::exception &exception2) {
            inFile.close();
            std::cerr << "Error : wrong scene file." << std::endl;
            throw exception2;
        }
        inFile.close();
    }

    void	Engine::loadScene(std::shared_ptr<Scene> toAdd)
    {
        sceneInProcess = std::move(toAdd);
    }

	std::shared_ptr<Scene>	Engine::getSceneInProcess()
	{
		return sceneInProcess;
	}

	void	Engine::run()
	{
		while (inGame)
		{
			processInput();
			physics.update();
            behaviourUpdate();
			if (displayMode)
			{
				renderer->draw(sceneInProcess->getSprites());
			}
			if (inputs.getKey(Key::KEY_ESCAPE))
				inGame = false;
		}
	}

	std::shared_ptr<RessourceManager>	Engine::getRessources()
	{
		return ressources;
	}

	void	Engine::processInput()
	{
		inputManager->setProcessInput(inputs);
	}

	void	Engine::behaviourUpdate()
	{
		std::list<std::shared_ptr<Component>>	compo(sceneInProcess->getComponents());

		for (auto i : compo)
		{
			if (dynamic_cast<Behaviour *>(i.get()))
				dynamic_cast<Behaviour *>(i.get())->update(inputs);
		}
	}
}
