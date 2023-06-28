#include "text_shape.h"
#include "manipulator.h"
#include "text_shape_obj.h"

// 适配器(TextShape)使(TextView)对象兼容(Shape)接口, 使之能被(Manipulator)驱动

int main() {
    // 类适配器(TODO)
    TextShape ts;
    Manipulator *mp = ts.CreateManipulator();
    mp->ChangeShape();

    // 对象适配器
    TextView tv;
    TextShapeObj tso(&tv);
    Manipulator *mp2 = tso.CreateManipulator();
    mp2->ChangeShape();

    return 0;
}