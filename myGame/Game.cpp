#include "Game.h"
#include "Enemy.h"

#include <iostream>
#include <math.h>

Game::Game() : window(sf::VideoMode(1600, 900), "Vampire Survivors Clone") {
    camera.setSize(1600,900);
    camera.setCenter(400,600);

    if (!backgroundTexture.loadFromFile(R"(C:\Users\jolly\CLionProjects\myGame\assets\grass.jpg)")) {
        std::cout << "Error loading background texture" << std::endl;
    }
    backgroundSprite.setTexture(backgroundTexture);



}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::update() {
    player.update();
    Enemy.update();
    camera.setCenter(player.getPosition());
    window.setView(camera);
}

void Game::render() {
    window.clear();

    sf::Vector2f viewCenter = camera.getCenter();
    sf::Vector2f viewSize = camera.getSize();
    sf::Vector2u textureSize = backgroundTexture.getSize();
    float scaleX = backgroundSprite.getScale().x;
    float scaleY = backgroundSprite.getScale().y;

    float texWidth = textureSize.x * scaleX;
    float texHeight = textureSize.y * scaleY;

    int left = static_cast<int>((viewCenter.x - viewSize.x / 2) / texWidth) - 1;
    int right = static_cast<int>((viewCenter.x + viewSize.x / 2) / texWidth) + 1;
    int top = static_cast<int>((viewCenter.y - viewSize.y / 2) / texHeight) - 1;
    int bottom = static_cast<int>((viewCenter.y + viewSize.y / 2) / texHeight) + 1;

    for (int x = left; x <= right; ++x) {
        for (int y = top; y <= bottom; ++y) {
            backgroundSprite.setPosition(x * texWidth, y * texHeight);
            window.draw(backgroundSprite);
        }
    }

    player.draw(window);
    Enemy.draw(window);
    window.display();
}
