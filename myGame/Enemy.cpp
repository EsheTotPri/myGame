#include "Enemy.h"
#include <iostream>

Enemy::Enemy(): speed(2.f), direction(0,0), changeDirection(5.f) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    if (!enemyTexture.loadFromFile(R"(C:\Users\jolly\CLionProjects\myGame\assets\enemy.png)")) {
        std::cout << "Error loading background texture" << std::endl;
    }
    enemySprite.setTexture(enemyTexture);
    enemySprite.setPosition(400,300);

    randomizeDirection();

}

void Enemy::randomizeDirection() {
    direction.x = (std::rand() % 3 - 1);
    direction.y = (std::rand() % 3 - 1);
}

void Enemy::update() {
    if (movementClock.getElapsedTime().asSeconds() >= changeDirection) {
        randomizeDirection();
        movementClock.restart();
    }

    enemySprite.move(direction.x * speed * 0.1f, direction.y * speed * 0.1f);

}

sf::Vector2f Enemy::getPosition() const {
    return enemySprite.getPosition();
}

void Enemy::draw(sf::RenderWindow& window) const {
    window.draw(enemySprite);
}

