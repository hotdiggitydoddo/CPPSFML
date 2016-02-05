#include "game_components.h"
#include "entity.h"

namespace ECS
{
	void CounterComponent::update(float dt)
	{
		counter += dt;
		std::cout << counter << std::endl;
	}

	void KillComponent::init()
	{
		counter = &entity->getComponent<CounterComponent>();
	}

	void KillComponent::update(float dt)
	{
		if (counter->counter >= 100)
			entity->destroy();
	}

	float SpatialComponent::x()
	{
		return position.x;
	}

	float SpatialComponent::y()
	{
		return position.y;
	}
}
