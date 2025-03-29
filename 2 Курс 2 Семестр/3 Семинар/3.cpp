#include <SFML/Graphics.hpp>
#include <random>
sf::Color getRandomColor()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> d(0, 255);
    uint8_t a1 = d(gen);
    uint8_t a2 = d(gen);
    uint8_t a3 = d(gen);
    return sf::Color{ a1, a2, a3 };
}
class Ball
{
private:
    sf::RenderWindow& mRenderWindow;
    sf::Vector2f mPosition{};
    sf::Vector2f mVelocity{};
    float mRadius{};
public:
    sf::Color color = sf::Color::White;
    Ball(sf::RenderWindow& window) : mRenderWindow{ window } {}

    void draw() const
    {
        static sf::CircleShape circle;
        circle.setFillColor(color);
        circle.setRadius(mRadius);
        circle.setOrigin({ mRadius, mRadius });
        circle.setPosition(mPosition);
        mRenderWindow.draw(circle);
    }
    void setPosition(sf::Vector2f position) { mPosition = position; }
    void setVelocity(sf::Vector2f velocity) { mVelocity = velocity; }
    void setRadius(float radius) { mRadius = radius; }
    sf::Vector2f getPosition() const { return mPosition; }
    sf::Vector2f getVelocity() const { return mVelocity; }
    float        getRadius()   const { return mRadius; }
};
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Color Change Rectangle");
    window.setFramerateLimit(60);
    float dt = 1.0f / 60;

    std::vector<Ball> balls;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                Ball ball{ window };
                ball.setRadius(20);
                ball.setPosition(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
                balls.push_back(ball);
            }
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Space) {
                    for (auto& ball : balls)
                        ball.color = getRandomColor();
                }
            }
        }
        window.clear(sf::Color::Black);
        for (auto& ball : balls)
            ball.draw();
        window.display();
    }
}
