//
// Created by User on 13.02.2025.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
    private:
    sf::RectangleShape shape;

    float speed;

    public:
    Player();
    void handleInput();
    void update();
    void draw(sf::RenderWindow &window);

    sf::Vector2f getPosition() const;

};

#endif //PLAYER_H
