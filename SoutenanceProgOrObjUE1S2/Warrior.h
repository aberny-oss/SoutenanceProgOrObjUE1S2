#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Character.h"

class Warrior : public Character
{
public:

    Warrior(const std::string& name)
        : Character(name, "Warrior", 10, 250) {
        attacks = { "Simple", "Heavy", "Ultime" }; // toutes les attaques
    }

    void SimpleAttack() override;

    void HeavyAttack() override;

    void UltimeAttack() override;
};

