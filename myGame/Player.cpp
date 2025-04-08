#include "Player.h"
#include "Enemy.h"
#include <iostream>

Player::Player() {
    if (!playerTexture.loadFromFile("C:\\Users\\User\\CLionProjects\\myGame\\assets\\player.png")) {
        std::cout << "Error loading background texture" << std::endl;
    }
    playerSprite.setTexture(playerTexture);
    sf::FloatRect bounds = playerSprite.getLocalBounds();
    playerSprite.setOrigin(bounds.width / 2, bounds.height / 2);
    playerSprite.setPosition({400, 300});
    playerSprite.setScale(0.25f, 0.25f);
    speed = 1.0f;
}

void Player::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) playerSprite.move(0, -speed);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) playerSprite.move(0, speed);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) playerSprite.move(-speed, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) playerSprite.move(speed, 0);
}

void Player::update(Enemy& enemy) {
    handleInput();

    if (shootClock.getElapsedTime().asSeconds() >= shootDelay && enemy.isAlive()) {
        bullets.emplace_back(playerSprite.getPosition(), enemy.getPosition());
        shootClock.restart();
    }

    for (auto& bullet : bullets) {
        bullet.update();
        if (bullet.isActive && bullet.getBounds().intersects(enemy.getBounds())) {
            bullet.isActive = false;
            enemy.takeDamage();
        }
    }

    bullets.erase(std::remove_if(bullets.begin(), bullets.end(),
                                 [](const Bullet& b) { return !b.isActive; }),
                  bullets.end());
}

void Player::draw(sf::RenderWindow &window) {
    window.draw(playerSprite);
}

sf::Vector2f Player::getPosition() const {
    return playerSprite.getPosition();
}

const std::vector<Bullet>& Player::getBullets() const {
    return bullets;
}

std::vector<Bullet>& Player::getBullets() {
    return bullets;
}
