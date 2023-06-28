#ifndef GRAPHIC_H
#define GRAPHIC_H

#include "point.h"
#include "event.h"
#include <iostream>

// 虚代理

class Graphic {
public:
    virtual ~Graphic();

    virtual void Draw(const Point &at) = 0;
    virtual void HandleMouse(Event &event) = 0;

    virtual const Point &GetExtent() = 0;

    virtual void Load(std::istream &from) = 0;
    virtual void Save(std::ostream &to) = 0;

protected:
    Graphic();
};

class Image : public Graphic {
public:
    Image(const char *file); // load image from a file
    virtual ~Image();

    virtual void Draw(const Point &at);
    virtual void HandleMouse(Event &event);

    virtual const Point &GetExtent();

    virtual void Load(std::istream &from);
    virtual void Save(std::ostream &to);

private:
    // ...
};

// (ImageProxy)和(Image)具有相同的接口
class ImageProxy : public Graphic {
public:
    ImageProxy(const char *imageFile);
    virtual ~ImageProxy();

    virtual void Draw(const Point &at);     // 装载图像
    virtual void HandleMouse(Event &event); // 向实际图像转发这个事件

    virtual const Point &GetExtent();

    virtual void Load(std::istream &from); // 得到(Save)的信息并初始化相应的成员函数
    virtual void Save(std::ostream &to);   // 将缓存的图像尺寸和文件名保存在一个流中

protected:
    Image *GetImage();

private:
    Image *_image;
    Point _extent;
    char *_fileName;
};

// 最后假设有一个类(TextDocument)能够包含(Graphic)对象
class TextDocument {
public:
    TextDocument();

    void Insert(Graphic *);
    // ...
};

#endif