#include "Circle.hpp"

Circle::Circle(const std::string& name, const Vector& C, const Vector& V) 
    : Shape(name, C), R(C.distance(V)) {}

double Circle::area() const { return M_PI*R*R; }
double Circle::perimeter() const { return M_PI*R*2; }
bool Circle::contains(const Vector& v) const {
    double d = C.distance(v);
    return d < R;
}
void Circle::print() const {
    std::cout << name << " (kör)\n\tKözéppont: " << C 
        << "\n\tSugara: " << R << std::endl;
}
