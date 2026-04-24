#ifndef SHAPEMANAGER_H
#define SHAPEMANAGER_H

#include <cstddef>
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
    Shape* find(const std::string& name) const;

    std::size_t size() const;
};

#endif
