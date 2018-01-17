#pragma once

#include "Component.hpp"
#include "Scene.hpp"
#include "ITexture.hpp"
#include "Transform.h"

namespace TacosEngine
{
	// Fix : inclusion multiple
	class Scene;
	class Component;

	class Sprite : public Entity
	{
		public:         
			Sprite(const std::string &myname, std::shared_ptr<Scene> scene);
			virtual ~Sprite(){};
			void setScene(std::shared_ptr<Scene> scene);

			template<typename T>
			std::shared_ptr<T> getComponent()
			{
				return (_scene->getComponent<T>(_id));
			}

			std::list<std::shared_ptr<Component>> getComponentList();

			void setTexture(ITexture *text)
			{
				_texture = text;
			}

			void	*getTexture()
			{
				return _texture->getTexture();
			}

			Transform	getTransform()
			{
				return _transform;
			}

		private:
		    Transform                   _transform;
	//      Tag                         _tag;
			ITexture					*_texture;
	//      Layout                      _layout;
			std::shared_ptr<Scene>      _scene;
	};
}