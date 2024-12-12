#pragma once
#include <SFML/Graphics.hpp>

class Player
{
private:
    sf::RectangleShape* playerForm;
    int playerId;
    float playerSpeed;
    sf::Vector2f dir;
    
public:
    // Constructor
    Player(sf::RectangleShape   * playerFORM, int playerID, float playerSPEED);

    // Destructor
    ~Player();

    // Get for the id player and the form of the player which are private 
    int getId();
    sf::RectangleShape* getPlayerForm();
    float getSpeed();
    sf::Vector2f getDir();

    // Function to draw the form and to move the player
    void draw(sf::RenderWindow& window);
    void update(float deltaTime);
    void setDir(sf::Vector2f dir);
    float setMagnitude(sf::Vector2f dir);
};