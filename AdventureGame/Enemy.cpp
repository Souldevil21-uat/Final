#include "Enemy.h"
#include <iostream>

Enemy::Enemy(int health, int strength) : Character(health, strength) {}

Enemy::~Enemy() {}

void Enemy::attack(Character& target) {
    int damage = this->getStrength();
    std::cout << "Enemy attacks, causing " << damage << " points of damage!" << std::endl;
    std::cout << "Target health before attack: " << target.getHealth() << std::endl;
    target.setHealth(target.getHealth() - damage);
    std::cout << "Target health after attack: " << target.getHealth() << std::endl;
}
