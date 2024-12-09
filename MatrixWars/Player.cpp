#include "Player.h"

// Constructor
Player::Player(sf::CircleShape* playerFORM, int playerID, float playerSPEED)
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

sf::CircleShape* Player::getPlayerForm()
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

void Player::update(float deltaTime)
{
    playerForm->move(dir.x * getSpeed() * deltaTime, dir.y * getSpeed() * deltaTime);
    
    if (playerForm->getPosition().x < playerForm->getOrigin().x * playerForm->getScale().x)
    {
        playerForm->setPosition(playerForm->getOrigin().x * playerForm->getScale().x, playerForm->getPosition().y);
    }
    else if (playerForm->getPosition().x > 1900)
    {
        playerForm->setPosition(1900, playerForm->getPosition().y);
    }

    if (playerForm->getPosition().y < playerForm->getRadius() * playerForm->getScale().y / 2)
    {
        playerForm->setPosition(playerForm->getPosition().x, playerForm->getRadius() * playerForm->getScale().y / 2);
    }
    else if (playerForm->getPosition().y > 1080 - 40)
    {
        playerForm->setPosition(playerForm->getPosition().x, 1080 - 40);
    }
        
}

void Player::setDir(sf::Vector2f _dir)
{
    dir = _dir;
}


