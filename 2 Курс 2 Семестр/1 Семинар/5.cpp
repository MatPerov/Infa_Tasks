#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Circle and Mouse");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        sf::Font font;
        sf::Text text;
        text.setFont(font);
        if (!font.loadFromFile("ofont.ru_Caesar Dressing.ttf"))
        {
            std::cout << "Error! Can't load font!" << std::endl;
            std::exit(1);
        }
        text.setCharacterSize(35);
        text.setFillColor(sf::Color(165, 42, 42));
        text.setStyle(sf::Text::Bold);
        text.setPosition({ 60, 350 });
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Vector2i mousePixel = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosition = window.mapPixelToCoords(mousePixel);
        text.setString(std::to_string(mousePixel.x)+" -- " + std::to_string(mousePixel.y) + "      " + std::to_string(mousePosition.x) + " -- " + std::to_string(mousePosition.y));
        window.clear(sf::Color(255, 248, 220));
        window.draw(text);
        window.display();
    }
}
