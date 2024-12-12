#include "Player.h"
#include "Enemy.h" // Inclure le fichier d'en-tête Enemy
#include "WaveManager.h"
#include "MathUtils.h"
#include <SFML/Graphics.hpp>
#include <iostream> // Pour afficher les messages d'erreur

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

    // Create the wave manager
    WaveManager waveManager(5, 2.0f, 10.0f); // Initial wave size of 5 enemies, spawn interval of 2 seconds, wave duration of 10 seconds

    // Load font
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cerr << "Error loading font" << std::endl;
        return -1; // Quitter le programme si la police ne peut pas être chargée
    }

    // Create text to display the current wave
    sf::Text waveText;
    waveText.setFont(font);
    waveText.setCharacterSize(50); // Augmenter la taille du texte
    waveText.setFillColor(sf::Color::White);
    waveText.setStyle(sf::Text::Bold); // Rendre le texte en gras

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
        waveManager.update(deltaTime, player.getPlayerForm()); // Mettre à jour les ennemis avec la forme du joueur

        // Update wave text
        waveText.setString("Wave: " + std::to_string(waveManager.getCurrentWave()));
        // Center the text at the top of the screen
        sf::FloatRect textRect = waveText.getLocalBounds();
        waveText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        waveText.setPosition(sf::Vector2f(window.getSize().x / 2.0f, textRect.height + 10)); // Ajuster la position pour qu'il soit visible

        // Classic command
        window.clear();
        player.draw(window);
        waveManager.draw(window); // Dessiner les ennemis
        window.draw(waveText); // Dessiner le texte de la vague
        window.display();
    }
}