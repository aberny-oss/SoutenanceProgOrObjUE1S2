#include "Goblin.h"

std::vector<std::string> Goblin::Display() const {
    std::vector<std::string> lines;

    // Préparer le nom (max 12 caractères)
    std::string displayName = name.substr(0, 12);
    displayName += std::string(12 - displayName.length(), ' ');

    // Préparer les stats (max 12 caractères)
    std::string stats = "Lv:" + std::to_string(level) + " HP:" + std::to_string(health);
    stats = stats.substr(0, 12);
    stats += std::string(12 - stats.length(), ' ');

    // Cadre et informations
    lines.push_back("+----------------+");
    lines.push_back("|  " + displayName + "  |");
    lines.push_back("|  " + stats + "  |");
    lines.push_back(R"(|    _____       |)");
    lines.push_back(R"(|.-,;='';_),-.   |)");
    lines.push_back(R"(| \_\(),()/_/    |)");
    lines.push_back(R"(|   (,___,)      |)");
    lines.push_back(R"(|  ,-/`~`\-,___  |)");
    lines.push_back(R"(| / /).:.('--._) |)");
    lines.push_back(R"(|{_[ (_,_)       |)");
    lines.push_back(R"(|    | Y |       |)");
    lines.push_back(R"(|   /  |  \      |)");
    lines.push_back(R"(|   """ """      |)");
    lines.push_back("+----------------+");

    return lines;
}

void Goblin::SimpleAttack() {
    std::cout << name << " attaque avec sa dague ! \n";
}

void Goblin::HeavyAttack() {
    std::cout << name << " fait un combo rapide ! \n";
}

//void Goblin::UltimeAttack() {
//    std::cout << name << " utilise sa technique ultime ! \n";
//}