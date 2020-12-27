#ifndef IMAGE_DATABASE
#define IMAGE_DATABASE

#include <map>
#include <raylib.h>
#include "JSImage.h"

class ImageDatabase {
    private:
        static std::map<unsigned int, Image> _images;
        static unsigned int _current;
    public:
        static JSImage AddImage(Image image);
        static Image* GetImage(JSImage image);
        static void RemoveImage(JSImage image);
};
#endif
