#include "entity.h"

namespace ECS 
{
	void Entity::update(float dt)
	{
		for (auto& c : components)
			c->update(dt);
	}

	void Entity::draw()
	{
		for (auto& c : components)
			c->draw();
	}

	bool Entity::isAlive() const
	{
		return alive;
	}

	void Entity::destroy()
	{
		alive = false;
	}

	
	

	Entity::Entity()
	{
	}

	Entity::~Entity()
	{
	}
}

