#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Game.h"

class Character {
protected:
    std::string name;
    std::string type;
    int level;
    int health;
    std::vector<std::string> attacks;

public:
    Character(const std::string& n, const std::string& t, int l, int h)
        : name(n), type(t), level(l), health(h) {
        attacks = { "Simple", "Heavy", "Ultime" }; // toutes les attaques
    }


    virtual ~Character() {} // destructeur virtuel

    void DisplayCharacter() const;

    std::string GetName() const;

    // Getter moderne
    virtual int GetNbAttacks() const;
    virtual void DisplayAttacks() const;
    /*virtual void UseAttackByIndex(int index);*/
    virtual void AttackByIndex(std::vector<std::string> attacks);

    void TakeDamage(int dmg);
    void Heal(int amount);

    virtual void SimpleAttack();
    virtual void HeavyAttack();
    virtual void UltimeAttack();
};
