#include "Shape.hpp"

Shape::Shape(const std::string& name, const Vector& C) : name(name), C(C) {}

Shape::~Shape() {}

const std::string& Shape::getName() const { return name; }
const Vector& Shape::getCenter() const { return C; }