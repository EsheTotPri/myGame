//
// Created by jolly on 27.04.2025.
//

#ifndef ENVIRONMENTOBJECTS_H
#define ENVIRONMENTOBJECTS_H
#include <SFML/Graphics.hpp>

class EnvironmentObjects {
public:
  EnvironmentObjects(const sf::Sprite& sprite) : sprite(sprite) {}
  EnvironmentObjects(const sf::Texture& texture, sf::Vector2f position) {
    sprite.setTexture(texture);
    sprite.setPosition(position);
  }

  const sf::Sprite& getSprite() const { return sprite; }

private:
  sf::Sprite sprite;
};


#endif //ENVIRONMENTOBJECTS_H
