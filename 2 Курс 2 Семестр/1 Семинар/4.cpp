#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Rotating Text", sf::Style::Default);
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("ofont.ru_Caesar Dressing.ttf")) //файл шрифта есть в папке.
    {
        std::cout << "Error! Can't load font!" << std::endl;
        std::exit(1);
    }

    sf::Text text;
    text.setFont(font);
    text.setString(L"Привет Мир!");
    text.setCharacterSize(50);
    text.setFillColor(sf::Color(165, 42, 42));
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text.setPosition({ 275, 350 });

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color (255, 248, 220));
        window.draw(text);

        window.display();
    }
}
