#include "Game.h"



void Game::Init() {
    std::cout << "=== Initialisation du jeu ===\n";
    isRunning = true;
    // on ajoute un Input au manager
    inputManager.Add(std::make_unique<Input>());
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
    while (true) {

        art.ARTConsoleMenu(action);
        inputManager.UpdateAll();   // lit la touche
        //inputManager.DisplayAll();  // affiche la touche

        // on récupère le premier Input géré
        Input* inp = inputManager.Get(0);
        if (!inp) continue;

        // on vérifie la commande
        std::string value = inp->GetLastInput();
        if (value == Input::PLAY_GAME) {
            action = 2;
            art.ARTConsoleMenu(action);
            menuID = 1;
            break;
        }
        else if (value == Input::QUIT_GAME) {
            action = 3;
            art.ARTConsoleMenu(action);
            state = GameState::QUIT;
            break;
        }
        else {
            action = 1;
        }
    }
}

void Game::ShowMenuPerso()
{
    bool first = true;
    if (first == true)
    {
        art.ARTPersoMenu();


    }
    first = false;

}

void Game::Shutdown() {
     int action = 3;
    art.ARTConsoleMenu(action);
    // Les unique_ptr du manager se libèrent automatiquement
}
