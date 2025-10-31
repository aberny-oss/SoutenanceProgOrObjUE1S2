#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include "Character.h"

template <typename T>
class Manager {
private:
    std::vector<std::unique_ptr<T>> objects;


public:

    void Add(std::unique_ptr<T> obj) {
        objects.push_back(std::move(obj));
    }

    void UpdateAll() {
        for (auto& obj : objects)
            obj->Update();
    }

    void DisplayAll() const {
        for (const auto& obj : objects)
            obj->Display();
    }

    // Option bonus : rechercher un objet par nom
    T* FindByName(const std::string& name) {
        for (auto& obj : objects)
            if (obj->GetName() == name)
                return obj.get();
        return nullptr;
    }


    void Remove(size_t index) {
        if (index < objects.size())
            objects.erase(objects.begin() + index);
    }
};