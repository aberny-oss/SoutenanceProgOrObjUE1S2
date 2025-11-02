#include "Input.h"

// Définition des membres statiques
const std::string Input::PLAY_GAME = "j";
const std::string Input::QUIT_GAME = "q";

// lit une entrée utilisateur
void Input::Update()
{
    std::getline(std::cin, lastInput);
}

void Input::Display() const
{
    std::cout << lastInput << std::endl;
}

