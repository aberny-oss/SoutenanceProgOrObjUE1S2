#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Character.h"

class Mage : public Character
{
public:

    Mage(const std::string& name, const std::string& team)
        : Character(name, "Mage", 8, 200, team)
    {
        attacks = {"Simple", "Heavy", "Ultime" }; // toutes les attaques
    }

    std::vector<std::string>Display() const override;

    void SimpleAttack();

    void HeavyAttack();

    void UltimeAttack();



};
