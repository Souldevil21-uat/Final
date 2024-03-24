#pragma once

class Character {
public:
    Character(int health, int strength);
    virtual ~Character();

    virtual void attack(Character& target) = 0; // Pure virtual function makes this class abstract.
    virtual void heal();
    virtual void defend();

    // Getter methods
    int getHealth() const;
    int getStrength() const;

    // Setter methods
    void setHealth(int health);
    void setStrength(int strength);

protected:
    int health;
    int strength;
};