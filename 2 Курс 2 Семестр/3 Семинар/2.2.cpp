#include <SFML/Graphics.hpp>
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Color Change Rectangle");
    window.setFramerateLimit(60);

    sf::RectangleShape rec(sf::Vector2f {150,300});
    rec.setFillColor(sf::Color::Green);
    rec.setPosition(sf::Vector2f{ 325,250 });
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseMoved)
                if (rec.getGlobalBounds().contains(window.mapPixelToCoords(sf::Vector2i {event.mouseMove.x, event.mouseMove.y})))
                    rec.setFillColor(sf::Color::Red);
                else
                    rec.setFillColor(sf::Color::Green);
        }
        window.clear(sf::Color(255, 248, 220));
        window.draw(rec);
        window.display();
    }
}
