#pragma once

#include <GameEngine/EventManager/EventManager.hpp>
#include <GameEngine/Animation/Animation.hpp>
#include "TestInput.h"
#include "RessourceManager/RessourceManager.hpp"
#include "Scene/Scene.hpp"
#include "PhysicsEngine/PhysicsEngine.h"
#include "IWindow/IWindow.hpp"
#include "IRenderer/IRenderer.hpp"
#include "Input/Input.h"
#include "InputManager/InputManager.h"
#include "../../Common/JSON/json.hpp"

#define _TICK 0.02

namespace TacosEngine
{
    using json = nlohmann::json;

	class Engine
	{
	private:
		// Ressources
		std::shared_ptr<RessourceManager>	ressources;
	
		// Scenes
		std::list<std::shared_ptr<Scene>>	scenes;
		std::shared_ptr<Scene>				sceneInProcess;
	
		// Physics
		TacosEngine::PhysicsEngine			physics;
	
		// GameLoop
		bool								inGame;

		// Window
		bool								displayMode;
		std::shared_ptr<IWindow>			window;

		// Renderer
		std::unique_ptr<IRenderer>			renderer;

		// Input
		TacosEngine::Input									inputs;
		std::unique_ptr<TacosEngine::InputManager>			inputManager;
		TestInput											test;

		// Event
		std::shared_ptr<EventManager>       eventManager;


	public:
		Engine(bool displayMode = true);
		~Engine();

		void				initRessources(const std::string &path);
		void				addScene(std::shared_ptr<Scene> toAdd);
		void				addScene(const std::string &path);
		void				loadScene(std::shared_ptr<Scene> toLoad);
		void				run();
		std::shared_ptr<Scene>			getSceneInProcess();
		std::shared_ptr<RessourceManager>	getRessources();
		void				behaviourUpdate();
		void				startObjects();
		void				destroyObjects();
		void 				windowEvents();
		void				checkNewScene();
		void				animationUpdate(int);

	private:
		void			processInput();
	};
}
