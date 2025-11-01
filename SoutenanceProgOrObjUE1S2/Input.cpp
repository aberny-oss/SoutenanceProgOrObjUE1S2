#include "Input.h"

// Définition des membres statiques
const std::string Input::PLAY_GAME = "j";
const std::string Input::QUIT_GAME = "q";

// lit une entrée utilisateur
void Input::Update(std::string& input)
{
    std::getline(std::cin, input);
}


void Input::Display() const
{
    std::cout << lastInput << std::endl;
}

