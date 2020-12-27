#ifndef JSFONT
#define JSFONT

typedef struct JSFont {
    int baseSize;
    int charsCount;
    int charsPadding;
    Texture2D texture;
    unsigned int id;
} JSFont;
#endif