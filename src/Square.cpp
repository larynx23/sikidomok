#include "Square.hpp"

Square::Square(const std::string& name, const Vector& C, const Vector& V) : Shape(name, C) {
    Vector R = V - C;
    Vector curr = V;
    for (size_t i = 0; i < 4; i++) {
        vertices[i] = curr;
        R = R.rotate(M_PI / 2);
        curr = C + R;
    }
}

double Square::area() const {
    double side = vertices[0].distance(vertices[1]);
    return side*side;
}
double Square::perimeter() const {
    double side = vertices[0].distance(vertices[1]);
    return side * 4;
}
bool Square::contains(const Vector& v) const {
    Vector AM = v - vertices[0];
    Vector AB = vertices[1] - vertices[0];
    Vector AD = vertices[3] - vertices[0];

    return (0 < AM * AB && AM * AB < AB * AB)
        && (0 < AM * AD && AM * AD < AD * AD);
}
void Square::print() const {
    std::cout << name << " (négyzet)\n\tKözéppont: " << C 
        << "\n\tPontjai: ";
    for (size_t i = 0; i < 4; i++)
        std::cout << vertices[i] << " ";
    std::cout << std::endl;
}