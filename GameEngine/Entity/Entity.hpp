#pragma once

#include <iostream>
#include <memory>
#include <list>
#include <string>
#include <exception>
#include <type_traits>

namespace TacosEngine
{
	class Entity
	{
	public:
		Entity(const std::string &name) : _name(name) 
		{
			static unsigned int id = 0;

			_id = id;
			id++;
		}
		virtual unsigned int        getInstanceId() { return _id; }
		virtual const std::string   &getInstanceName() { return _name; }
		virtual ~Entity(){}
    
	protected:
		unsigned int _id;
		std::string _name;
	};
}