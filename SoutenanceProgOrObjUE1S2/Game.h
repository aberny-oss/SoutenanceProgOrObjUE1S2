#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // pour std::transform
#include <cctype>    // pour std::tolower
#include "Manager.h"

class Game {
private:
    bool isRunning;
    int turn;

public:
    Game() : isRunning(false), turn(1) {};

    void Init();
    void Run();
    void Shutdown();
};


