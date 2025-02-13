

#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "ctime"
#include "cstdlib"

class Enemy {
    private:

    sf:: Sprite enemySprite;
    sf:: Texture enemyTexture;
    float speed;
    sf::Vector2f direction;
    sf::Clock movementClock;
    float changeDirection;

    public:

    Enemy();
    void update();
    sf::Vector2f getPosition();
    void draw(sf::RenderWindow& window) const;
    sf::Vector2f getPosition() const;
    void randomizeDirection();


};


#endif //ENEMY_H
