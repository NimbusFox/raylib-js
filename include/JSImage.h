#ifndef JSIMAGE
#define JSIMAGE

typedef struct JSImage {
    unsigned int id;
    int width;
    int height;
    int mipmaps;
    int format;
} JSImage;
#endif
