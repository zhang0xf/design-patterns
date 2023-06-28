#include "image_ptr.h"

int demo() {
    // 重载->运算符使你能够通过(ImagePtr)对象调用(Image)对象的操作, 而省去了把这些操作作为(ImagePtr)接口的一部分的麻烦.
    // ImagePtr image = ImagePtr("filePath");
    // image->Draw(Point(50, 100));
    // (image.operator->())->Draw(Point(50, 100));
    return 0;
}