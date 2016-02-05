#pragma once

#include <array>
#include <algorithm>
#include <bitset>


class Entity;

using ComponentID = std::size_t;

inline ComponentID getUniqueComponentID() noexcept
{
    static ComponentID lastId{ 0u };
    return lastId++;
}

struct Component
{
	Entity* entity{ nullptr };

	virtual void init() { }
	virtual void update(float dt) { }
	virtual void draw() { }

	virtual ~Component() { };
};



template<typename T> inline ComponentID getComponentTypeID() noexcept
{
	static_assert(std::is_base_of<Component, T>::value, "T must inherit from Component");

	static ComponentID typeId{ getUniqueComponentId() };
	return typeId;
}

constexpr std::size_t maxComponents{ 32 };

using ComponentBitset = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;