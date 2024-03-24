#pragma once
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include <memory>

class GameEngine {
public:
    GameEngine();
    ~GameEngine();

    void run(); // Starts the game loop.
    void initializeEnemies();

private:
    void handleInput(); // Processes user input.
    void update(); // Updates the game state.
    void render(); // Renders the game world and entities to the console.

    bool isRunning;
    std::unique_ptr<Player> player;
    std::vector<std::unique_ptr<Enemy>> enemies; // Using smart pointers for dynamic memory management.
    Enemy* currentEnemy;

};
