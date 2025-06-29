#pragma once
#include <vector>
#include "Enemy.h"
#include <SFML/Graphics.hpp>

class WaveManager
{
public:
    WaveManager(int initialWaveSize, float spawnInterval, float waveDuration);
    void update(float deltaTime, sf::RectangleShape* playerForm, sf::CircleShape* bullet, std::vector<sf::CircleShape>& bullets);
    void removeDefeatedEnemies(std::vector<sf::CircleShape>& bullets);
    void draw(sf::RenderWindow& window);
    void startNextWave();
    int getCurrentWave() const; // Ajout de la m�thode getCurrentWave
    std::vector<sf::RectangleShape*> getEnemyForms();

private:
    std::vector<Enemy*> enemies;
    int waveSize;
    float spawnInterval;
    float timeSinceLastSpawn;
    int enemiesSpawned;
    int currentWave;
    float waveDuration; // Dur�e de chaque vague
    float timeSinceWaveStart; // Temps �coul� depuis le d�but de la vague

    void spawnEnemy();
    //void removeDefeatedEnemies(std::vector<sf::CircleShape>& bullets);
    bool allEnemiesDefeated();
};
