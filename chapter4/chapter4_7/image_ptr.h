#ifndef IMAGE_PTR_H
#define IMAGE_PTR_H

// 详见(image_proxy.h)
class Image {
public:
    Image(const char *);
    // ...
};

// 假设图像存储在一个文件中
extern Image *LoadAnImageFile(const char *);

// external functions

// (ImagePtr)并非对每一种代理来说都是好方法, 有些代理需要清楚地知道调用了哪一个操作.
class ImagePtr {
public:
    ImagePtr(const char *imageFile);
    virtual ~ImagePtr();

    // 重载->运算符, 使你可以在撤销对一个对象的引用时, 执行一些附加操作.
    virtual Image *operator->();
    virtual Image &operator*();

private:
    Image *LoadImage();

private:
    Image *_image;
    const char *_imageFile;
};

#endif