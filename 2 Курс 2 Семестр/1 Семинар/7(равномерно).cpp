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
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i mousePixel = sf::Mouse::getPosition(window);
            sf::Vector2f mousePosition = window.mapPixelToCoords(mousePixel);
            float Vx = mousePosition.x - circle.getPosition().x;
            float Vy = mousePosition.y - circle.getPosition().y;
            circle.move(sf::Vector2f{ Vx * 3 / sqrt(Vx*Vx+Vy*Vy), Vy * 3 / sqrt(Vx * Vx + Vy * Vy) });
        }

        window.clear(sf::Color(255, 248, 220));
        window.draw(circle);

        window.display();
    }
}
