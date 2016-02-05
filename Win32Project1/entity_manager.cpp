#include "entity_manager.h"

namespace ECS
{
	EntityManager::EntityManager() {}
	EntityManager::~EntityManager() {}

	void EntityManager::update(float dt)
	{
		for (auto& e : entities)
			e->update(dt);
	}

	void EntityManager::draw()
	{
		for (auto& e : entities)
			e->draw();
	}

	void EntityManager::refresh()
	{
		entities.erase(
			std::remove_if(std::begin(entities), std::end(entities),
				[](const std::unique_ptr<Entity>& entity)
		{
			return !entity->isAlive();
		}),
			std::end(entities));
	}

	Entity& EntityManager::addEntity()
	{
		Entity* e{ new Entity{} };
		std::unique_ptr<Entity> uPtr{ e };
		entities.emplace_back(std::move(uPtr));

		return *e;
	}
}

