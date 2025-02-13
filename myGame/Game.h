//
// Created by User on 13.02.2025.
//

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"

class Game {
    private:
    sf::RenderWindow window;
    sf::View camera;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    Player player;
    Enemy Enemy;

    void processEvents();
    void update();
    void render();


    public:
    Game();
    void run();
};



#endif //GAME_H
