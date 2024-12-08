#include "Player.h"

// Constructor
Player::Player(sf::Shape* playerFORM, int playerID, float playerSPEED)
{
    playerForm = playerFORM;
    playerId = playerID;
    playerSpeed = playerSPEED;
}

// Destructor
Player::~Player()
{
    if (playerForm)
    {
        delete playerForm;
        playerForm = nullptr;
    }
}

// Getter
int Player::getId()
{
    return playerId;
}

sf::Shape* Player::getPlayerForm()
{
    return playerForm;
}

float Player::getSpeed()
{
    return playerSpeed;
}


// Move and Draw Functions
void Player::draw(sf::RenderWindow& window)
{
    if (playerForm)
    {
        window.draw(*playerForm);
    }
}

void Player::move(float offsetX, float offsetY)
{
    if (playerForm)
    {
        playerForm->move(offsetX * playerSpeed, offsetY * playerSpeed);
    }
}

