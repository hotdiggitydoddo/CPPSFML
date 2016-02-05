#pragma once
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include "entity.h"

class EntityManager
{
public:
	EntityManager();
	~EntityManager();

	void update(float dt);
	void draw();
	void refresh();

	Entity& addEntity();

private:
	std::vector<std::unique_ptr<Entity>> entities;
};



class CounterComponent : Component
{
public:
	float counter;
	void update(float dt)  override
	{
		counter += dt;
		std::cout << counter << std::endl;
	}
};


class KillComponent : Component
{
public:
	CounterComponent* counter{ nullptr };

	void init() override
	{
		counter = &entity->getComponent<CounterComponent>();
	}

	void update(float dt) override
	{
		if (counter->counter >= 100)
			entity->destroy();
	}
};
