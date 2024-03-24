#include "Player.h"
#include <iostream>

Player::Player(int health, int strength) : Character(health, strength) {}

Player::~Player() {}

void Player::attack(Character& target) {
    int damage = this->getStrength();
    std::cout << "Player attacks, causing " << damage << " points of damage!" << std::endl;
    std::cout << "Target health before attack: " << target.getHealth() << std::endl;
    target.setHealth(target.getHealth() - damage);
    std::cout << "Target health after attack: " << target.getHealth() << std::endl;
}

