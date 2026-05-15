#ifndef SHAPEMANAGER_H
#define SHAPEMANAGER_H

#include <iostream>
#include <string>

#include "Shape.hpp"

class ShapeManager {
private:
    Shape** shapes;
    std::size_t len;
    std::size_t capacity;

public:
    ShapeManager();
    ~ShapeManager();

    bool addShape(Shape* s);
    bool deleteShape(const std::string& name);
    int findIndex(const std::string& name) const;
    Shape* find(const std::string& name) const;
    void list();

    std::size_t size() const;
};

#endif
