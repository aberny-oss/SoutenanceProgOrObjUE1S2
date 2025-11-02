#include "Warrior.h"

std::vector<std::string> Warrior::Display() {
    std::vector<std::string> lines;

    if (type == "Warrior") {
        // Préparer le nom (max 12 caractères)
        std::string displayName = name.substr(0, 12);
        displayName += std::string(12 - displayName.length(), ' ');

        // Préparer les stats
        std::string stats = "Lv:" + std::to_string(level) + " HP:" + std::to_string(health);
        stats = stats.substr(0, 12);
        stats += std::string(12 - stats.length(), ' ');

        lines.push_back("+--------------+");
        lines.push_back("| " + displayName + " |");
        lines.push_back("| " + stats + " |");
        lines.push_back(R"(|     .-.      |)");
        lines.push_back(R"(|   __|=|__    |)");
        lines.push_back(R"(|  (_/`-`\_)   |)");
        lines.push_back(R"(|  ||\___/||   |)");
        lines.push_back(R"(|  <>/   \<>   |)");
        lines.push_back(R"(|   \|_._|/    |)");
        lines.push_back(R"(|    <_I_>     |)");
        lines.push_back(R"(|     |||      |)");
        lines.push_back(R"(|    /_|_\     |)");
        lines.push_back("+--------------+");
    }

    return lines;
}

void Warrior::SimpleAttack()
{
    std::cout << name << " attaque avec son epee ! \n";
}

void Warrior::HeavyAttack()
{
    std::cout << name << " fait une attaque lourde ! \n";
}

void Warrior::UltimeAttack()
{
    std::cout << name << " utilise sa rage ultime ! \n";
}