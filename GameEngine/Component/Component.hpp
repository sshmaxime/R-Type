#pragma once

#include "Entity.hpp"
#include "Sprite.hpp"

namespace TacosEngine
{
	// Fix : inclusion multiple
	class Sprite;

	class Component : public Entity
	{
		public:
			Component(const std::string &myname, std::shared_ptr<Sprite> sprite);
			virtual ~Component(){};
			std::shared_ptr<Sprite> getSprite();
			void addSprite(std::shared_ptr<Sprite> toAdd);
			const std::string &getSpriteName();
			bool  isSprited();

			template <typename T>
			std::shared_ptr<T> getComponent()
			{
				return _sprite->getComponent<T>();
			}

		protected:
			std::shared_ptr<Sprite> _sprite;
	};
}