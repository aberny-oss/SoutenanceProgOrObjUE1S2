#include "Game.h"



void Game::Init() {
    std::cout << "=== Initialisation du jeu ===\n";
    isRunning = true;
}

void Game::Run() {
    while (isRunning) {
        
    }
}

void Game::Shutdown() {
    std::cout << "=== Fin du jeu ===\n";
}
