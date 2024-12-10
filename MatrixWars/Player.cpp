#include "Player.h"

// Constructor
Player::Player(sf::RectangleShape* playerFORM, int playerID, float playerSPEED)
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

sf::RectangleShape* Player::getPlayerForm()
{
    return playerForm;
}

float Player::getSpeed()
{
    return playerSpeed;
}

sf::Vector2f Player::getDir()
{
    return dir;
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
    if (dir.x != 0 || dir.y != 0)
    {
        float mag = setMagnitude(dir);

        dir.x /= mag;
        dir.y /= mag;
    }
    
    playerForm->move(dir.x * getSpeed() * deltaTime, dir.y * getSpeed() * deltaTime);
    
    if (playerForm->getPosition().x < playerForm->getSize().x * playerForm->getScale().x / 2)
    {
        playerForm->setPosition(playerForm->getSize().x * playerForm->getScale().x / 2, playerForm->getPosition().y);
    }
    else if (playerForm->getPosition().x > 1920 - playerForm->getSize().x * playerForm->getScale().x / 2)
    {
        playerForm->setPosition(1920 - playerForm->getSize().x * playerForm->getScale().x / 2, playerForm->getPosition().y);
    }

    if (playerForm->getPosition().y < playerForm->getSize().y * playerForm->getScale().y / 2)
    {
        playerForm->setPosition(playerForm->getPosition().x, playerForm->getSize().y * playerForm->getScale().y / 2);
    }
    else if (playerForm->getPosition().y > 1080 - playerForm->getSize().y * playerForm->getScale().y / 2)
    {
        playerForm->setPosition(playerForm->getPosition().x, 1080 - playerForm->getSize().y * playerForm->getScale().y / 2);
    }
        
}

void Player::setDir(sf::Vector2f _dir)
{
    dir = _dir;
}

float Player::setMagnitude(sf::Vector2f dir)
{
    return sqrt((dir.x * dir.x) + (dir.y * dir.y));
}



