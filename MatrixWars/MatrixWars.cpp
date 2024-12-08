#include "Player.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Matrix Wars");

    // Create the player shapes and the player
    sf::CircleShape* playerShape = new sf::CircleShape(80, 4);
    playerShape->setFillColor(sf::Color::Red);
    playerShape->setPosition(sf::Vector2f(500, 500));

    Player player(playerShape, 1, 100);

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

        float offsetX = 0.0f;
        float offsetY = 0.0f;

        if (offsetX != 0 && offsetY != 0)
        {
            const float length = std::sqrt(offsetX * offsetX + offsetY * offsetY);
            offsetX /= length;
            offsetY /= length;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) { offsetY -= 5.0f; }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { offsetY += 5.0f; }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) { offsetX -= 5.0f; }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { offsetX += 5.0f; }

        player.move(offsetX * player.getSpeed() * deltaTime, offsetY * player.getSpeed() * deltaTime);

        // Classic command
        window.clear();
        player.draw(window);
        window.display();
    }
}