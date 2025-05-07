//
// Created by jolly on 27.04.2025.
//

#ifndef ENVIRONMENTMANAGER_H
#define ENVIRONMENTMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <vector>
#include "EnvironmentObjects.h"

class EnvironmentManager {
public:
  EnvironmentManager(sf::Vector2u windowSize);

  void update(const sf::Vector2f& playerPosition);
  void draw(sf::RenderWindow& window);

private:
  sf::Texture treeTexture;
  sf::Texture rockTexture;
  sf::Texture stickTexture;
  sf::Texture treeTexture2;
  sf::Texture treeTexture3;
  sf::Texture rockTexture2;
  sf::Texture stickTexture2;
  sf::Texture fountainTexture;
  sf::Sprite fountainSprite;
  bool fountainPlaced = false;

  std::map<std::pair<int, int>, std::vector<EnvironmentObjects>> chunks;
  sf::Vector2u windowSize;
};

#endif // ENVIRONMENTMANAGER_H
