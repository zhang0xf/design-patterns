#ifndef MANIPULATOR_H
#define MANIPULATOR_H

#include "shape.h"

// (Manipulator)类是一个抽象类,它所描述的对象知道如何驱动Shape类响应相应的用户输入,如: 将图形拖动到一个新的位置.

class Manipulator {
public:
    Manipulator(const Shape *);

    virtual void ChangeShape();

protected:
    const Shape *_shape; //被操作的Shape对象
};

class TextManipulator : public Manipulator {
public:
    TextManipulator(const Shape *shape);

    virtual void ChangeShape();
};

#endif