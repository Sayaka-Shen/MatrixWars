#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>


int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Matrix Wars", sf::Style::Fullscreen);
    
    while (window.isOpen())
    {
        sf::Event event;
        
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape)
                    {
                        window.close();
                    }
                    break;
                default:
                    break;
            }
        }

        window.clear();
        
        window.display();
    }
}
