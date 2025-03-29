#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Toggle {
public:
    Toggle(float x, float y) {
        background.setSize(sf::Vector2f(60, 30));
        background.setPosition(x, y);
        background.setFillColor(sf::Color(100, 100, 100));

        switchButton.setRadius(14);
        switchButton.setPosition(x + 1, y + 1);
        switchButton.setFillColor(sf::Color(255, 255, 255));

        isOn = false;
    }

    void toggle() {
        isOn = !isOn;
        if (isOn) {
            switchButton.setPosition(background.getPosition().x + background.getSize().x - 2*switchButton.getRadius(), background.getPosition().y + 1);
            background.setFillColor(sf::Color(0, 255, 0));
        }
        else {
            switchButton.setPosition(background.getPosition().x + 1, background.getPosition().y + 1);
            background.setFillColor(sf::Color(100, 100, 100));
        }
    }

    void draw(sf::RenderWindow& window) {
        window.draw(background);
        window.draw(switchButton);
    }

    bool contains(float x, float y) {
        return background.getGlobalBounds().contains(x, y);
    }

private:
    sf::RectangleShape background;
    sf::CircleShape switchButton;
    bool isOn;
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Toggle Switch");

    std::vector<Toggle> toggles;
    for (int i = 0; i < 10; i++) {
        toggles.push_back(Toggle(370, 100 + 50 * i));
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            for (auto& toggle : toggles) {
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (toggle.contains(event.mouseButton.x, event.mouseButton.y)) {
                            toggle.toggle();
                        }
                    }
                }
            }
        }

        window.clear();
        for (auto& toggle : toggles)
            toggle.draw(window);
        window.display();
    }

    return 0;
}