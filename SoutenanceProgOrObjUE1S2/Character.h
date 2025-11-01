#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "ASCIIART.h"
#include <iomanip>

class Character {
protected:
    std::string name;
    std::string type;
    int level;
    int health;
    std::vector<std::string> attacks;
    ASCIIART art;

public:
    Character(const std::string& n, const std::string& t, int l, int h)
        : name(n), type(t), level(l), health(h), art()
    {
        attacks = { "Simple", "Heavy", "Ultime" }; // toutes les attaques
    }


    virtual ~Character() {} // destructeur virtuel

    void DisplayCharacter();

    std::string GetName() const;

    // Getter moderne
    virtual int GetNbAttacks() const;
    virtual void DisplayAttacks() const;
    /*virtual void UseAttackByIndex(int index);*/
    virtual void AttackByIndex(std::vector<std::string> attacks);

    void TakeDamage(int dmg);
    void Heal(int amount);

    virtual void SimpleAttack() = 0;
    virtual void HeavyAttack() = 0;
    virtual void UltimeAttack() = 0;
};
