#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include "ASCIIART.h"
#include "Manager.h"
#include <iomanip> // pour std::setw

class Character {
protected:
    std::string name;
    std::string type;
    int level;
    int health;
    std::vector<std::string> attacks;
    ASCIIART art;
    std::string team;

public:
    Character(const std::string& name, const std::string& type, int level, int health, const std::string& team)
        : name(name), type(type), level(level), health(health), team(team), art()
    {
        attacks = { "Simple", "Heavy", "Ultime" }; // toutes les attaques
    }


    virtual ~Character() {} // destructeur virtuel

    /*void Display();*/

    virtual std::vector<std::string> Display();  // Retourne l'ASCII art ligne par ligne

    std::string GetName() const;
    std::string GetTeam() const;

    // Getter moderne
    virtual int GetNbAttacks() const;
    virtual void DisplayAttacks() const;
    /*virtual void UseAttackByIndex(int index);*/
    void AttackByIndex(std::vector<std::string> attacks);

    void TakeDamage(int dmg);
    void Heal(int amount);

    virtual void SimpleAttack() = 0;
    virtual void HeavyAttack() = 0;
    virtual void UltimeAttack() = 0;
};
