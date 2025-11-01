#include "Utils.h"
#include <iostream>

std::string AskStr(const std::string& msg, const std::vector<std::string>& validChoices)
{
    std::string choice;
    bool valid = false;

    do
    {
        std::cout << msg << " (";
        for (size_t i = 0; i < validChoices.size(); ++i)
        {
            std::cout << validChoices[i];
            if (i < validChoices.size() - 1)
                std::cout << " / ";
        }
        std::cout << ") : ";

        std::cin >> choice;
        valid = false;

        // Vérification sans algorithm
        for (size_t i = 0; i < validChoices.size(); ++i)
        {
            if (choice == validChoices[i])
            {
                valid = true;
                break;
            }
        }

        if (!valid)
        {
            std::cout << "Commande incorrecte ! Réessaie.\n";
        }

    } while (!valid);

    return choice;
}

int AskInt(const std::string& msg, int min, int max)
{
    int choice;
    do
    {
        std::cout << msg << std::endl;
        std::cin >> choice;

        if (choice < min || choice > max)
        {
            std::cout << "Commande Incorrecte! " << std::endl;
        }

    } while (choice < min || choice > max);

    return choice;
}

