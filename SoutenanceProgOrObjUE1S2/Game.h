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

enum class GameState{MENU, COMBAT, VICTORY, DEFEAT, QUIT};

enum class Mode{MODE_TEXT, MODE_GAME};

class Game {
private:
    bool isRunning;
    int turn;
    GameState state; // state contient l'état actuel du jeu
    Mode mode;
    int menuID; // 0 = principal, 1 = inventaire, 2 = pause...
    Manager<Input> inputManager;
    ASCIIART art;

public:
    Game() : isRunning(false), turn(1), state(GameState::MENU), mode(Mode::MODE_GAME), menuID(0), art(inputManager) {}

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


