#pragma once
#include <vector>
#include <memory>
#include <string>
#include <functional> // pour ForEach
#include <algorithm>  // pour erase if besoin
#include <iostream>   // optionnel, si tu veux debug print
#include "Utils.h"

template <typename T>
class Manager {
private:
    std::vector<std::unique_ptr<T>> objects;
    std::vector<std::vector<T*>> table2D;
    size_t tableRows = 0;
    size_t tableCols = 0;


public:


    // Ajouter un objet (on passe un unique_ptr)
    void Add(std::unique_ptr<T> obj)
    {
        objects.push_back(std::move(obj));
    }

    // Obtenir un objet par index (nullptr si hors limite)
    T* FindByIndex(size_t index)const {
        if (index < objects.size())
        {
            return objects[index].get();
        }
        return nullptr;
    }

    // Nombre d'objets
    size_t Size() const
    {
        return objects.size();
    }

    // Supprimer par index
    void Remove(size_t index) {
        if (index < objects.size())
        {
            objects.erase(objects.begin() + index);
        }
    }

    // Vider tous les objets
    void Clear() { objects.clear(); }

    // Afficher tous les objets : exige T::Display() const ou non
    std::vector<T*> DisplayAll() const
    {
        std::vector<T*> result;
        for (const auto& obj : objects)
        {
            if (!obj)
            {
                continue;
            }
            if (obj) obj->Display();
        }
        return result;
    }

    void ONEBuildPriorityTable2D(const std::string& teamPriority, size_t rows, size_t cols)
    {
        tableRows = rows;
        tableCols = cols;
        table2D.clear();
        table2D.resize(rows, std::vector<T*>(cols, nullptr));

        size_t r = 0, c = 0;

        // Placer d'abord les objets prioritaires
        for (auto& obj : objects) {
            if (!obj)
            {
                continue;
            }
            if (obj->GetTeam() == teamPriority)
            {
                table2D[r][c] = obj.get();
                c++;
                if (c >= cols)
                {
                    c = 0; r++;
                }
                if (r >= rows)
                {
                    return; // tableau plein
                }
            }
        }
    }
    
    void BuildPriorityTable2D(const std::string& teamPriority, size_t rows, size_t cols)
    {
        tableRows = rows;
        tableCols = cols;
        table2D.clear();
        table2D.resize(rows, std::vector<T*>(cols, nullptr));

        size_t r = 0, c = 0;

        // Placer d'abord les objets prioritaires
        for (auto& obj : objects) {
            if (!obj)
            {
                continue;
            }
            if (obj->GetTeam() == teamPriority)
            {
                table2D[r][c] = obj.get();
                c++;
                if (c >= cols)
                {
                    c = 0; r++;
                }
                if (r >= rows)
                {
                    return; // tableau plein
                }
            }
        }

        // Placer ensuite les autres objets
        for (auto& obj : objects) {
            if (!obj)
            {
                continue;
            }
            // Si c'est déjà placé comme prioritaire, on skip
            if (obj->GetTeam() == teamPriority)
            {
                continue;
            }
            table2D[r][c] = obj.get();
            c++;
            if (c >= cols)
            {
                c = 0; r++;
            }
            if (r >= rows)
            {
                return;
            }
        }
    }

    void DisplayTable2D() const {
    int term_width = Utils::getTerminalWidth();
    for (size_t i = 0; i < tableRows; ++i) {
        // 1. Récupère la matrice ASCII de chaque colonne pour la rangée i
        std::vector<std::vector<std::string>> allASCII;
        int maxLines = 0;
        for (size_t j = 0; j < tableCols; ++j) {
            if (table2D[i][j]) {
                allASCII.push_back(table2D[i][j]->Display());
            } else {
                // Ajuste ici la largeur d’une case vide si nécessaire !
                std::vector<std::string> emptyBox = {""};
                allASCII.push_back(emptyBox);
            }
            if (allASCII.back().size() > maxLines)
                maxLines = allASCII.back().size();
        }
        // 2. Affiche la rangée bloc par bloc, ligne après ligne
        for (int line = 0; line < maxLines; ++line) {
            std::string line_content;
            for (size_t j = 0; j < tableCols; ++j) {
                // Si le bloc de la colonne a cette ligne, sinon ligne vide de taille équivalente
                if (line < allASCII[j].size())
                    line_content += allASCII[j][line];
                else
                    line_content += std::string(allASCII[j][0].size(), ' ');
                // Séparateur optionnel entre colonnes
                line_content += " ";
            }
            // 3. Calcul du padding global pour centrer la LIGNE ENTIÈRE
            int padding = (term_width - static_cast<int>(line_content.size())) / 2;
            if (padding > 0) std::cout << std::string(padding, ' ');
            std::cout << line_content << "\n";
        }
        // Optionnel : saut entre rangées/équipes
        std::cout << "\n";
    }
}


    // Rechercher par nom : exige T::GetName() const -> std::string (ou compatible)
    T* FindByName(const std::string& name) {
        for (auto& obj : objects)
        {
            if (obj && obj->GetName() == name)
            {
                return obj.get();
            }
        }
        return nullptr;
    }

    std::vector<T*> FindByTeam(const std::string& team)
    {
        std::vector<T*> result;
        for (auto& obj : objects)
        {
            if (obj && obj->GetTeam() == team)
                result.push_back(obj.get());
        }
        return result;
    }

};
