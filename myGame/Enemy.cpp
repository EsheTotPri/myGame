#include "Enemy.h"
#include <iostream>

Enemy::Enemy() : speed(1.f), direction(0, 0), changeDirection(1.f), health(10) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    if (!enemyTexture.loadFromFile("C:\\Users\\User\\CLionProjects\\myGame\\assets\\enemy.png")) {
        std::cout << "Error loading enemy texture" << std::endl;
    }
    enemySprite.setTexture(enemyTexture);
    enemySprite.setPosition(400, 300);
    enemySprite.setScale(0.25f, 0.25f);

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

    enemySprite.move(direction.x * speed * 0.5f, direction.y * speed * 0.5f);
}

sf::Vector2f Enemy::getPosition() const {
    return enemySprite.getPosition();
}

void Enemy::draw(sf::RenderWindow& window) const {
    window.draw(enemySprite);
}

void Enemy::takeDamage() {
    health--;
    if (health <= 0) {
        std::cout << "Enemy defeated!" << std::endl;
    }
}

bool Enemy::isAlive() const {
    return health > 0;
}

sf::FloatRect Enemy::getBounds() const {
    return enemySprite.getGlobalBounds();
}
