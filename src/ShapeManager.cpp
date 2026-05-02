#include <iostream>
#include <string>
#include "ShapeManager.hpp"

ShapeManager::ShapeManager() : len(0), capacity(16) {
    shapes = new Shape*[capacity];
    for (size_t i = 0; i < capacity; i++)
        shapes[i] = nullptr;
}

ShapeManager::~ShapeManager() {
    for (std::size_t i = 0; i < capacity; i++)
        delete shapes[i];
    delete[] shapes;
}

int ShapeManager::findIndex(const std::string& name) const {
    for (std::size_t i = 0; i < len; i++)
    if (shapes[i]->getName() == name) return (int)i;
    return -1;
}

Shape* ShapeManager::find(const std::string& name) const {
    int index = findIndex(name);
    if (index == -1) return nullptr;
    return shapes[index];
}

bool ShapeManager::addShape(Shape* s) {
    if (s == nullptr) return false;
    if (findIndex(s->getName()) != -1) return false;
    if (len == capacity) {
        const std::size_t oldCapacity = capacity;
        capacity += 16;
        Shape** temp = new Shape*[capacity];
        for (std::size_t i = 0; i < len; i++)
            temp[i] = shapes[i];
        for (std::size_t i = oldCapacity; i < capacity; i++)
            temp[i] = nullptr;
        delete[] shapes;
        shapes = temp;
    }
    
    shapes[len++] = s;
    return true;
}

bool ShapeManager::deleteShape(const std::string& name) {
    int index = findIndex(name);
    if (index == -1) return false;

    delete shapes[index];
    if (index != (int)len - 1) 
        shapes[index] = shapes[len - 1];
    
    shapes[len - 1] = nullptr;
    --len;

    return true;
}

std::size_t ShapeManager::size() const {
    return len;
}
