#ifndef TEXT_SHAPE_H
#define TEXT_SHAPE_H

#include "shape.h"
#include "text_view.h"

// 类适配器(区别于对象适配器)

// 类适配器(TextShape)采用多重继承适配接口
// 类适配器的关键是用一个分支继承接口, 而用另外一个分支继承接口的实现部分, 用公共方式(public)继承接口, 用私有方式(private)继承接口的实现
class TextShape : public Shape, private TextView { // 注意继承方式
public:
    TextShape();

    virtual void BoundingBox(Point &bottomLeft, Point &topRight) const;
    virtual bool IsEmpty() const;
    virtual Manipulator *CreateManipulator() const;
};

#endif