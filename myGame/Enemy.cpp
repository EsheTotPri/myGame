#include "Enemy.h"
#include <iostream>
#include <cmath>
#include "Player.h"

Enemy::Enemy() : speed(1.0f), direction(0, 0), changeDirection(1.f), health(50) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    if (!enemyTexture.loadFromFile("C:\\Users\\User\\CLionProjects\\myGame\\assets\\enemy.png")) {
        std::cout << "Error loading enemy texture" << std::endl;
    }
    enemySprite.setTexture(enemyTexture);
    enemySprite.setPosition(400, 300);
    enemySprite.setScale(0.15f, 0.15f);

    randomizeDirection();
}

void Enemy::randomizeDirection() {
    direction.x = (std::rand() % 3 - 1);
    direction.y = (std::rand() % 3 - 1);
}

void Enemy::update(const sf::Vector2f& playerPosition, Player& player) {
    if (!isAlive())
        return;

    sf::Vector2f direction = playerPosition - enemySprite.getPosition();
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (length != 0)
        direction /= length;

    enemySprite.move(direction * speed * 0.16f);

    if (enemySprite.getGlobalBounds().intersects(player.getGlobalBounds())) {
        if (attackCooldown.getElapsedTime() >= attackDelay) {
            player.takeDamage(damage);
            attackCooldown.restart();
        }
    }
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
