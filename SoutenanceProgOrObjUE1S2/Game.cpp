#include "Game.h"



void Game::Init() {
    std::cout << "=== Initialisation du jeu ===\n";
    isRunning = true;
    std::string input;

    Manager<Character> characterManager;
    characterManager.Add(std::make_unique<Warrior>("Vilain1"));
    characterManager.Add(std::make_unique<Warrior>("Vilain2"));

    /*Manager<Item> itemManager;
    itemManager.Add(std::make_unique<Item>("Epee legendaire"));
    itemManager.Add(std::make_unique<Item>("Potion de soin"));

    Manager<Quest> questManager;
    questManager.Add(std::make_unique<Quest>("Sauver le village"));*/

}


void Game::Run()
{

    while (state != GameState::QUIT) {
        if (state == GameState::MENU)
        {
            switch (menuID)
            {
            case 0: ShowMenuPrincipal(); break;
            case 1: ShowMenuPerso(); break;
            //case 2: ShowMenuInventaire(); break;
            //case 3: ShowMenuPause(); break;
            }
        }

        switch (state) {
        /*case GameState::COMBAT: StartCombat(); break;
        case GameState::VICTORY: ShowVictory(); break;
        case GameState::DEFEAT: ShowDefeat(); break;*/
        case GameState::QUIT: std::cout << "Fin du jeu !" << std::endl; break;
        }

        turn += 1;
    }
}

void Game::ShowMenuPrincipal()
{
    int action = 0;
    art.ARTConsoleMenu(action); // affiche menu initial

    while (true) {
        inp.Update(input); // inp est un objet Input

        if (input == Input::PLAY_GAME) {
            action = 2;
            menuID = 1;
            break;
        }
        else if (input == Input::QUIT_GAME) {
            action = 3;
            art.ARTConsoleMenu(action);
            state = GameState::QUIT;
            break;
        }
        else {
            action = 1;
            art.ARTConsoleMenu(action);
        }
    }
}

void Game::ShowMenuPerso()
{
    bool first = true;
    if (first == true)
    {
        /*art.ARTPersoMenu();*/


    }
    first = false;

}

void Game::Shutdown() {
     int action = 3;
    art.ARTConsoleMenu(action);
    // Les unique_ptr du manager se libèrent automatiquement
}
