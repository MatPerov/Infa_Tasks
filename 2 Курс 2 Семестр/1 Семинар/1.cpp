#include <SFML/Graphics.hpp>
int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Moving Circle", sf::Style::Default);
    window.setFramerateLimit(60);

    sf::CircleShape circle(50);
    circle.setPosition(sf::Vector2f(500, 500));
    circle.setFillColor(sf::Color(112, 128, 144));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        circle.move(sf::Vector2f{ 2, 0 });
        sf::Vector2f max = window.getView().getSize();
        if (circle.getPosition().x - circle.getRadius() > max.x)
            circle.move({ -max.x - 3 * circle.getRadius(), 0 });
        window.clear(sf::Color(255, 248, 220));
        window.draw(circle);

        window.display();
    }
}
