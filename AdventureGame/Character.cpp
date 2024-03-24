#include "Character.h"
#include <iostream>

Character::Character(int health, int strength) : health(health), strength(strength) {}

Character::~Character() {}

int Character::getHealth() const {
    return health;
}

int Character::getStrength() const {
    return strength;
}

void Character::setHealth(int newHealth) {
    health = newHealth;
    if (health < 0) {
        health = 0; // Prevents health from going negative.
    }
}

void Character::setStrength(int strength) {
    this->strength = strength;
}

void Character::heal() {
    health += 10; // Just a simple fixed amount for demonstration.
}

void Character::defend() {
    // Implement defense mechanism, could be a flag that modifies incoming damage.
}

void Character::attack(Character& target) {
    int damage = this->getStrength();
    std::cout << "Attacking with strength: " << damage << std::endl;
    std::cout << "Target health before attack: " << target.getHealth() << std::endl;
    target.setHealth(target.getHealth() - damage);
    std::cout << "Target health after attack: " << target.getHealth() << std::endl;
} 
