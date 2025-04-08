#include "Bullet.h"
#include <cmath>

Bullet::Bullet(sf::Vector2f startPos, sf::Vector2f targetPos) : isActive(true) {
  shape.setRadius(15.f);
  shape.setFillColor(sf::Color::Yellow);
  shape.setOrigin(shape.getRadius(), shape.getRadius());
  shape.setPosition(startPos);

  sf::Vector2f dir = targetPos - startPos;
  float length = std::sqrt(dir.x * dir.x + dir.y * dir.y);
  if (length != 0)
    velocity = dir / length * speed;
  else
    velocity = {0.f, 0.f};
}

void Bullet::update() {
  shape.move(velocity);
}

void Bullet::draw(sf::RenderWindow& window) const {
  window.draw(shape);
}

sf::FloatRect Bullet::getBounds() const {
  return shape.getGlobalBounds();
}
