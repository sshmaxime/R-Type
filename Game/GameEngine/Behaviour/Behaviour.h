#pragma once

#include <GameEngine/Scene/Scene.hpp>
#include "../Input/Input.h"

namespace TacosEngine
{
	class Behaviour : public Component
	{
	private:
		bool 	start;
		bool	destroy;
	public:
		Behaviour(const std::string &name, std::shared_ptr<GameObject> object);
		~Behaviour() override;
		virtual void Start();
		virtual void update(const Input &input);
		virtual void onCollide(GameObject &other);
		bool	isStarted() const;
		void	setStart(bool);
		bool 	toDestroy() const;
		void	setDestroy(bool);
	};
}