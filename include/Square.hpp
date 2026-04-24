#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.hpp"

class Square : public Shape {
private:
    Vector vertices[4];

public:
    Square(const std::string& name, const Vector& C, const Vector& V);

    double area() const;
    double perimeter() const;
    bool contains(const Vector& v) const;
};

#endif
