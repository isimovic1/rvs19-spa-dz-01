#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window) {
    this->window = window;
    this->size = 20;
    this->speed = 50;
    this->growing = true;
}

void Cvijet::draw() {
    sf::CircleShape sun(size);
    sun.setFillColor(sf::Color::Yellow);
    sun.setPosition(10, 20);

    sf::CircleShape flower(30);
    flower.setFillColor(sf::Color::Yellow);
    flower.setOutlineThickness(10.f);
    flower.setOutlineColor(sf::Color::Red);
    flower.setPosition(400, 220);

    sf::RectangleShape stem(sf::Vector2f(10, 100));
    stem.setFillColor(sf::Color::Green);
    stem.setPosition(420, 290);

    sf::ConvexShape leaf(3);
    leaf.setPoint(0, sf::Vector2f(420, 350));
    leaf.setPoint(1, sf::Vector2f(380, 380));
    leaf.setPoint(2, sf::Vector2f(340, 320));
    leaf.setFillColor(sf::Color::Green);

    window->draw(flower);
    window->draw(sun);
    window->draw(stem);
    window->draw(leaf);
}

void Cvijet::animate()
{
    sf::Time frameTime = frameClock.restart();

    if (growing) {
        size += speed * frameTime.asSeconds();
        if (size >= 20) {
            size = 20;
            growing = false;
        }
    }
    else {
        size -= speed * frameTime.asSeconds();
        if (size <= 15) {
            size = 15;
            growing = true;
        }
    }
}