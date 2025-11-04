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
        case GameState::COMBAT: StartCombat(); break;
        //case GameState::VICTORY: ShowVictory(); break;
        //case GameState::DEFEAT: ShowDefeat(); break;
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
        input = inp.Update();

        // Mettre à jour l'affichage dynamique
        art.SetInput(input);

        if (input == Input::PLAY_GAME)
        {
            art.ARTConsoleMenu(action);
            menuID = 1;
            break;
        }
        else if (input == Input::QUIT_GAME)
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
    if (firstIteration == true)
    {
        system("cls");
        CreateCharacter();
        firstIteration = false;
        /*characterManager.BuildPriorityTable2D("Ennemy", 2, 2);*/
    }
    characterManager.ONEBuildPriorityTable2D("Player", 1, 1);
    bool stay = true;
    while (stay)
    {
        system("cls");
        characterManager.DisplayTable2D();
        std::cout << "Que souhaite vous faire Combattre (j) ou quitter le jeu (q)" << std::endl;
        input = inp.Update();

        if (input == Input::PLAY_GAME)
        {
            state = GameState::COMBAT;
            break;
        }
        else if (input == Input::QUIT_GAME)
        {
            state = GameState::QUIT;
            break;
        }

        stay = false;
    }

}

    void Game::Attack()
    {
        int intInput;
        // Récupère tous les personnages de l'équipe "Player" :
        std::vector<Character*> players = characterManager.FindByTeam("Player");
        std::vector<Character*> ennemys = characterManager.FindByTeam("Ennemy");
    

        system("cls");
        std::cout << "Quel attaque voulez vous utiliser ? \n" << std::endl;

        // Prend le premier joueur (si plusieurs joueurs, à adapter)
        int nbAttacks = players[0]->GetNbAttacks();
        std::cout << "Nombre d'attaques du joueur : " << nbAttacks << std::endl;
        std::cout << "Choisissez une attaque (1-" << nbAttacks << "): ";
        intInput = u.AskInt("", 1, nbAttacks);

        system("cls");
        players[0]->AttackByIndex(intInput);


        while (true)
        {
            
            std::cout << "Sur qui ? (Entre son numero) \n" << std::endl;
            std::cin >> intInput;

            int position = 0;
            if (intInput < 1 || intInput > characterManager.Size())
            {
                std::cout << "Nombre trop grand ou trop petit !" << std::endl;
            }
            if (position == intInput)
            {
                std::cout << position;
                break;
            }
            position += 1;
        }
    
    }

void Game::StartCombat()
{
    bool fight = true;
    characterManager.BuildPriorityTable2D("Ennemy", 2, 2);
    while (fight)
    {
        system("cls");
        characterManager.DisplayTable2D();
        std::cout << "Que souhaite vous faire : Attaquer/Soigner" << std::endl;
        Attack();

        inp.Update();
        input = inp.GetLastInput();




    }
    



}

void Game::Shutdown() {
     int action = 2;
     system("cls");
    art.ARTConsoleMenu(action);
    // Les unique_ptr du manager se libèrent automatiquement
}
