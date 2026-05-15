#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.hpp"

class Circle : public Shape {
private:
    double R;

public:
    Circle(const std::string& name, const Vector& C, const Vector& V);

    double area() const;
    double perimeter() const;
    bool contains(const Vector& v) const;
    void print() const override;
};

#endif
