#include "WaveManager.h"

WaveManager::WaveManager(int initialWaveSize, float spawnInterval, float waveDuration)
    : waveSize(initialWaveSize), spawnInterval(spawnInterval), timeSinceLastSpawn(0), enemiesSpawned(0), currentWave(1), waveDuration(waveDuration), timeSinceWaveStart(0)
{
}

void WaveManager::update(float deltaTime, sf::RectangleShape* playerForm)
{
    timeSinceLastSpawn += deltaTime;
    timeSinceWaveStart += deltaTime;

    if (timeSinceLastSpawn >= spawnInterval && enemiesSpawned < waveSize)
    {
        spawnEnemy();
        timeSinceLastSpawn = 0;
        enemiesSpawned++;
    }

    for (auto& enemy : enemies)
    {
        enemy->update(deltaTime, playerForm);
    }

    removeDefeatedEnemies();

    // Check if all enemies are defeated or if the wave duration has elapsed
    if (allEnemiesDefeated() || timeSinceWaveStart >= waveDuration)
    {
        startNextWave();
    }
}

void WaveManager::draw(sf::RenderWindow& window)
{
    for (auto& enemy : enemies)
    {
        enemy->draw(window);
    }
}

void WaveManager::startNextWave()
{
    currentWave++;
    waveSize += 2; // Increase the number of enemies in each wave
    enemiesSpawned = 0;
    timeSinceLastSpawn = 0;
    timeSinceWaveStart = 0; // Reset the wave timer
}

void WaveManager::spawnEnemy()
{
    sf::RectangleShape* enemyShape = new sf::RectangleShape(sf::Vector2f(80, 80));
    enemyShape->setFillColor(sf::Color::Green);
    enemyShape->setPosition(sf::Vector2f(rand() % 1920, rand() % 1080));
    enemyShape->setOrigin(enemyShape->getSize().x / 2, enemyShape->getSize().y / 2);
    enemyShape->setScale(0.5, 0.5);

    Enemy* enemy = new Enemy(enemyShape, enemiesSpawned, 300);
    enemies.push_back(enemy);
}

void WaveManager::removeDefeatedEnemies()
{
    enemies.erase(std::remove_if(enemies.begin(), enemies.end(), [](Enemy* enemy) {
        // Supposons que l'ennemi a une méthode isDefeated() pour vérifier s'il est éliminé
        bool defeated = enemy->isDefeated();
        if (defeated)
        {
            delete enemy;
        }
        return defeated;
    }), enemies.end());
}

bool WaveManager::allEnemiesDefeated()
{
    return enemies.empty() && enemiesSpawned == waveSize;
}

int WaveManager::getCurrentWave() const
{
    return currentWave;
}