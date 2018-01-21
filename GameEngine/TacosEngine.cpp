#include "TacosEngine.h"
#include <chrono>
#include <thread>



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
            std::shared_ptr<Scene> SceneToAdd = new Scene(JSON["scene"]["details"]["name"]);

            // Dé-commenter après l'ajout du game
            /*std::string difficulty;
            int level;
            int nbEnemies;
            difficulty = JSON["scene"]["details"]["difficulty"];
            level = std::stoi(std::string(JSON["scene"]["details"]["level"]));
            nbEnemies = std::stoi(std::string(JSON["scene"]["details"]["nbEnemies"]));*/


            for (auto it = JSON["scene"]["sprites"].begin(); it != JSON["scene"]["sprites"].end(); it++) {

                std::string name = *it;
                std::shared_ptr<Sprite> spriteToAdd = new Sprite(name, SceneToAdd);
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
        }
        catch (std::exception &exception2) {
            inFile.close();
            std::cerr << "Error : wrong scene file." << std::endl;
            throw exception2;
        }
        inFile.close();
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
			test.update(inputs);
			if (displayMode)
			{
				renderer->draw(sceneInProcess->getSprites());
				std::cout << "Drawing" << std::endl;
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
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
}
