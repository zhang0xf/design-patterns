#include "text_shape.h"
#include "manipulator.h"

TextShape::TextShape() :
    Shape(), TextView() { // 调用基类构造
}

// (BoundingBox)操作对TextView的接口进行转换,使之匹配Shape的接口
void TextShape::BoundingBox(Point &bottomLeft, Point &topRight) const {
    Coord bottom, left, width, height;

    GetOrigin(bottom, left); // 原点、宽度和高度定义(TextView)
    GetExtent(width, height);

    bottomLeft = Point(bottom, left); // 相对的两角定义(左下和右上)(Shape)
    topRight = Point(bottom + height, left + width);
}

// (IsEmpty)操作给出了在适配器实现过程中常用的一种方法: 直接转发请求
bool TextShape::IsEmpty() const {
    return TextView::IsEmpty();
}

// TextView不支持(CreateManipulator)操作
// 假设我们已经实现了支持(TextShape)操作的类(TextManipulator)
Manipulator *TextShape::CreateManipulator() const {
    return new TextManipulator(this);
}