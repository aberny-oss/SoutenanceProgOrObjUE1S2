#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Character.h"

class Goblin : public Character
{
public:

    Goblin(const std::string& name, const std::string& team)
        : Character(name, "Goblin", 6, 150, team)
    {
        attacks = {"Simple", "Heavy"}; // toutes les attaques
    }

    std::vector<std::string>Display() const override;

    void SimpleAttack();

    void HeavyAttack();

    /*void UltimeAttack() override;*/



};
