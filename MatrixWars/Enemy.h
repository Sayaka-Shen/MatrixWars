#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
public:
    // Constructor
    Enemy(sf::RectangleShape* enemyFORM, int enemyID, float enemySPEED);

    // Destructor
    ~Enemy();

    // Getters
    int getId();
    sf::RectangleShape* getEnemyForm();
    float getSpeed();

    // Move and Draw Functions
    void draw(sf::RenderWindow& window);
    void update(float deltaTime, sf::RectangleShape* playerForm, sf::CircleShape* bullet);
    void setDir(sf::Vector2f _dir);
    bool isDefeated(sf::CircleShape* bullet); // Ajout de la méthode isDefeated
	bool isToBeDeleted() { return toBeDeleted; }
	void markForDeletion() { toBeDeleted = true; }

private:
    sf::RectangleShape* enemyForm;
    int enemyId;
    float enemySpeed;
    sf::Vector2f dir;
    bool toBeDeleted;

    bool checkCollision(sf::RectangleShape* other);
	bool checkBulletCollision(sf::CircleShape* other);
};
