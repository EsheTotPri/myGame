#include "Player.h"

Player::Player() {
    shape.setSize({50,50});
    shape.setFillColor(sf::Color::Red);
    shape.setPosition({400,300});
    speed = 1.2f;
}

void Player::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) shape.move(0, -speed);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) shape.move(0, speed);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) shape.move(-speed, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) shape.move(speed, 0);
}

void Player::update() {
    handleInput();
}

void Player::draw(sf::RenderWindow &window) {
    window.draw(shape);
}

sf::Vector2f Player::getPosition() const {
    return shape.getPosition();
}

