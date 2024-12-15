#pragma once
#include <SFML/Graphics.hpp>

class Bullet
{
private:
    sf::CircleShape* bulletForm;
    float bulletSpeed;
    sf::Vector2f dir;
public:
    Bullet(sf::CircleShape* bulletForm, float bulletSpeed);
    ~Bullet();

    //Getters for the bullet entity
    sf::CircleShape* getBulletForm();
    float getBulletSpeed();

    // Function to draw the form and to move the bullet
    void Draw(sf::RenderWindow& window);
    void setDir(sf::Vector2f _dir);

    //Update
};
