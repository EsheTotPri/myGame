#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Enemy {
private:
    sf::Sprite enemySprite;
    sf::Texture enemyTexture;
    float speed;
    sf::Vector2f direction;
    sf::Clock movementClock;
    float changeDirection;
    int health;

public:
    Enemy();
    void update();
    sf::Vector2f getPosition() const;
    void draw(sf::RenderWindow& window) const;
    void randomizeDirection();

    void takeDamage();
    bool isAlive() const;
    sf::FloatRect getBounds() const;
};

#endif //ENEMY_H
