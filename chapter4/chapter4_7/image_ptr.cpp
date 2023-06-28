#include "image_ptr.h"

ImagePtr::ImagePtr(const char *imageFile) {
    _imageFile = imageFile;
    _image = 0; // NULL
}

ImagePtr::~ImagePtr() {
}

Image *ImagePtr::operator->() {
    return LoadImage();
}

Image &ImagePtr::operator*() {
    return *LoadImage();
}

Image *ImagePtr::LoadImage() {
    if (_image == 0) {
        _image = LoadAnImageFile(_imageFile);
    }
    return _image;
}

Image *LoadAnImageFile(const char *fileName) {
    return new Image(fileName);
}