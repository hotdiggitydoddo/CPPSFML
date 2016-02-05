#include <SFML/Graphics.hpp>
#include <iostream>
#include "entity_manager.h"





int main()
{
	EntityManager manager;

	auto& entity(manager.addEntity());

	//entity.addComponent<CounterComponent>();
	//entity.addComponent<KillComponent>();
	
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