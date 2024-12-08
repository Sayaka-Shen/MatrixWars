#pragma once
#include <SFML/Graphics.hpp>

class Player
{
private:
    sf::Shape* playerForm;
    int playerId;
    float playerSpeed;
    
public:
    // Constructor
    Player(sf::Shape* playerFORM, int playerID, float playerSPEED);

    // Destructor
    ~Player();

    // Get for the id player and the form of the player which are private 
    int getId();
    sf::Shape* getPlayerForm();
    float getSpeed();

    // Function to draw the form and to move the player
    void draw(sf::RenderWindow& window);
    void move(float offsetX, float offsetY);
};