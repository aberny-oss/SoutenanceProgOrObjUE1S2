#pragma once
#include <iostream>

class ASCIIART {
private:
    std::string* input; // pointeur vers la variable input de Game
public:
    void SetInput(std::string* inputPtr) { input = inputPtr; }
    void ARTCharacter();
    void ARTConsoleMenu(int action); // plus besoin de paramètre
    void ARTPersoMenu();
};