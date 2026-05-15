#include "Triangle.hpp"

Triangle::Triangle(const std::string& name, const Vector& C, const Vector& V) : Shape(name, C) {
    Vector R = V - C;
    Vector curr = V;
    for (size_t i = 0; i < 3; i++) {
        vertices[i] = curr;
        R = R.rotate(M_PI / 3);
        curr = C + R;
    }
}

double Triangle::area() const {
    double R = C.distance(vertices[0]);
    return ((3 * std::sqrt(3)) / 4) * R*R;
}
double Triangle::perimeter() const {
    double side = vertices[0].distance(vertices[1]);
    return side * 3;
}
bool Triangle::contains(const Vector& v) const {
    const Vector& A = vertices[0];
    const Vector& B = vertices[1];
    const Vector& D = vertices[2];

    double c1 = (B - A).cross(v - A);
    double c2 = (D - B).cross(v - B);
    double c3 = (A - D).cross(v - D);

    return (c1 > 0 && c2 > 0 && c3 > 0) || (c1 < 0 && c2 < 0 && c3 < 0);
}
void Triangle::print() const {
    std::cout << name << " (háromszög)\n\tKözéppont: " << C 
        << "\n\tPontjai: ";
    for (size_t i = 0; i < 3; i++)
        std::cout << vertices[i] << " ";
    std::cout << std::endl;
}