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

	void	Engine::loadScene(std::shared_ptr<Scene> toAdd)
	{
		sceneInProcess = toAdd;
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
