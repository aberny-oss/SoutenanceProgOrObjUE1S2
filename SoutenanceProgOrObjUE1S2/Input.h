#pragma once
#include <iostream>
#include <string>

class Input
{
private:

	// peut contenir une lettre, un nombre ou plusieurs caractères
	std::string lastInput;
public:

	//liste des différentes touches
	static const std::string PLAY_GAME;
	static const std::string QUIT_GAME;


	Input() : lastInput() {}

	// lit une entrée utilisateur
	std::string Update();

    // affiche la dernière touche
	void Display() const;

	std::string GetLastInput() const;

	static bool IsPressKey(std::string c);


};

