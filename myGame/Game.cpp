#include "Game.h"
#include "Enemy.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "EnvironmentManager.h"


Game::Game()
    : window(sf::VideoMode(1280, 720), "My Game"),
      environment(window.getSize())
    {
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();

    window.create(desktopMode, "Vampire Survivors Clone", sf::Style::Fullscreen);

    camera.setSize(desktopMode.width, desktopMode.height);
    camera.setCenter(desktopMode.width / 2.f, desktopMode.height / 2.f);

    if (!backgroundTexture.loadFromFile("C:\\Users\\User\\CLionProjects\\myGame\\assets\\grass.png")) { // поменять на путь к ассетам на своем компе
        std::cout << "Error loading background texture" << std::endl;
    }
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(2.f, 2.f);


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
    environment.update(player.getPosition());
    enemy.update(player.getPosition(), player);
    camera.setCenter(player.getPosition());
    window.setView(camera);
    if (player.isDead()) {
        sf::Font font;
        font.loadFromFile("C:\\Users\\User\\CLionProjects\\myGame\\fonts\\DmitrievaSP.otf");

        sf::Text deathMessage("PIZDEC TI EBLAN AHAHA))", font, 100);
        deathMessage.setPosition(window.getSize().x / 8 - deathMessage.getGlobalBounds().width / 8,
                                 window.getSize().y / 4 - deathMessage.getGlobalBounds().height / 4);
        window.clear();
        window.draw(deathMessage);
        window.display();
        sf::sleep(sf::seconds(2));
    } else {
        player.update(enemy);
        enemy.update(player.getPosition(), player);
    }
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
    environment.draw(window);

    player.draw(window);
    for (const auto& bullet : player.getBullets()) {
        bullet.draw(window);
    }

    if (enemy.isAlive()) {
        enemy.draw(window);
    }


    window.display();
}
