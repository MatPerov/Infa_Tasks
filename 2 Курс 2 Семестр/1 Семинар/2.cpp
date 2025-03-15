#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Rotating Square", sf::Style::Default);
	window.setFramerateLimit(60);

	sf::RectangleShape rectangle(sf::Vector2f(200.0f, 200.0f));
	rectangle.setOrigin(sf::Vector2f{ 100.0f, 100.0f });
	rectangle.setPosition(sf::Vector2f{ 400, 400 });
	rectangle.setFillColor(sf::Color(255, 215, 0));
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::White);
		rectangle.rotate(0.3f);
		window.draw(rectangle);
		window.display();
	}
}
