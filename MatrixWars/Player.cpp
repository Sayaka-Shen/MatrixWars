#include "Player.h"
#include <iostream>

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
    if (Player::getDir().x == 0 || Player::getDir().y == 0)
    {
        return playerSpeed * sqrt(2);
    }
    return playerSpeed;
}

sf::Vector2f Player::getDir()
{
    return dir;
}

sf::Vector2f Player::getLastDir()
{
    return lastDir;
}

// Move and Draw Functions
void Player::draw(sf::RenderWindow& window)
{
    if (playerForm)
    {
        window.draw(*playerForm);
    }
}

void Player::update(float deltaTime, const std::vector<sf::RectangleShape*>& enemyForms)
{
    

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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::B))
    {
		std::cout << "break" << std::endl;
    }
    for (auto enemyForm : enemyForms) {
        if (checkPlayerCollision(enemyForm)) {
			std::cout << "Player defeated" << std::endl;
			markForDeletion();
            break;
        }
    }
    
    removePlayer();
}

void Player::removePlayer() {
	if (Player::isToBeDeleted())
	{
		std::cout << "Player deleted" << std::endl;
		delete playerForm;
		playerForm = nullptr;
	}
}

void Player::setDir(sf::Vector2f _dir)
{
    dir = _dir;
    if (dir != sf::Vector2f{ 0, 0 })
    {
        lastDir = dir;
    }
}

void Player::setSpeed()
{
    playerSpeed = Player::getSpeed();
}

void Player::setSpeedDiagonal()
{
    playerSpeed = playerSpeed * sqrt(2);
}

void Player::setSpeedOrthogonal()
{
    playerSpeed = playerSpeed * playerSpeed;
}

bool Player::checkPlayerCollision(sf::RectangleShape* other)
{
    return Player::getPlayerForm()->getGlobalBounds().intersects(other->getGlobalBounds());
}

bool Player::isDefeated(sf::RectangleShape* enemy)
{
    if (Player::checkPlayerCollision(enemy))
    {
        std::cout << "Player defeated" << std::endl;
        markForDeletion();
        return true;
    }

    return false;
}