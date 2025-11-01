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
	void Update();

    // affiche la dernière touche
	void Display() const;

	std::string GetLastInput() const
	{
		return lastInput;
	}

	static bool IsPressKey(std::string c)
	{
		return c == PLAY_GAME || c == QUIT_GAME;
	}


};

