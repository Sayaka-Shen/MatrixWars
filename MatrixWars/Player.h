#pragma once
#include <SFML/Graphics.hpp>

class Player
{
private:
    sf::RectangleShape* playerForm;
    int playerId;
    float playerSpeed;
    sf::Vector2f dir;
    sf::Vector2f lastDir;
	bool toBeDeleted;
public:
    // Constructor
    Player(sf::RectangleShape* playerFORM, int playerID, float playerSPEED);

    // Destructor
    ~Player();

    // Get for the id player and the form of the player which are private 
    int getId();
    sf::RectangleShape* getPlayerForm();
    float getSpeed();
    sf::Vector2f getDir();
    sf::Vector2f getLastDir();

    // Function to draw the form and to move the player
    void draw(sf::RenderWindow& window);
    void update(float deltaTime, const std::vector<sf::RectangleShape*>& enemyForms);
    void setDir(sf::Vector2f dir);
    void setSpeed();
    void setSpeedDiagonal();
    void setSpeedOrthogonal();
    bool checkPlayerCollision(sf::RectangleShape* other);
    void markForDeletion() { toBeDeleted = true; }
    bool isDefeated(sf::RectangleShape* enemy);
	bool isToBeDeleted() { return toBeDeleted; }
    void removePlayer();



};
