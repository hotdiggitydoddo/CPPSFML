#pragma once
#include <vector>
#include <memory>
#include <assert.h>
#include "component.h"

class Entity
{
public:
	void update(float dt);
	void draw();

	bool isAlive() const;
	void destroy();

	template<typename T, typename... TArgs>
	T& addComponent(TArgs&&... args);

	template<typename T> 
	bool hasComponent() const;

	template<typename T>
	T& getComponent() const;

	Entity();
	~Entity();



private:
	bool alive{ true };
	std::vector<std::unique_ptr<Component>> components;

	ComponentArray componentArray;
	ComponentBitset componentBitset;
};

