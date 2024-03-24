#pragma once
#include "Character.h"

class Player : public Character {
public:
    Player(int health, int strength);
    virtual ~Player();

    void attack(Character& target) override; // Override the pure virtual function from Character.

    // Additional Player-specific methods can be added here.
};
