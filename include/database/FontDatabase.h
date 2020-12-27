#ifndef FONT_DATABASE
#define FONT_DATABASE

#include <map>
#include <raylib.h>
#include "JSFont.h"

class FontDatabase {
private:
    static std::map<unsigned int, Font> _fonts;
    static unsigned int _current;
public:
    static JSFont AddFont(Font font);

    static Font GetFont(JSFont font);

    static void RemoveFont(JSFont font);
};
#endif