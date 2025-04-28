#ifndef ENEMY_H
#define ENEMY_H
class Player;

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
    int damage = 10;

public:
    Enemy();
    void update(const sf::Vector2f& playerPosition, Player& player);
    sf::Vector2f getPosition() const;
    void draw(sf::RenderWindow& window) const;
    void randomizeDirection();

    void takeDamage();
    bool isAlive() const;
    sf::FloatRect getBounds() const;
    sf::Clock attackCooldown;
    sf::Time attackDelay = sf::seconds(1.f);

};

#endif //ENEMY_H
