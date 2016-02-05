#include "entity.h"
#include "component.h"

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

template<typename T, typename... TArgs>
T& Entity::addComponent(TArgs&&... args)
{
	assert(!hasComponent<T>());

	T* component(new T(std::forward<TArgs>(args)...));
	component->entity = this;
	std::unique_ptr<Component> uPtr{ component };
	components.emplace_back(std::move(uPtr));

	componentArray[getComponentTypeID<T>()] = component;
	componentBitset[getComponentTypeID<T>] = true;

	component->init();

	return *component;
}

template<typename T>
T& Entity::getComponent() const
{
	assert(hasComponent<T>());
	auto ptr(componentArray[getComponentTypeID<T>()]);
	return *static_cast<T*>(ptr);
}

Entity::Entity()
{
}

Entity::~Entity()
{
}