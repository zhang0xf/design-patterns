#include <iostream>
#include "manipulator.h"

Manipulator::Manipulator(const Shape *shape) :
    _shape(shape) {
    (void)_shape; // fix error : private field '_shape' is not used
}

void Manipulator::ChangeShape() {
    std::cout << "Manipulator::ChangeShape()" << std::endl;
}

TextManipulator::TextManipulator(const Shape *shape) :
    Manipulator(shape) { // 调用基类构造函数
}

void TextManipulator::ChangeShape() {
    Point bottomLeft, topRight;
    _shape->BoundingBox(bottomLeft, topRight);
    (void)bottomLeft;
    (void)topRight;

    std::cout << "TextManipulator::ChangeShape()" << std::endl;
}