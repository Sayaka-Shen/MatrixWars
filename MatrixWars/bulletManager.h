#pragma once
#include "SFML/Graphics.hpp"

class bulletManager
{
private:

    std::vector<sf::CircleShape> bullets;
    float speed;
    float size;

public:
    bulletManager(float size, float speed);
    ~bulletManager();

    int getBulletNumber();
    sf::CircleShape* getBulletShape();
	std::vector<sf::CircleShape>& getBullets() { return bullets; }

    void AddBullet(sf::Vector2f position, sf::Vector2f dir);
    void DrawBullets(sf::RenderWindow& window);
    void moveBullets(float deltaTime);
};