#pragma once
#include <iostream>
#include <string>
#include <vector>

class ASCIIART {
private:
    std::string inputValue; // stocke la chaîne
public:
    ASCIIART() = default;

    void SetInput(const std::string& str);
    void ARTCharacter(const std::string& type);
    void ARTConsoleMenu(int action); // plus besoin de paramètre
};