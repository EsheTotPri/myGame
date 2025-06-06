#ifndef EXPERIENCEORB_H
#define EXPERIENCEORB_H

#include <SFML/Graphics.hpp>

class ExperienceOrb {
private:
    sf::CircleShape orb;
    sf::Vector2f position;
    float radius = 10.f;
    bool collected = false;
    int xpAmount;

public:
    ExperienceOrb(const sf::Vector2f& pos, int xp = 15);

    void update(float deltaTime, const sf::Vector2f& playerPos);
    void draw(sf::RenderWindow& window) const;

    bool isCollected() const;
    sf::FloatRect getBounds() const;
    int getXP() const;
};

#endif
