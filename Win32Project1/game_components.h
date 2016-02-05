#pragma once
#include <iostream>
#include "entity.h"
#include <SFML\Graphics.hpp>

namespace ECS
{
	struct CounterComponent : Component
	{
		float counter;
		void update(float dt)  override;
	};

	struct KillComponent : Component
	{
		CounterComponent* counter{ nullptr };

		void init() override;
		void update(float dt) override;
	};

	struct SpatialComponent : Component
	{
		sf::Vector2f position;

		SpatialComponent() = default;
		SpatialComponent(const sf::Vector2f& mPosition) : position{ mPosition } { }

		float x() const noexcept;
		float y() const noexcept;
	};

}
