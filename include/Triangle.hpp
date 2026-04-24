#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.hpp"

class Triangle : public Shape {
private:
    Vector vertices[3];

public:
    Triangle(const std::string& name, const Vector& C, const Vector& V);

    double area() const;
    double perimeter() const;
    bool contains(const Vector& v) const;
};

#endif
