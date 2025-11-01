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

public:
    Manager() = default;
    ~Manager() = default;

    // Ajouter un objet (on passe un unique_ptr)
    void Add(std::unique_ptr<T> obj) {
        objects.push_back(std::move(obj));
    }

    // Obtenir un objet par index (nullptr si hors limite)
    T* Get(size_t index) {
        if (index < objects.size())
            return objects[index].get();
        return nullptr;
    }

    // Nombre d'objets
    size_t Size() const { return objects.size(); }

    // Supprimer par index
    void Remove(size_t index) {
        if (index < objects.size())
            objects.erase(objects.begin() + index);
    }

    // Vider tous les objets
    void Clear() { objects.clear(); }

    // Mettre à jour tous les objets : exige T::Update() sans param
    void UpdateAll() {
        for (auto& obj : objects)
            if (obj) obj->Update();
    }

    // Afficher tous les objets : exige T::Display() const ou non
    void DisplayAll() const {
        for (const auto& obj : objects)
            if (obj) obj->Display();
    }

    // Rechercher par nom : exige T::GetName() const -> std::string (ou compatible)
    T* FindByName(const std::string& name) {
        for (auto& obj : objects) {
            if (obj && obj->GetName() == name)
                return obj.get();
        }
        return nullptr;
    }

    // Appliquer une lambda / fonction à tous les objets
    void ForEach(const std::function<void(T&)>& fn) {
        for (auto& obj : objects)
            if (obj) fn(*obj);
    }
};
