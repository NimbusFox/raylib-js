#include "database/FontDatabase.h"

std::map<unsigned int, Font> FontDatabase::_fonts = std::map<unsigned int, Font>();
unsigned int FontDatabase::_current = 0;

JSFont FontDatabase::AddFont(Font font) {
    auto jsFont = JSFont();
    jsFont.id = _current++;

    _fonts.insert({jsFont.id, font});

    jsFont.baseSize = font.baseSize;
    jsFont.charsCount = font.charsCount;
    jsFont.charsPadding = font.charsPadding;
    jsFont.texture = font.texture;

    return jsFont;
}

Font FontDatabase::GetFont(JSFont font) {
    return _fonts[font.id];
}

void FontDatabase::RemoveFont(JSFont font) {
    auto fnt = GetFont(font);
    UnloadFont(fnt);
    _fonts.erase(font.id);
}