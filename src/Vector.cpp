#include "Vector.hpp"
#include <cmath>

Vector::Vector(double x, double y) : x(x), y(y) {}

double Vector::getX() const { return x; }
double Vector::getY() const { return y; }

double Vector::length() const { return std::sqrt(x*x + y*y); }
double Vector::distance(const Vector& v) const {
    Vector temp(x - v.getX(), y - v.getY());
    return temp.length();
}

Vector Vector::operator+(const Vector& v) const {
    return Vector(x + v.getX(), y + v.getY());
}
Vector Vector::operator-(const Vector& v) const {
    return Vector(x - v.getX(), y - v.getY());
}
Vector Vector::operator*(double s) const {
    return Vector(x * s, y * s);
}
double Vector::operator*(const Vector& v) const {
    return x * v.getX() + y * v.getY();
}
bool Vector::operator==(const Vector& v) const {
    return x == v.getX() && y == v.getY();
}
