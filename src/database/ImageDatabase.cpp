#include "database/ImageDatabase.h"

std::map<unsigned int, Image> ImageDatabase::_images = std::map<unsigned int, Image>();
unsigned int ImageDatabase::_current = 0;

JSImage ImageDatabase::AddImage(Image image) {
    auto jsImage = JSImage();
    jsImage.id = _current++;

    _images.insert({jsImage.id, image});

    jsImage.format = image.format;
    jsImage.height = image.height;
    jsImage.mipmaps = image.mipmaps;
    jsImage.width = image.width;

    return jsImage;
}

Image* ImageDatabase::GetImage(JSImage image) {
    return &_images[image.id];
}

void ImageDatabase::RemoveImage(JSImage image) {
    auto im = GetImage(image);
    UnloadImage(*im);
    _images.erase(image.id);
}
