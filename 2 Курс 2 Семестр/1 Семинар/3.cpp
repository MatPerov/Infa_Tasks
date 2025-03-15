#include <SFML/Graphics.hpp>
int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Rotating Circle", sf::Style::Default);
    window.setFramerateLimit(60);

    sf::CircleShape circle(50);
    circle.setPosition(sf::Vector2f(500, 500));
    circle.setFillColor(sf::Color(112, 128, 144));
    circle.setOrigin(sf::Vector2f{ 250.0f, 50.0f });
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        circle.rotate(1.0f);

        window.clear(sf::Color (255, 248, 220));
        window.draw(circle);

        window.display();
    }
}
