#include "Game.h"
#include "Enemy.h"
#include <iostream>

Game::Game() {
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();

    window.create(desktopMode, "Vampire Survivors Clone", sf::Style::Fullscreen);

    camera.setSize(desktopMode.width, desktopMode.height);
    camera.setCenter(desktopMode.width / 2.f, desktopMode.height / 2.f);

    if (!backgroundTexture.loadFromFile("C:\\Users\\User\\CLionProjects\\myGame\\assets\\grass.jpg")) { // поменять на путь к ассетам на своем компе
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
    player.update(enemy);
    enemy.update();
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
    for (const auto& bullet : player.getBullets()) {
        bullet.draw(window);
    }

    if (enemy.isAlive()) {
        enemy.draw(window);
    }

    window.display();
}
