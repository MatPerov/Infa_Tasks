#include <SFML/Graphics.hpp>
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Moving Circle", sf::Style::Default);
    window.setFramerateLimit(60);
    sf::CircleShape circle(70);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(sf::Vector2f(330, 330));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space)
                    circle.setFillColor(sf::Color::Red);
            }
            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Space)
                    circle.setFillColor(sf::Color::Green);
            }
        }

        window.clear(sf::Color(255, 248, 220));
        window.draw(circle);

        window.display();
    }
}
