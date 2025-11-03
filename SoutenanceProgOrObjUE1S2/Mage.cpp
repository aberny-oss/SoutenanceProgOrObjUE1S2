#include "Mage.h"

std::vector<std::string> Mage::Display() const {
    std::vector<std::string> lines;

    // Préparer le nom (max 12 caractères)
    std::string displayName = name.substr(0, 12);
    displayName += std::string(12 - displayName.length(), ' ');

    // Préparer les stats (max 12 caractères)
    std::string stats = "Lv:" + std::to_string(level) + " HP:" + std::to_string(health);
    stats = stats.substr(0, 12);
    stats += std::string(12 - stats.length(), ' ');

    lines.push_back("+----------------+");
    lines.push_back("|  " + displayName + "  |");
    lines.push_back("|  " + stats + "  |");
    lines.push_back(R"(|                |)");
    lines.push_back(R"(|                |)");
    lines.push_back(R"(|                |)");
    lines.push_back(R"(|      __/\__    |)");
    lines.push_back(R"(|   _  \\''//    |)");
    lines.push_back(R"(| -( )-/_||_\    |)");
    lines.push_back(R"(|  .'. \_()_/    |)");
    lines.push_back(R"(|   |   | . \    |)");
    lines.push_back(R"(|   |   | .  \   |)");
    lines.push_back(R"(|  .'. ,\_____'. |)");
    lines.push_back(R"(+----------------+)");

    return lines;
}

void Mage::SimpleAttack()
{
    std::cout << name << " attaque avec sa magie ! \n";
}

void Mage::HeavyAttack()
{
    std::cout << name << " fait une attaque magique lourde ! \n";
}

void Mage::UltimeAttack()
{
    std::cout << name << " utilise sa magie ultime ! \n";
}