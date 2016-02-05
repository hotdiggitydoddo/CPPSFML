#include <SFML/Graphics.hpp>
#include <iostream>
#include "component.h"
#include "entity.h"
#include "entity_manager.h"


struct CounterComponent : Component
{
	float counter;
	void update(float dt)  override
	{
		counter += dt;
		std::cout << counter << std::endl;
	}
};


struct KillComponent : Component
{
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


int main()
{
	EntityManager manager;

	auto& entity(manager.addEntity());

	entity.addComponent<CounterComponent>();
	entity.addComponent<KillComponent>();
	
	for (auto i(0u); i < 1000; i++)
	{
		manager.refresh();
		manager.update(1.f);
		manager.draw();
	}

	return 0;
}

//int main()
//{
//	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//	sf::CircleShape shape(100.f);
//	shape.setFillColor(sf::Color::Red);
//
//	while (window.isOpen())
//	{
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//
//		window.clear();
//		window.draw(shape);
//		window.display();
//	}
//
//	return 0;
//}