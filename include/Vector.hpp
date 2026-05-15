#ifndef VECTOR_H
#define VECTOR_H

#include <ostream>

class Vector {
private:
    double x;
    double y;

public:
    Vector(double x = 0.0, double y = 0.0);
    Vector(const Vector& other) = default;
    Vector(Vector&& other) = default;
    Vector& operator=(const Vector& other) = default;
    Vector& operator=(Vector&& other) = default;

    double getX() const;
    double getY() const;

    double length() const;
    double distance(const Vector& v) const;
    Vector rotate(double angle) const;

    Vector operator+(const Vector& v) const;
    Vector operator-(const Vector& v) const;
    Vector operator*(double s) const;
    double operator*(const Vector& v) const;
    bool operator==(const Vector& v) const;

    friend std::ostream& operator<<(std::ostream& os, const Vector& v);
};

#endif
