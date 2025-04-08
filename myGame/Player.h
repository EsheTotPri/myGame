#ifndef PLAYER_H
#define PLAYER_H

#include "Bullet.h"
#include "Enemy.h"

#include <SFML/Graphics.hpp>

class Player {
private:
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    std::vector<Bullet> bullets;
    sf::Clock shootClock;

    float speed;
    float shootDelay = 0.8f;

public:
    Player();
    void handleInput();
    void update(Enemy& enemy);
    void draw(sf::RenderWindow &window);

    sf::Vector2f getPosition() const;
    const std::vector<Bullet>& getBullets() const;
    std::vector<Bullet>& getBullets();
};

#endif //PLAYER_H
