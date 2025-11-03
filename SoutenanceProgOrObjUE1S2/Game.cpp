#include "Game.h"



void Game::Init() {
    std::cout << "=== Initialisation du jeu ===\n";
    isRunning = true;
    std::string input;

    characterManager.Add(std::make_unique<Warrior>("Vilain1", "Ennemy"));
    characterManager.Add(std::make_unique<Goblin>("Vilain2", "Ennemy"));


    /*Manager<Item> itemManager;
    itemManager.Add(std::make_unique<Item>("Epee legendaire"));
    itemManager.Add(std::make_unique<Item>("Potion de soin"));

    Manager<Quest> questManager;
    questManager.Add(std::make_unique<Quest>("Sauver le village"));*/

}

void Game::CreateCharacter()
{
    std::string name, type;
    std::cout << "Veuillez entrer votre nom de personnage : ";
    std::getline(std::cin, name);
    while (true)
    {
        std::cout << "Type du personnage (Warrior / Mage / Goblin) : ";
        std::getline(std::cin, type);

        // Conversion en minuscules
        std::transform(type.begin(), type.end(), type.begin(),
            [](unsigned char c) { return std::tolower(c); });

        if (type == "warrior")
        {
            return characterManager.Add(std::make_unique<Warrior>(name, "Player"));
        }
        else if (type == "mage")
        {
            return characterManager.Add(std::make_unique<Mage>(name, "Player"));
        }
        else if (type == "goblin")
        {
            return characterManager.Add(std::make_unique<Goblin>(name, "Player"));
        }

        system("cls");
        std::cout << "Type invalide. Reessaie !" << std::endl;
    }
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
        case GameState::QUIT: Shutdown(); break;
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
        input = inp.GetLastInput();

        // Mettre à jour l'affichage dynamique
        art.SetInput(input);

        if (inp.GetLastInput() == Input::PLAY_GAME)
        {
            art.ARTConsoleMenu(action);
            menuID = 1;
            break;
        }
        else if (inp.GetLastInput() == Input::QUIT_GAME)
        {
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

        if (firstIteration == true)
        {
            CreateCharacter();
            firstIteration = false;
            // 1 Construire le tableau une fois
            /*characterManager.BuildPriorityTable2D("Ennemy", 2, 2);*/
        }
        system("cls");
        /*characterManager.DisplayByTeam("Player");*/
        characterManager.ONEBuildPriorityTable2D("Player", 1, 1);
        // 2 Afficher autant de fois que tu veux
        characterManager.DisplayTable2D();
        inp.Update();

        stay = false;
    }

}

void Game::Shutdown() {
     int action = 2;
     system("cls");
    art.ARTConsoleMenu(action);
    // Les unique_ptr du manager se libèrent automatiquement
}
