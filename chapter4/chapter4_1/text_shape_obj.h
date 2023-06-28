#ifndef TEXT_SHAPE_OBJ_H
#define TEXT_SHAPE_OBJ_H

#include "shape.h"
#include "text_view.h"

// 对象适配器(区别于类适配器)

// 对象适配器采用对象组合的方法将具有不同接口的类组合在一起. 在该方法中, 适配器TextShape维护一个指向TextView的指针
class TextShapeObj : public Shape {
public:
    TextShapeObj(TextView *);

    virtual void BoundingBox(Point &, Point &) const;
    virtual bool IsEmpty() const;
    virtual Manipulator *CreateManipulator() const;

private:
    TextView *_text;
};

#endif