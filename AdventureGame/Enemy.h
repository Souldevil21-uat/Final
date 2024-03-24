#pragma once
#include "Character.h"

class Enemy : public Character {
public:
    Enemy(int health, int strength);
    virtual ~Enemy();

    void attack(Character& target) override; // Override the pure virtual function from Character.

    // Additional Enemy-specific methods can be added here.
};
