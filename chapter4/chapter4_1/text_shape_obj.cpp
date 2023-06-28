#include "text_shape_obj.h"
#include "manipulator.h"

TextShapeObj::TextShapeObj(TextView *text) :
    _text(text) {
}

void TextShapeObj::BoundingBox(Point &bottomLeft, Point &topRight) const {
    Coord bottom, left, width, height;

    _text->GetOrigin(bottom, left);
    _text->GetExtent(width, height);

    bottomLeft = Point(bottom, left);
    topRight = Point(bottom + height, left + width);
}

bool TextShapeObj::IsEmpty() const {
    return true;
}

Manipulator *TextShapeObj::CreateManipulator() const {
    return new TextManipulator(this);
}