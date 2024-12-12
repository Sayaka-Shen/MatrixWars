#pragma once
#include <vector>
#include "Enemy.h"
#include <SFML/Graphics.hpp>

class WaveManager
{
public:
    WaveManager(int initialWaveSize, float spawnInterval, float waveDuration);
    void update(float deltaTime, sf::RectangleShape* playerForm);
    void draw(sf::RenderWindow& window);
    void startNextWave();
    int getCurrentWave() const; // Ajout de la m�thode getCurrentWave

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
    void removeDefeatedEnemies();
    bool allEnemiesDefeated();
};
