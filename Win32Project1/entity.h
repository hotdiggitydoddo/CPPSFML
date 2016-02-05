#pragma once
#include <vector>
#include <memory>
#include <assert.h>
#include "component.h"

namespace ECS
{
	class Entity
	{
	public:
		void update(float dt);
		void draw();

		bool isAlive() const;
		void destroy();

		template<typename T, typename... TArgs>
		T& addComponent(TArgs&&... args)
		{
			assert(!hasComponent<T>());

			T* component(new T(std::forward<TArgs>(args)...));
			component->entity = this;
			std::unique_ptr<Component> uPtr{ component };
			components.emplace_back(std::move(uPtr));

			componentArray[getComponentTypeID<T>()] = component;
			componentBitset[getComponentTypeID<T>()] = true;

			component->init();

			return *component;
		}

		template<typename T>
		bool hasComponent() const
		{
			return componentArray[getComponentTypeID<T>()];
		}

		template<typename T>
		T& getComponent() const
		{
			assert(hasComponent<T>());
			auto ptr(componentArray[getComponentTypeID<T>()]);
			return *static_cast<T*>(ptr);
		}

		Entity();
		~Entity();



	private:
		bool alive{ true };
		std::vector<std::unique_ptr<Component>> components;

		ComponentArray componentArray;
		ComponentBitset componentBitset;
	};

	

}

