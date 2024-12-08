#include "Player.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Matrix Wars");

    // Create the player shapes and the player
    sf::CircleShape* playerShape = new sf::CircleShape(80, 4);
    playerShape->setFillColor(sf::Color::Red);
    playerShape->setPosition(sf::Vector2f(500, 500));

    Player player(playerShape, 1, 10);
    
    while (window.isOpen())
    {
        sf::Event event;
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                case sf::Keyboard::Z: player.move(0, -5); break;
                case sf::Keyboard::S: player.move(0, 5);  break;
                case sf::Keyboard::Q: player.move(-5, 0); break;
                case sf::Keyboard::D: player.move(5, 0);  break;
                case sf::Keyboard::Escape: window.close(); break;
                default: break;
                }
            }
        }

        window.clear();
        player.draw(window);
        window.display();
    }
}