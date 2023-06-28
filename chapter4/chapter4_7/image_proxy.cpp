#include "def.h"
#include "image_proxy.h"

// Graphic ===================================

Graphic::Graphic() {
}

Graphic::~Graphic() {
}

// Image =====================================

Image::Image(const char *file) {
    UNUSED(file);
}

Image::~Image() {
}

void Image::Draw(const Point &at) {
    UNUSED(at);
}

void Image::HandleMouse(Event &event) {
    UNUSED(event);
}

const Point &Image::GetExtent() {
    Point *p = new Point;
    return *p;
}

void Image::Load(std::istream &from) {
    UNUSED(from);
}

void Image::Save(std::ostream &to) {
    UNUSED(to);
}

ImageProxy::ImageProxy(const char *imageFile) {
    _fileName = strdup(imageFile);
    _extent = Point::Zero; // dont know extent yet.
    _image = 0;            // NULL
}

ImageProxy::~ImageProxy() {
}

Image *ImageProxy::GetImage() {
    if (_image == 0) {
        _image = new Image(_fileName);
    }
    return _image;
}

// 如果可能的话, (GetExtent)的实现部分返回缓存的图像尺寸(文档无需加载图像,知道尺寸即可进行排版)
const Point &ImageProxy::GetExtent() {
    if (_extent == Point::Zero) {
        _extent = GetImage()->GetExtent();
    }
    return _extent;
}

void ImageProxy::Draw(const Point &at) {
    GetImage()->Draw(at);
}

void ImageProxy::HandleMouse(Event &event) {
    GetImage()->HandleMouse(event);
}

void ImageProxy::Load(std::istream &from) {
    from >> _extent >> _fileName;
}

void ImageProxy::Save(std::ostream &to) {
    to << _extent << _fileName;
}

TextDocument::TextDocument() {
}

void TextDocument::Insert(Graphic *) {
}