#ifndef GAME_H
#define GAME_H

#include "Enemy.h"
#include "EnvironmentObjects.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include "EnvironmentManager.h"

class Game {
private:
    sf::RenderWindow window;
    sf::View camera;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    Player player;
    Enemy enemy;
    EnvironmentManager environment;
    std::vector<EnvironmentObjects> environmentObjects;
    sf::Texture treeTexture;
    sf::Texture rockTexture;
    sf::Texture stickTexture;


    void processEvents();
    void update();
    void render();

public:
    Game();
    void run();
};

#endif //GAME_H
