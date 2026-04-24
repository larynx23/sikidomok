#ifndef SHAPE_H
#define SHAPE_H

#include <string>

#include "Vector.hpp"

class Shape {
protected:
    std::string name;
    Vector C;

public:
    Shape(const std::string& name, const Vector& C);
    virtual ~Shape();

    const std::string& getName() const;
    const Vector& getCenter() const;

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual bool contains(const Vector& v) const = 0;
};

#endif
