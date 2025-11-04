#include "Input.h"

// Définition des membres statiques
const std::string Input::PLAY_GAME = "j";
const std::string Input::QUIT_GAME = "q";

// lit une entrée utilisateur
std::string Input::Update()
{
    std::getline(std::cin, lastInput);
	return lastInput;
}

void Input::Display() const
{
    std::cout << lastInput << std::endl;
}

std::string Input::GetLastInput() const
{
	return lastInput;
}

bool Input::IsPressKey(std::string c)
{
	return c == PLAY_GAME || c == QUIT_GAME;
}

