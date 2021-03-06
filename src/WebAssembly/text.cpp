#include <emscripten/bind.h>
#include <emscripten/emscripten.h>
#include <raylib.h>

#include "JSCodepoint.h"

// Bindings up to date with raylib 3.5
// https://www.raylib.com/cheatsheet/cheatsheet.html

Font JSGetFontDefault() {
    return GetFontDefault();
}

Font JSLoadFont(std::string fileName) {
    return LoadFont(fileName.c_str());
}

Font FontLoadEx(std::string fileName, int fontSize, std::vector<int> fontChars) {
    return LoadFontEx(fileName.c_str(), fontSize, fontChars.data(), fontChars.size());
}

Font JSLoadFontFromImage(Image image, Color key, int firstChar) {
    return LoadFontFromImage(image, key, firstChar);
}

Font JSLoadFontFromMemory(std::string fileType, std::vector<unsigned char> fileData, int fontSize, std::vector<int> fontChars) {
    return LoadFontFromMemory(fileType.c_str(), fileData.data(), fileData.size(), fontSize, fontChars.data(), fontChars.size());
}

void JSUnloadFont(Font font) {
    UnloadFont(font);
}

void JSDrawText(std::string text, int posX, int posY, int fontSize, Color color) {
    DrawText(text.c_str(), posX, posY, fontSize, color);
}

void JSDrawTextEx(Font font, std::string text, Vector2 position, float fontSize, float spacing, Color tint) {
    DrawTextEx(font, text.c_str(), position, fontSize, spacing, tint);
}

void JSDrawTextRec(Font font, std::string text, Rectangle rec, float fontSize, float spacing, bool wordWrap, Color tint) {
    DrawTextRec(font, text.c_str(), rec, fontSize, spacing, wordWrap, tint);
}

void JSDrawTextRecEx(Font font, std::string text, Rectangle rec, float fontSize, float spacing, bool wordWrap, Color tint, int selectStart, int selectLength, Color selectTint, Color selectBackTint) {
    DrawTextRecEx(font, text.c_str(), rec, fontSize, spacing, wordWrap, tint, selectStart, selectLength, selectTint, selectBackTint);
}

void JSDrawTextCodepoint(Font font, int codepoint, Vector2 position, float fontSize, Color tint) {
    DrawTextCodepoint(font, codepoint, position, fontSize, tint);
}

int JSMeasureText(std::string text, int fontSize) {
    return MeasureText(text.c_str(), fontSize);
}

Vector2 JSMeasureTextEx(Font font, std::string text, float fontSize, float spacing) {
    return MeasureTextEx(font, text.c_str(), fontSize, spacing);
}

int JSGetGlyphIndex(Font font, int codepoint) {
    return GetGlyphIndex(font, codepoint);
}

int JSTextToInteger(std::string text) {
    return TextToInteger(text.c_str());
}

std::string JSTextToUtf8(std::vector<int> codepoints) {
    return TextToUtf8(codepoints.data(), codepoints.size());
}

std::vector<int> JSGetCodepoints(std::string text) {
    auto count = 0;
    auto output = std::vector<int>();

    auto data = GetCodepoints(text.c_str(), &count);

    for (auto i = 0; i < count; i++) {
        output.push_back(data[i]);
    }

    return output;
}

int JSGetCodepointsCount(std::string text) {
    return GetCodepointsCount(text.c_str());
}

JSCodepoint JSGetNextCodepoint(std::string text) {
    auto val = JSCodepoint();

    val.result = GetNextCodepoint(text.c_str(), &val.bytesProcessed);

    return val;
}

std::string JSCodepointToUtf8(int codepoint) {
    auto _ = 0;
    return CodepointToUtf8(codepoint, &_);
}

EMSCRIPTEN_BINDINGS(raylibWebText) {
    // Font loading/unloading functions
    emscripten::function("GetFontDefault", &JSGetFontDefault);
    emscripten::function("LoadFont", &JSLoadFont);
    emscripten::function("LoadFontEx", &FontLoadEx);
    emscripten::function("LoadFontFromImage", &JSLoadFontFromImage);
    emscripten::function("LoadFontFromMemory", &JSLoadFontFromMemory);
    //emscripten::function("LoadFontData", &LoadFontData);
    //emscripten::function("GenImageFontAtalas", &GenImageFontAtlas);
    //emscripten::function("UnloadFontData", &UnloadFontData);
    emscripten::function("UnloadFont", &JSUnloadFont);

    // Text drawing functions
    emscripten::function("DrawFPS", &DrawFPS);
    emscripten::function("DrawText", &JSDrawText);
    emscripten::function("DrawTextEx", &JSDrawTextEx);
    emscripten::function("DrawTextRec", &JSDrawTextRec);
    emscripten::function("DrawTextRecEx", &JSDrawTextRecEx);
    emscripten::function("DrawTextCodepoint", &JSDrawTextCodepoint);

    // Text misc. functions
    emscripten::function("MesureText", &JSMeasureText);
    emscripten::function("MeasureTextEx", &JSMeasureTextEx);
    emscripten::function("GetGlyphIndex", &JSGetGlyphIndex);

    // Text strings management functions (no utf8 strings, only byte chars)
    // NOTE: Some strings allocate memory internally for returned strings, just be careful!

    //emscripten::function("TextCopy", &TextCopy);
    //emscripten::function("TextIsEqual", &TextIsEqual);
    //emscripten::function("TextLength", &TextLength);
    //emscripten::function("TextFormat", &TextFormat);
    //emscripten::function("TextSubtext", &TextSubtext);
    //emscripten::function("TextReplace", &TextReplace);
    //emscripten::function("TextInsert", &TextInsert);
    //emscripten::function("TextJoin", &TextJoin);
    //emscripten::function("TextAppend", &TextAppend);
    //emscripten::function("TextFindIndex", &TextFindIndex);
    //emscripten::function("TextToUpper", &TextToUpper);
    //emscripten::function("TextToLower", &TextToLower);
    //emscripten::function("TextToPascal", &TextToPascal);
    emscripten::function("TextToInteger", &JSTextToInteger);
    emscripten::function("TextToUtf8", &JSTextToUtf8);

    // UTF8 text strings management functions
    emscripten::function("GetCodepoints", &JSGetCodepoints);
    emscripten::function("GetCodepointsCount", &JSGetCodepointsCount);
    emscripten::function("GetNextCodepoint", &JSGetNextCodepoint);
    emscripten::function("CodepointToUtf8", &JSCodepointToUtf8);
}
