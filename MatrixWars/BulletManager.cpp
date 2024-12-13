#include "bulletManager.h"
#include <math.h>
#include <iostream>

bulletManager::bulletManager(float size, float speed)
{
    this->size = size;
    this->speed = speed;
}

bulletManager::~bulletManager()
{
}

int bulletManager::getBulletNumber() {
    return bullets.size();
}

void bulletManager::AddBullet(sf::Vector2f position, sf::Vector2f dir) {
    sf::CircleShape bullet(size, 3);
    bullet.setPosition(position);
    bullet.setOrigin(size, size);
    bullet.setFillColor(sf::Color::Blue);
    bullet.setRotation((std::atan2(dir.y, dir.x) * 180.f / 3.14159265358979323846f) + 90);
    bullets.push_back(bullet);
}

void bulletManager::DrawBullets(sf::RenderWindow& window) {
    for (const auto& bullet : bullets)
    {
		std::cout << "drawing bullet" << std::endl;
        window.draw(bullet);
    }
}

void bulletManager::moveBullets(float deltaTime) {
    for (auto& bullet : bullets) {
        float angle = (bullet.getRotation() - 90) * 3.14159265358979323846f / 180;
        sf::Vector2f dir(cos(angle), sin(angle));
        bullet.move(dir * deltaTime * speed);
    }
}