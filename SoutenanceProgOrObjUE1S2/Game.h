#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // pour std::transform
#include <cctype>    // pour std::tolower
#include "Manager.h"
#include "ASCIIART.h"
#include "Utils.h"
#include "Input.h"
#include "Warrior.h"

enum class GameState{MENU, COMBAT, VICTORY, DEFEAT, QUIT};

enum class Mode{MODE_TEXT, MODE_GAME};

class Game {
private:
    bool isRunning;
    int turn;
    GameState state;     // état actuel du jeu
    Mode mode;
    int menuID;          // 0 = menu principal, 1 = inventaire, etc.
    ASCIIART art;        // menu ASCII
    Input inp;           // gestionnaire d'input
    std::string input;   // input utilisateur

public:

    Game() : isRunning(false), turn(1), state(GameState::MENU), mode(Mode::MODE_GAME), menuID(0), art()
    {
        art.SetInput(&input); // on passe le pointeur de input à ASCIIART
    }

    void Init();


    void Run();

    //menu
    void ShowMenuPrincipal();
    void ShowMenuPerso();
    //void ShowMenuInventaire();
    //void ShowMenuPause();

    //combat
    /*void StartCombat();*/

    //victoire
    /*void ShowVictory();*/

    //defaite
    /*void ShowDefeat();*/

    void Shutdown();
};


