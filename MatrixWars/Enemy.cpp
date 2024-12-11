#include "Enemy.h"

// Constructor
Enemy::Enemy(sf::RectangleShape* enemyFORM, int enemyID, float enemySPEED)
{
    enemyForm = enemyFORM;
    enemyId = enemyID;
    enemySpeed = enemySPEED;
}

// Destructor
Enemy::~Enemy()
{
    if (enemyForm)
    {
        delete enemyForm;
        enemyForm = nullptr;
    }
}

// Getter
int Enemy::getId()
{
    return enemyId;
}

sf::RectangleShape* Enemy::getEnemyForm()
{
    return enemyForm;
}

float Enemy::getSpeed()
{
    return enemySpeed;
}

// Move and Draw Functions
void Enemy::draw(sf::RenderWindow& window)
{
    if (enemyForm)
    {
        window.draw(*enemyForm);
    }
}

void Enemy::update(float deltaTime, sf::RectangleShape* playerForm)
{
    // Mise à jour de la direction de l'ennemi pour se déplacer vers le joueur
    sf::Vector2f playerPos = playerForm->getPosition();
    sf::Vector2f enemyPos = enemyForm->getPosition();
    sf::Vector2f direction = playerPos - enemyPos;
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0)
    {
        direction /= length;
    }
    dir = direction;

    // Déplacement de l'ennemi
    enemyForm->move(dir.x * getSpeed() * deltaTime, dir.y * getSpeed() * deltaTime);
    
    // Gestion des collisions avec les bords de la fenêtre
    if (enemyForm->getPosition().x < enemyForm->getSize().x * enemyForm->getScale().x / 2)
    {
        enemyForm->setPosition(enemyForm->getSize().x * enemyForm->getScale().x / 2, enemyForm->getPosition().y);
    }
    else if (enemyForm->getPosition().x > 1920 - enemyForm->getSize().x * enemyForm->getScale().x / 2)
    {
        enemyForm->setPosition(1920 - enemyForm->getSize().x * enemyForm->getScale().x / 2, enemyForm->getPosition().y);
    }

    if (enemyForm->getPosition().y < enemyForm->getSize().y * enemyForm->getScale().y / 2)
    {
        enemyForm->setPosition(enemyForm->getPosition().x, enemyForm->getSize().y * enemyForm->getScale().y / 2);
    }
    else if (enemyForm->getPosition().y > 1080 - enemyForm->getSize().y * enemyForm->getScale().y / 2)
    {
        enemyForm->setPosition(enemyForm->getPosition().x, 1080 - enemyForm->getSize().y * enemyForm->getScale().y / 2);
    }

    // Vérification de la collision avec le joueur
    if (checkCollision(playerForm))
    {
        // Gestion de la collision (par exemple, arrêter le mouvement ou ajuster la position)
        enemyForm->move(-dir.x * getSpeed() * deltaTime, -dir.y * getSpeed() * deltaTime);
    }
}

void Enemy::setDir(sf::Vector2f _dir)
{
    dir = _dir;
}

bool Enemy::checkCollision(sf::RectangleShape* other)
{
    return enemyForm->getGlobalBounds().intersects(other->getGlobalBounds());
}
