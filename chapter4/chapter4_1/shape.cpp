#include "shape.h"
#include "manipulator.h"

Shape::Shape() {
}

void Shape::BoundingBox(Point &bottomLeft, Point &topRight) const {
    (void)bottomLeft;
    (void)topRight;
}

Manipulator *Shape::CreateManipulator() const {
    return new Manipulator(this);
}