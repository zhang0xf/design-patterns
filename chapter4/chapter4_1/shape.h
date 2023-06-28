#ifndef SHAPE_H
#define SHAPE_H

#include "point.h"

class Manipulator;

// 图形对象的接口抽象类

// (Shape)假定有一个边框, 这个边框由它相对的两角定义
// (Shape)同时定义了(CreateManipulator)操作用于创建一个(Manipulator)对象, (Manipulator)对象知道如何驱动用户操作的图形

class Shape {
public:
    Shape();
    virtual void BoundingBox(Point &bottomLeft, Point &topRight) const;
    virtual Manipulator *CreateManipulator() const;
};

#endif