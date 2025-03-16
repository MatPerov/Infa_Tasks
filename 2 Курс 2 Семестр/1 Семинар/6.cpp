#include <SFML/Graphics.hpp>
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Moving Circle", sf::Style::Default);
    window.setFramerateLimit(60);
    sf::CircleShape circle(30);
    circle.setPosition(sf::Vector2f(100, 100));
    circle.setFillColor(sf::Color(165, 42, 42));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            circle.move(sf::Vector2f{ 0, -1 });
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            circle.move(sf::Vector2f{ 1, 0 });
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            circle.move(sf::Vector2f{ -1, 0 });
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            circle.move(sf::Vector2f{ 0, 1 });

        window.clear(sf::Color(255, 248, 220));
        window.draw(circle);

        window.display();
    }
}
