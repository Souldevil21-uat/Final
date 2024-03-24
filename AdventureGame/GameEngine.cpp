#include "GameEngine.h"
#include <iostream>
#include <random>

GameEngine::GameEngine() : isRunning(true), currentEnemy(nullptr) {
    player = std::make_unique<Player>(100, 20);
    initializeEnemies(); // Populate the enemies once
}

void GameEngine::initializeEnemies() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(5, 55);

    enemies.clear(); // Clear any existing enemies before initializing
    for (int i = 0; i < 3; ++i) {
        int randomHealth = distr(gen);
        enemies.push_back(std::make_unique<Enemy>(randomHealth, 10));
        std::cout << "Initialized enemy " << (i + 1) << " with health " << randomHealth << std::endl;
    }
}

GameEngine::~GameEngine() {}

void GameEngine::run() {
    std::cout << "Today is another day in the coliseum, and you are their champion!" << std::endl;

    for (auto& enemy : enemies) {
        currentEnemy = enemy.get(); // Set the current enemy
        std::cout << "A new challenger approaches with " << currentEnemy->getHealth() << " health." << std::endl;

        while (player->getHealth() > 0 && currentEnemy->getHealth() > 0) {
            handleInput(); // Player chooses to attack, heal, or defend

            if (currentEnemy->getHealth() > 0) {
                currentEnemy->attack(*player); // Enemy attacks the player
            }

            if (currentEnemy->getHealth() <= 0) {
                std::cout << "Enemy defeated!" << std::endl;
                break; // Break from the loop to face the next enemy
            }
            if (player->getHealth() <= 0) {
                std::cout << "You have been defeated. Game Over." << std::endl;
                isRunning = false;
                break;
            }
        }

        if (!isRunning) {
            break; // Exit if the game has been flagged to stop
        }
    }

    if (isRunning) {
        std::cout << "Congratulations! You have defeated all the opponents today!" << std::endl;
    }
}

void GameEngine::handleInput() {
    std::cout << "Choose your action: \n1. Attack\n2. Heal\n3. Defend\n";
    int choice;
    std::cin >> choice;
    switch (choice) {
    case 1:
        player->attack(*currentEnemy);
        break;
    case 2:
        player->heal();
        break;
    case 3:
        player->defend();
        break;
    default:
        std::cout << "Invalid choice. Try again.\n";
        handleInput(); // Recursively handle input again for valid choice.
        break;
    }
}



void GameEngine::update() {
    std::cout << "Updating game state..." << std::endl;

    // Assuming the player's action is already processed by this point.
    // Now, it's the enemy's turn to attack the player.
    if (currentEnemy->getHealth() <= 0) {
        std::cout << "Enemy defeated!" << std::endl;
        // Assuming enemies are sequentially battled, remove the defeated enemy.
        enemies.erase(enemies.begin()); // Removes the first enemy, adjust logic as needed for your game structure.
        // Check if there are more enemies to fight.
        if (!enemies.empty()) {
            currentEnemy = enemies[0].get(); // Focus on the next enemy.
        }
        else {
            std::cout << "All enemies defeated! Victory!" << std::endl;
            isRunning = false; // Or move to the next game phase.
        }
    }

    // Here, you can also implement logic for checking the status of the player and enemy.
    // For example, if the player's health drops to 0 or below, you could set isRunning to false to end the game.
    if (player->getHealth() <= 0) {
        std::cout << "You have been defeated!" << std::endl;
        isRunning = false;
    }

    while (player->getHealth() > 0 && currentEnemy->getHealth() > 0) {
        handleInput(); // Player chooses to attack, heal, or defend
        update(); // Updates might include enemy attacks
        render(); // Shows the current state, including health levels
    }

}

void GameEngine::render() {
    std::cout << "Rendering game world..." << std::endl;
    // This method would output the current state of the game world and entities.
}


