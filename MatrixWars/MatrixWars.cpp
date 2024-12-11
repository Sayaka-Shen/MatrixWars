#include "Player.h"
#include "Enemy.h" // Inclure le fichier d'en-tête Enemy
#include "MathUtils.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Matrix Wars", sf::Style::Fullscreen);

    // Create the player shapes and the player
    sf::RectangleShape* playerShape = new sf::RectangleShape(sf::Vector2f(80, 80));
    playerShape->setFillColor(sf::Color::Red);
    playerShape->setPosition(sf::Vector2f(200, 200));
    playerShape->setOrigin(playerShape->getSize().x / 2, playerShape->getSize().y / 2);
    playerShape->setScale(0.5, 0.5);

    Player player(playerShape, 1, 500);

    // Create the enemy shapes and the enemy
    sf::RectangleShape* enemyShape = new sf::RectangleShape(sf::Vector2f(80, 80));
    enemyShape->setFillColor(sf::Color::Green);
    enemyShape->setPosition(sf::Vector2f(400, 400));
    enemyShape->setOrigin(enemyShape->getSize().x / 2, enemyShape->getSize().y / 2);
    enemyShape->setScale(0.5, 0.5);

    Enemy enemy(enemyShape, 1, 300);

    // Time management
    sf::Clock clock;
    
    while (window.isOpen())
    {
        sf::Event event;
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
        }
        
        // Movement Management 
        float deltaTime = clock.restart().asSeconds();
        player.setDir({0, 0});
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        {
            player.setDir({0, -1});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            player.setDir({0, 1});
        } 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            player.setDir({-1, 0});
        } 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            player.setDir({1, 0});
        }

        player.update(deltaTime);
        enemy.update(deltaTime, player.getPlayerForm()); // Mettre à jour l'ennemi avec la forme du joueur

        // Classic command
        window.clear();
        player.draw(window);
        enemy.draw(window); // Dessiner l'ennemi
        window.display();
    }
}