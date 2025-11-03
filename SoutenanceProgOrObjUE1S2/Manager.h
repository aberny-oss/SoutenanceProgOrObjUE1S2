#pragma once
#include <vector>
#include <memory>
#include <string>
#include <functional> // pour ForEach
#include <algorithm>  // pour erase if besoin
#include <iostream>   // optionnel, si tu veux debug print

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

    // Mettre à jour tous les objets : exige T::Update() sans param
    /*void UpdateAll() {
        for (auto& obj : objects)
        {
            if (obj) obj->Update();
        }
    }*/

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

    std::vector<T*> DisplayAllWithPriority(const std::string& teamPriority = "")
    {
        std::vector<T*> result;
        T* priorityObj = nullptr;

        for (auto& obj : objects) {
            if (!obj)
            {
                continue;
            }
            if (!teamPriority.empty() && obj->GetTeam() == teamPriority) {
                priorityObj = obj.get(); // garder en mémoire le perso prioritaire
            }
            else {
                result.push_back(obj.get());
            }
        }

        // Si on a trouvé le perso prioritaire, on le met devant
        if (priorityObj) result.insert(result.begin(), priorityObj);

        return result;
    }

    std::vector<T*> DisplayByTeam() const
    {
        std::vector<T*> result;
        T* teamObj = nullptr;

        for (const auto& obj : objects)
            if (!obj)
            {
                continue;
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

    void DisplayTable2D() const
    {
        for (size_t i = 0; i < tableRows; ++i)
        {
            // Récupérer toutes les données pour cette rangée
            std::vector<std::vector<std::string>> allASCII;
            int maxLines = 0;

            for (size_t j = 0; j < tableCols; ++j)
            {
                if (table2D[i][j]) {
                    allASCII.push_back(table2D[i][j]->Display());
                }
                else {
                    // Case vide avec bordure
                    std::vector<std::string> emptyBox = {""};
                    allASCII.push_back(emptyBox);
                }

                if (allASCII.back().size() > maxLines) {
                    maxLines = allASCII.back().size();
                }
            }

            // Afficher l'ASCII art ligne par ligne (avec infos intégrées)
            for (int line = 0; line < maxLines; ++line)
            {
                for (size_t j = 0; j < tableCols; ++j)
                {
                    if (line < allASCII[j].size()) {
                        std::cout << allASCII[j][line];
                    }
                    else {
                        std::cout << "                ";
                    }
                    std::cout << " "; // Espace entre colonnes
                }
                std::cout << "\n";
            }

            // Séparateur entre rangées
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
