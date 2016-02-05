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




