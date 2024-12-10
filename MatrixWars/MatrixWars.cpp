#include "Player.h"
#include "MathUtils.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Matrix Wars");

    // Create the player shapes and the player
    //sf::CircleShape* playerShape = new sf::CircleShape(80, 16);
    sf::RectangleShape* playerShape = new sf::RectangleShape(sf::Vector2f(80, 80));
    playerShape->setFillColor(sf::Color::Red);
    playerShape->setPosition(sf::Vector2f(200, 200));
    playerShape->setOrigin(playerShape->getSize().x / 2, playerShape->getSize().y / 2);
    playerShape->setScale(0.5, 0.5);
    //playerShape->setRotation(45);

    Player player(playerShape, 1, 500);

    // Time management
    sf::Clock clock;
    
    while (window.isOpen())
    {
        sf::Event event;
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed && event.type == sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
        }
        
        // Movement Management 
        float deltaTime = clock.restart().asSeconds();
        player.setDir({0, 0});
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        {
            player.setDir(player.getDir() + sf::Vector2f(0, -1));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            player.setDir(player.getDir() + sf::Vector2f(0, 1));
        } 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            player.setDir(player.getDir() + sf::Vector2f(-1, 0));
        } 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            player.setDir(player.getDir() + sf::Vector2f(1, 0));
        }

        player.update(deltaTime);

        // Classic command
        window.clear();
        player.draw(window);
        window.display();
    }
}