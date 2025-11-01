#include "Game.h"



void Game::Init() {
    std::cout << "=== Initialisation du jeu ===\n";
    isRunning = true;
    std::string input;

    characterManager.Add(std::make_unique<Warrior>("hero1"));
    characterManager.Add(std::make_unique<Warrior>("Vilain1"));

    hero = characterManager.Get(0);
    ennemy = characterManager.Get(1);

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
        inp.Update(); // inp est un objet Input

        if (inp.GetLastInput() == Input::PLAY_GAME) {
            action = 2;
            menuID = 1;
            break;
        }
        else if (inp.GetLastInput() == Input::QUIT_GAME) {
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
    bool stay = true;

    while (stay)
    {
        system("cls"); // efface l'écran à chaque boucle
        hero->DisplayCharacter(); // affiche le chevalier

        inp.Update(); // récupère l'entrée utilisateur
        std::string input = inp.GetLastInput();

        if (input == "q") // exemple : quitter le menu perso
            stay = false;

        // tu peux ici gérer d'autres commandes comme "i" pour inventaire, etc.
    }
}

void Game::Shutdown() {
     int action = 3;
    art.ARTConsoleMenu(action);
    // Les unique_ptr du manager se libèrent automatiquement
}
