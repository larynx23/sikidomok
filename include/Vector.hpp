#ifndef VECTOR_H
#define VECTOR_H

class Vector {
private:
    double x;
    double y;

public:
    Vector(double x = 0.0, double y = 0.0);

    double getX() const;
    double getY() const;

    double length() const;
    double distance(const Vector& v) const;

    Vector operator+(const Vector& v) const;
    Vector operator-(const Vector& v) const;
    Vector operator*(double s) const;
    double operator*(const Vector& v) const;
    bool operator==(const Vector& v) const;
};

#endif
