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

Vector Vector::rotate(double angle) const {
    double rotatedX = x * std::cos(angle) - y * std::sin(angle);
    double rotatedY = x * std::sin(angle) + y * std::cos(angle);
    return Vector(rotatedX, rotatedY);
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

double Vector::cross(const Vector& v) const {
    return x * v.getY() - y * v.getX();
}

std::ostream& operator<<(std::ostream& os, const Vector& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}
