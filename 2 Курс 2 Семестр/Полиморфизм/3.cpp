#include <iostream>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <cstdint>
#include <iomanip>

class Widget
{
public:
    virtual bool handleEvent(const sf::Event& event) = 0;
    virtual void draw() const = 0;
    virtual ~Widget() {}
};
class Slider : public Widget
{
protected:
    sf::RectangleShape mTrackShape{};
    sf::RectangleShape mThumbShape{};

    // Когда слайдер находится в нажатом состоянии, 
    // то isPressed = true (Пользователь зажал thumb и держит)
    bool mIsPressed{ false };

    // Также храним ссылку на окно SFML, на которое будем отрисовывать слайдер
    // Эту ссылку можно было не хранить, а просто передавать во все функции,
    // где окно понадобится, но тогда код был бы более громоздким
    sf::RenderWindow& mRenderWindow;

public:
    Slider(sf::RenderWindow& window, sf::Vector2f centerPosition, sf::Vector2f trackSize, sf::Vector2f thumbSize)
        : mRenderWindow(window)
    {
        mTrackShape.setSize(trackSize);
        mTrackShape.setOrigin(trackSize / 2.0f);
        mTrackShape.setPosition(centerPosition);
        mTrackShape.setFillColor({ 200, 200, 220 });

        mThumbShape.setSize(thumbSize);
        mThumbShape.setOrigin(thumbSize / 2.0f);
        mThumbShape.setPosition(centerPosition);
        mThumbShape.setFillColor({ 150, 150, 240 });
    }

    void draw() const override
    {
        mRenderWindow.draw(mTrackShape);
        mRenderWindow.draw(mThumbShape);
    }

    void setRestrictedThumbPosition(sf::Vector2f position)
    {
        float min = mTrackShape.getPosition().x - mTrackShape.getSize().x / 2.0f;
        float max = mTrackShape.getPosition().x + mTrackShape.getSize().x / 2.0f;
        mThumbShape.setPosition({ std::clamp(position.x, min, max), mThumbShape.getPosition().y });
    }

    bool onMousePressed(const sf::Event& event)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2f mousePosition = mRenderWindow.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
            if (mThumbShape.getGlobalBounds().contains(mousePosition) || mTrackShape.getGlobalBounds().contains(mousePosition))
            {
                mIsPressed = true;
                setRestrictedThumbPosition({ mousePosition.x, mThumbShape.getPosition().y });
            }
        }
        return mIsPressed;
    }

    void onMouseMove(const sf::Event& event)
    {
        if (!mIsPressed)
            return;

        sf::Vector2f mousePosition = mRenderWindow.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y });
        setRestrictedThumbPosition(mousePosition);
    }

    void onMouseReleased()
    {
        mIsPressed = false;
    }

    // Нужно вызвать лишь этот метод в цикле обработки событий.
    // Возвращает true, если за время последнего кадра произошло нажатие на ползунок.
    bool handleEvent(const sf::Event& event) override
    {
        bool result = false;

        if (event.type == sf::Event::MouseMoved)
            onMouseMove(event);
        else if (event.type == sf::Event::MouseButtonPressed)
            result = onMousePressed(event);
        else if (event.type == sf::Event::MouseButtonReleased)
            onMouseReleased();

        return result;
    }

    bool isPressed() const
    {
        return mIsPressed;
    }

    float getValue() const
    {
        float start = mTrackShape.getPosition().x - mTrackShape.getSize().x / 2.0f;
        float finish = mTrackShape.getPosition().x + mTrackShape.getSize().x / 2.0f;
        float position = mThumbShape.getPosition().x;
        return 100.0f * (position - start) / (finish - start);
    }

};



class Draggable : public Widget
{
protected:
    sf::RectangleShape mShape{};
    bool mIsDragged{ false };
    sf::Vector2f mOffset{ 0.0f, 0.0f };
    sf::RenderWindow& mRenderWindow;

public:
    Draggable(sf::RenderWindow& window, sf::Vector2f position, sf::Vector2f size, sf::Color color)
        : mRenderWindow(window)
    {
        mShape.setPosition(position);
        mShape.setSize(size);
        mShape.setFillColor(color);
    }

    bool onMousePressed(sf::Vector2f mousePosition)
    {
        if (mShape.getGlobalBounds().contains(mousePosition))
        {
            mIsDragged = true;
            mOffset = mousePosition - mShape.getPosition();
        }
        return mIsDragged;
    }

    void onMouseReleased()
    {
        mIsDragged = false;
    }

    void onMouseMoved(sf::Vector2f mousePosition)
    {
        if (mIsDragged)
            mShape.setPosition(mousePosition - mOffset);
    }

    bool handleEvent(const sf::Event& event) override
    {
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2f mousePosition = mRenderWindow.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
            return onMousePressed(mousePosition);
        }

        if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2f mousePosition = mRenderWindow.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
            onMouseReleased();
        }

        if (event.type == sf::Event::MouseMoved)
        {
            sf::Vector2f mousePosition = mRenderWindow.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y });
            onMouseMoved(mousePosition);
        }

        return false;
    }

    void setColor(sf::Color c) { mShape.setFillColor(c); }
    void setSize(sf::Vector2f sz) { mShape.setSize(sz); }
    void setPosition(sf::Vector2f p) { mShape.setPosition(p); }

    void draw() const override
    {
        mRenderWindow.draw(mShape);
    }
};


class Button : public Widget
{
private:
    // Цвета кнопки по умолчанию(default), при наведении(hover) и при нажатии(pressed)
    sf::Color mDefaultColor{ 179, 230, 255 };
    sf::Color mHoverColor{ 128, 212, 255 };
    sf::Color mPressedColor{ 0, 136, 204 };

    // Объект кнопки содержит объект фигуры-прямоугольника
    // Внутри mShape хранятся координаты, размеры и текущий цвет прямоугольника (у кнопки они будут такими же)
    sf::RectangleShape mShape{};

    // Объкт текста, который хранит всё информаци о тексте на кнопке
    sf::Text mText{};

    // Когда кнопка находится в нажатом состоянии, 
    // то isPressed = true (Пользователь зажал кнопку и держит)
    bool mIsPressed{ false };

    // Также храним ссылку на окно SFML, на которое будем отрисовывать кнопку
    // Эту ссылку можно было не хранить, а просто передавать во все функции,
    // где окно понадобится, но тогда код был бы более громоздким
    sf::RenderWindow& mRenderWindow;

public:

    Button(sf::RenderWindow& window, sf::FloatRect rect, sf::Font& font, const sf::String& textData)
        : mRenderWindow{ window }
    {
        mShape.setPosition({ rect.left, rect.top });
        mShape.setSize({ rect.width, rect.height });
        mShape.setFillColor(mDefaultColor);

        mText.setFont(font);
        mText.setString(textData);
        mText.setFillColor(sf::Color::Black);

        // Вычисляем оптимальный размер шрифта
        mText.setCharacterSize(30);
        auto calculateOptimalFontSize = [this]()
            {
                float widthFraction = 0.6;
                float heightFraction = 0.4;

                sf::FloatRect textBounds = mText.getLocalBounds();
                float widthRatio = mShape.getSize().x / textBounds.width * widthFraction;
                float heightRatio = mShape.getSize().y / textBounds.height * heightFraction;
                float minRatio = std::min(widthRatio, heightRatio);

                unsigned int newSize = static_cast<unsigned int>(mText.getCharacterSize() * minRatio);
                return newSize;
            };
        mText.setCharacterSize(calculateOptimalFontSize());
        centerText();
    }

    void setFontSize(unsigned int fontSize)
    {
        mText.setCharacterSize(fontSize);
        centerText();
    }

    void draw() const
    {
        mRenderWindow.draw(mShape);
        mRenderWindow.draw(mText);
    }

    // Нужно вызвать лишь этот метод в цикле обработки событий
    // Возвращает true, если нажатие на кнопку произошло
    bool handleEvent(const sf::Event& event)
    {
        if (event.type == sf::Event::MouseMoved)
            onMouseMove(event);
        else if (event.type == sf::Event::MouseButtonPressed)
            onMousePressed(event);
        else if (event.type == sf::Event::MouseButtonReleased)
            return onMouseReleased(event);
        return false;
    }

private:

    // Центрируем текст в центре прямоугольника
    void centerText()
    {
        sf::FloatRect textBounds = mText.getLocalBounds();
        mText.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
        sf::Vector2f rectCenter = mShape.getPosition() + mShape.getSize() / 2.0f;
        mText.setPosition(rectCenter);
    }

    void onMousePressed(const sf::Event& event)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2f mousePosition = mRenderWindow.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
            if (mShape.getGlobalBounds().contains(mousePosition))
            {
                mIsPressed = true;
                mShape.setFillColor(mPressedColor);
            }
        }
    }

    void onMouseMove(const sf::Event& event)
    {
        if (mIsPressed)
            return;

        sf::Vector2f mousePosition = mRenderWindow.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y });
        if (mShape.getGlobalBounds().contains(mousePosition))
            mShape.setFillColor(mHoverColor);
        else
            mShape.setFillColor(mDefaultColor);
    }

    bool onMouseReleased(const sf::Event& event)
    {
        if (!mIsPressed)
            return false;

        mIsPressed = false;

        sf::Vector2f mousePosition = mRenderWindow.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
        if (mShape.getGlobalBounds().contains(mousePosition))
        {
            mShape.setFillColor(mHoverColor);
            return true;
        }
        else
        {
            mShape.setFillColor(mDefaultColor);
            return false;
        }
    }
};



int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Widgets");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("sourceCodePro.ttf"))
    {
        std::cout << "Error: Font file not found." << std::endl;
        std::exit(1);
    }

    std::vector<Widget*> widgets;
    widgets.push_back(new Button{ window, {350, 300, 200, 80}, font, "Cat" });
    widgets.push_back(new Button{ window, {200, 450, 100, 80}, font, "Dog" });
    widgets.push_back(new Button{ window, {600, 600, 150, 70}, font, "Mouse" });

    widgets.push_back(new Slider{ window, {500, 500}, {200, 10}, {20, 40} });
    widgets.push_back(new Slider{ window, {300, 100}, {250, 20}, {30, 60} });

    widgets.push_back(new Draggable{ window, {550, 100}, {200, 120}, {20, 120, 50} });
    widgets.push_back(new Draggable{ window, {50, 550}, {200, 200}, {170, 20, 50} });
    widgets.push_back(new Draggable{ window, {50, 200}, {100, 100}, {100, 20, 150} });

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            for (auto& x : widgets)
                x->handleEvent(event);
        }

        window.clear(sf::Color::Black);
        for (auto& x : widgets)
            x->draw();

        window.display();
    }
}