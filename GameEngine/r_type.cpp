// r_type.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "TacosEngine.h"

using namespace TacosEngine;

int main()
{
	Engine	engine;
	std::shared_ptr<Scene>	scene = std::make_shared<Scene>("Scene1");

	engine.initRessources("./ressources.sp");
	engine.addScene(scene);
	if (scene->getTexture("back") != nullptr)
		std::cout << "ok" << std::endl;
	else
		std::cout << "ko" << std::endl;
	std::shared_ptr<Sprite> back = std::make_shared<Sprite>("Con", scene);
	back->setTexture(scene->getTexture("back"));
	scene->addSprite(back);
	engine.loadScene(scene);
	engine.run();
	return 0;
}