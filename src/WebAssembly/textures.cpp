#include <emscripten/bind.h>
#include <emscripten/emscripten.h>
#include <raylib.h>

#include "JSAnimImage.h"

// Bindings up to date with raylib 3.5
// https://www.raylib.com/cheatsheet/cheatsheet.html

Image JSLoadImage(std::string fileName) {
    return LoadImage(fileName.c_str());
}

Image JSLoadImageRaw(std::string fileName, int width, int height, int format, int headerSize) {
    return LoadImageRaw(fileName.c_str(), width, height, format, headerSize);
}

JSAnimImage JSLoadImageAnim(std::string fileName) {
    auto val = JSAnimImage();

    val.image = LoadImageAnim(fileName.c_str(), &val.frames);

    return val;
}

Image JSLoadImageFromMemory(std::string fileType, std::vector<unsigned char> fileData) {
    return LoadImageFromMemory(fileType.c_str(), fileData.data(), fileData.size());
}

void JSUnloadImage(Image image) {
    UnloadImage(image);
}

Image JSGenImageColor(int width, int height, Color color) {
    return GenImageColor(width, height, color);
}

Image JSGenImageGradientV(int width, int height, Color top, Color bottom) {
    return GenImageGradientV(width, height, top, bottom);
}

Image JSGenImageGradientH(int width, int height, Color left, Color right) {
    return GenImageGradientH(width, height, left, right);
}

Image JSGenImageGradientRadial(int width, int height, float density, Color inner, Color outer) {
    return GenImageGradientRadial(width, height, density, inner, outer);
}

Image JSGenImageChecked(int width, int height, int checksX, int checksY, Color col1, Color col2) {
    return GenImageChecked(width, height, checksX, checksY, col1, col2);
}

Image JSGenImageWhiteNoise(int width, int height, float factor) {
    return GenImageWhiteNoise(width, height, factor);
}

Image JSGenImagePerlinNoise(int width, int height, int offsetX, int offsetY, float scale) {
    return GenImagePerlinNoise(width, height, offsetX, offsetY, scale);
}

Image JSGenImageCellular(int width, int height, int tileSize) {
    return GenImageCellular(width, height, tileSize);
}

Image JSImageCopy(Image image) {
    return ImageCopy(image);
}

Image JSImageFromImage(Image image, Rectangle rec) {
    return ImageFromImage(image, rec);
}

Image JSImageText(std::string text, int fontSize, Color color) {
    return ImageText(text.c_str(), fontSize, color);
}

Image JSImageTextEx(Font font, std::string text, float fontSize, float spacing, Color tint) {
    return ImageTextEx(font, text.c_str(), fontSize, spacing, tint);
}

void JSImageFormat(Image* image, int newFormat) {
    ImageFormat(image, newFormat);
}

void JSImageToPOT(Image* image, Color fill) {
    ImageToPOT(image, fill);
}

void JSImageCrop(Image* image, Rectangle crop) {
    ImageCrop(image, crop);
}

void JSImageAlphaCrop(Image* image, float threshold) {
    ImageAlphaCrop(image, threshold);
}

void JSImageAlphaClear(Image* image, Color color, float threshold) {
    ImageAlphaClear(image, color, threshold);
}

void JSImageAlphaMask(Image* image, Image alphaMask) {
    ImageAlphaMask(image, alphaMask);
}

void JSImageAlphaPremultiply(Image* image) {
    ImageAlphaPremultiply(image);
}

void JSImageResize(Image* image, int newWidth, int newHeight) {
    ImageResize(image, newWidth, newHeight);
}

void JSImageResizeNN(Image* image, int newWidth, int newHeight) {
    ImageResizeNN(image, newWidth, newHeight);
}

void JSImageResizeCanvas(Image* image, int newWidth, int newHeight, int offsetX, int offsetY, Color fill) {
    ImageResizeCanvas(image, newWidth, newHeight, offsetX, offsetY, fill);
}

void JSImageMipmaps(Image* image) {
    ImageMipmaps(image);
}

void JSImageDither(Image* image, int rBpp, int gBpp, int bBpp, int aBpp) {
    ImageDither(image, rBpp, gBpp, bBpp, aBpp);
}

void JSImageFlipVertical(Image* image) {
    ImageFlipVertical(image);
}

void JSImageFlipHorizontal(Image* image) {
    ImageFlipHorizontal(image);
}

void JSImageRotateCW(Image* image) {
    ImageRotateCW(image);
}

void JSImageRotateCCW(Image* image) {
    ImageRotateCCW(image);
}

void JSImageColorTint(Image* image, Color color) {
    ImageColorTint(image, color);
}

void JSImageColorInvert(Image* image) {
    ImageColorInvert(image);
}

void JSImageColorGrayscale(Image* image) {
    ImageColorGrayscale(image);
}

void JSImageColorContrast(Image* image, float contrast) {
    ImageColorContrast(image, contrast);
}

void JSImageColorBrightness(Image* image, int brightness) {
    ImageColorBrightness(image, brightness);
}

void JSImageColorReplace(Image* image, Color color, Color replace) {
    ImageColorReplace(image, color, replace);
}

std::vector<Color> JSLoadImagePalette(Image image, int maxPaletteSize) {
    auto count = 0;

    auto colors = LoadImagePalette(image, maxPaletteSize, &count);

    auto output = std::vector<Color>();

    for (auto i = 0; i < count; i++) {
        output.push_back(colors[i]);
    }

    return output;
}

Rectangle JSGetImageAlphaBorder(Image image, float threshold) {
    return GetImageAlphaBorder(image, threshold);
}

void JSImageClearBackground(Image* dst, Color color) {
    ImageClearBackground(dst, color);
}

void JSImageDrawPixel(Image* dst, int posX, int posY, Color color) {
    ImageDrawPixel(dst, posX, posY, color);
}

void JSImageDrawPixelV(Image* dst, Vector2 position, Color color) {
    ImageDrawPixelV(dst, position, color);
}

void JSImageDrawLine(Image* dst, int startPosX, int startPosY, int endPosX, int endPosY, Color color) {
    ImageDrawLine(dst, startPosX, startPosY, endPosX, endPosY, color);
}

void JSImageDrawLineV(Image* dst, Vector2 start, Vector2 end, Color color) {
    ImageDrawLineV(dst, start, end, color);
}

void JSImageDrawCircle(Image* dst, int centerX, int centerY, int radius, Color color) {
    ImageDrawCircle(dst, centerX, centerY, radius, color);
}

void JSImageDrawCircleV(Image* dst, Vector2 center, int radius, Color color) {
    ImageDrawCircleV(dst, center, radius, color);
}

void JSImageDrawRectangle(Image* dst, int posX, int posY, int width, int height, Color color) {
    ImageDrawRectangle(dst, posX, posY, width, height, color);
}

void JSImageDrawRectangleV(Image* dst, Vector2 position, Vector2 size, Color color) {
    ImageDrawRectangleV(dst, position, size, color);
}

void JSImageDrawRectangleRec(Image* dst, Rectangle rec, Color color) {
    ImageDrawRectangleRec(dst, rec, color);
}

void JSImageDrawRectangleLines(Image* dst, Rectangle rec, int thick, Color color) {
    ImageDrawRectangleLines(dst, rec, thick, color);
}

void JSImageDraw(Image* dst, Image src, Rectangle srcRec, Rectangle dstRec, Color tint) {
    ImageDraw(dst, src, srcRec, dstRec, tint);
}

void JSImageDrawText(Image* dst, std::string text, int posX, int posY, int fontSize, Color color) {
    ImageDrawText(dst, text.c_str(), posX, posY, fontSize, color);
}

void JSImageDrawTextEx(Image* dst, Font font, std::string text, Vector2 position, float fontSize, float spacing, Color tint) {
    ImageDrawTextEx(dst, font, text.c_str(), position, fontSize, spacing, tint);
}

Texture2D JSLoadTexture(std::string fileName) {
    return LoadTexture(fileName.c_str());
}

Texture2D JSLoadTextureFromImage(Image image) {
    return LoadTextureFromImage(image);
}

TextureCubemap JSLoadTextureCubemap(Image image, int layoutType) {
    return LoadTextureCubemap(image, layoutType);
}

RenderTexture2D JSLoadRenderTexture(int width, int height) {
    return LoadRenderTexture(width, height);
}

void JSUnloadTexture(Texture2D texture) {
    UnloadTexture(texture);
}

void JSUnloadRenderTexture(RenderTexture2D target) {
    UnloadRenderTexture(target);
}

void JSUpdateTexture(Texture2D texture, std::vector<Color> pixels) {
    UpdateTexture(texture, pixels.data());
}

void JSUpdateTextureRec(Texture2D texture, Rectangle rec, std::vector<Color> pixels) {
    UpdateTextureRec(texture, rec, pixels.data());
}

Image JSGetTextureData(Texture2D texture) {
    return GetTextureData(texture);
}

Image JSGetScreenData(void) {
    return GetScreenData();
}

Texture2D JSGenTextureMipmaps(Texture2D texture) {
    GenTextureMipmaps(&texture);

    return texture;
}

void JSSetTextureFilter(Texture2D texture, int filterMode) {
    SetTextureFilter(texture, filterMode);
}

void JSSetTextureWrap(Texture2D texture, int wrapMode) {
    SetTextureWrap(texture, wrapMode);
}

void JSDrawTexture(Texture2D texture, int posX, int posY, Color tint) {
    DrawTexture(texture, posX, posY, tint);
}

void JSDrawTextureV(Texture2D texture, Vector2 position, Color tint) {
    DrawTextureV(texture, position, tint);
}

void JSDrawTextureEx(Texture2D texture, Vector2 position, float rotation, float scale, Color tint) {
    DrawTextureEx(texture, position, rotation, scale, tint);
}

void JSDrawTextureRec(Texture2D texture, Rectangle source, Vector2 position, Color tint) {
    DrawTextureRec(texture, source, position, tint);
}

void JSDrawTextureQuad(Texture2D texture, Vector2 tiling, Vector2 offset, Rectangle quad, Color tint) {
    DrawTextureQuad(texture, tiling, offset, quad, tint);
}

void JSDrawTextureTiled(Texture2D texture, Rectangle source, Rectangle dest, Vector2 origin, float rotation, float scale, Color tint) {
    DrawTextureTiled(texture, source, dest, origin, rotation, scale, tint);
}

void JSDrawTexturePro(Texture2D texture, Rectangle source, Rectangle dest, Vector2 origin, float rotation, Color tint) {
    DrawTexturePro(texture, source, dest, origin, rotation, tint);
}

void JSDrawTextureNPatch(Texture2D texture, NPatchInfo nPatchInfo, Rectangle dest, Vector2 origin, float rotation, Color tint) {
    DrawTextureNPatch(texture, nPatchInfo, dest, origin, rotation, tint);
}

Color JSFade(Color color, float alpha) {
    return Fade(color, alpha);
}

int JSColorToInt(Color color) {
    return ColorToInt(color);
}

Vector4 JSColorNormalize(Color color) {
    return ColorNormalize(color);
}

Color JSColorFromNormalized(Vector4 normalized) {
    return ColorFromNormalized(normalized);
}

Vector3 JSColorToHSV(Color color) {
    return ColorToHSV(color);
}

Color JSColorFromHSV(float hue, float saturation, float value) {
    return ColorFromHSV(hue, saturation, value);
}

Color JSColorAlpha(Color color, float alpha) {
    return ColorAlpha(color, alpha);
}

Color JSColorAlphaBlend(Color dst, Color src, Color tint) {
    return ColorAlphaBlend(dst, src, tint);
}

Color JSGetColor(int hexValue) {
    return GetColor(hexValue);
}

EMSCRIPTEN_BINDINGS(raylibWebTextures) {
    // Image loading functions
    // NOTE: This functions do not require GPU access
    emscripten::function("LoadImage", &JSLoadImage);
    emscripten::function("LoadImageRaw", &JSLoadImageRaw);
    emscripten::function("LoadImageAnim", &JSLoadImageAnim);
    emscripten::function("LoadImageFromMemory", &JSLoadImageFromMemory);
    emscripten::function("UnloadImage", &JSUnloadImage);
    //emscripten::function("ExportImage", &ExportImage);
    //emscripten::function("ExportImageAsCode", &ExportImageAsCode);

    // Image generation functions
    emscripten::function("GenImageColor", &JSGenImageColor);
    emscripten::function("GenImageGradientV", &JSGenImageGradientV);
    emscripten::function("GenImageGradientH", &JSGenImageGradientH);
    emscripten::function("GenImageGradientRadial", &JSGenImageGradientRadial);
    emscripten::function("GenImageChecked", &JSGenImageChecked);
    emscripten::function("GenImageWhiteNoise", &JSGenImageWhiteNoise);
    emscripten::function("GenImagePerlinNoise", &JSGenImagePerlinNoise);
    emscripten::function("GenImageCellular", &JSGenImageCellular);

    // Image manipulation functions
    emscripten::function("ImageCopy", &ImageCopy);
    emscripten::function("ImageFromImage", &ImageFromImage);
    emscripten::function("ImageText", &JSImageText);
    emscripten::function("ImageTextEx", &JSImageTextEx);
    emscripten::function("ImageFormat", &JSImageFormat, emscripten::allow_raw_pointer<Image>());
    emscripten::function("ImageToPOT", &JSImageToPOT, emscripten::allow_raw_pointer<Image>());
    emscripten::function("ImageCrop", &JSImageCrop, emscripten::allow_raw_pointer<Image>());
    emscripten::function("ImageAlphaCrop", &JSImageAlphaCrop, emscripten::allow_raw_pointer<Image>());
    emscripten::function("ImageAlphaClear", &JSImageAlphaClear, emscripten::allow_raw_pointer<Image>());
    emscripten::function("ImageAlphaMask", &JSImageAlphaMask, emscripten::allow_raw_pointer<Image>());
    emscripten::function("ImageAlphaPremultiply", &JSImageAlphaPremultiply, emscripten::allow_raw_pointer<Image>());
    emscripten::function("ImageResize", &JSImageResize, emscripten::allow_raw_pointer<Image>());
    emscripten::function("ImageResizeNN", &JSImageResizeNN, emscripten::allow_raw_pointer<Image>());
    emscripten::function("ImageResizeCanvas", &JSImageResizeCanvas, emscripten::allow_raw_pointer<Image>());
    emscripten::function("ImageMipmaps", &JSImageMipmaps, emscripten::allow_raw_pointer<Image>());
    emscripten::function("ImageDither", &JSImageDither, emscripten::allow_raw_pointer<Image>());
    emscripten::function("ImageFlipVertical", &JSImageFlipVertical, emscripten::allow_raw_pointer<Image>());
    emscripten::function("ImageFlipHorizontal", &JSImageFlipHorizontal, emscripten::allow_raw_pointer<Image>());
    emscripten::function("ImageRotateCW", &JSImageRotateCW, emscripten::allow_raw_pointer<Image>());
    emscripten::function("ImageRotateCCW", &JSImageRotateCCW, emscripten::allow_raw_pointer<Image>());
    emscripten::function("ImageColorTint", &JSImageColorTint, emscripten::allow_raw_pointer<Image>());
    emscripten::function("ImageColorInvert", &JSImageColorInvert, emscripten::allow_raw_pointer<Image>());
    emscripten::function("ImageColorGrayscale", &JSImageColorGrayscale, emscripten::allow_raw_pointer<Image>());
    emscripten::function("ImageColorContrast", &JSImageColorContrast, emscripten::allow_raw_pointer<Image>());
    emscripten::function("ImageColorBrightness", &JSImageColorBrightness, emscripten::allow_raw_pointer<Image>());
    emscripten::function("ImageColorReplace", &JSImageColorReplace, emscripten::allow_raw_pointer<Image>());
    //emscripten::function("LoadImageColors", &LoadImageColors);
    emscripten::function("LoadImagePalette", &JSLoadImagePalette);
    //emscripten::function("UnloadImageColors", &UnloadImageColors);
    //emscripten::function("UnloadImagePalette", &UnloadImagePalette);
    emscripten::function("GetImageAlphaBorder", &JSGetImageAlphaBorder);

    // Image drawing functions
    // NOTE: Image software-rendering functions (CPU)
    emscripten::function("ImageClearBackground", &ImageClearBackground, emscripten::allow_raw_pointer<Image>());
    emscripten::function("ImageDrawPixel", &ImageDrawPixel, emscripten::allow_raw_pointer<Image>());
    emscripten::function("ImageDrawPixelV", &ImageDrawPixelV, emscripten::allow_raw_pointer<Image>());
    emscripten::function("ImageDrawLine", &ImageDrawLine, emscripten::allow_raw_pointer<Image>());
    emscripten::function("ImageDrawLineV", &ImageDrawLineV, emscripten::allow_raw_pointer<Image>());
    emscripten::function("ImageDrawCircle", &ImageDrawCircle, emscripten::allow_raw_pointer<Image>());
    emscripten::function("ImageDrawCircleV", &ImageDrawCircleV, emscripten::allow_raw_pointer<Image>());
    emscripten::function("ImageDrawRectangle", &ImageDrawRectangle, emscripten::allow_raw_pointer<Image>());
    emscripten::function("ImageDrawRectangleV", &ImageDrawRectangleV, emscripten::allow_raw_pointer<Image>());
    emscripten::function("ImageDrawRectangleRec", &ImageDrawRectangleRec, emscripten::allow_raw_pointer<Image>());
    emscripten::function("ImageDrawRectangleLines", &ImageDrawRectangleLines, emscripten::allow_raw_pointer<Image>());
    emscripten::function("ImageDraw", &ImageDraw, emscripten::allow_raw_pointer<Image>());
    emscripten::function("ImageDrawText", &ImageDrawText, emscripten::allow_raw_pointer<Image>());
    emscripten::function("ImageDrawTextEx", &ImageDrawTextEx, emscripten::allow_raw_pointer<Image>());

    // Texture loading functions
    // NOTE: These functions require GPU access
    emscripten::function("LoadTexture", &JSLoadTexture);
    emscripten::function("LoadTextureFromImage", &JSLoadTextureFromImage);
    emscripten::function("LoadTextureCubemap", &JSLoadTextureCubemap);
    emscripten::function("LoadRenderTexture", &JSLoadRenderTexture);
    emscripten::function("UnloadTexture", &JSUnloadTexture);
    emscripten::function("UnloadRenderTexture", &JSUnloadRenderTexture);
    emscripten::function("UpdateTexture", &JSUpdateTexture);
    emscripten::function("UpdateTextureRec", &JSUpdateTextureRec);
    emscripten::function("GetTextureData", &JSGetTextureData);
    emscripten::function("GetScreenData", &GetScreenData);

    // Texture configuration functions
    emscripten::function("GenTextureMipmaps", &JSGenTextureMipmaps);
    emscripten::function("SetTextureFilter", &JSSetTextureFilter);
    emscripten::function("SetTextureWrap", &JSSetTextureWrap);

    // Texture drawing functions
    emscripten::function("DrawTexture", &JSDrawTexture);
    emscripten::function("DrawTextureV", &JSDrawTextureV);
    emscripten::function("DrawTextureEx", &JSDrawTextureEx);
    emscripten::function("DrawTextureRec", &JSDrawTextureRec);
    emscripten::function("DrawTextureQuad", &JSDrawTextureQuad);
    emscripten::function("DrawTextureTiled", &DrawTextureTiled);
    emscripten::function("DrawTexturePro", &JSDrawTexturePro);
    emscripten::function("DrawTextureNPatch", &JSDrawTextureNPatch);

    // Color/pixel related functions
    emscripten::function("Fade", &JSFade);
    emscripten::function("ColorToInt", &JSColorToInt);
    emscripten::function("ColorNormalize", &JSColorNormalize);
    emscripten::function("ColorFromNormalized", &JSColorFromNormalized);
    emscripten::function("ColorToHSV", &JSColorToHSV);
    emscripten::function("ColorAlpha", &JSColorAlpha);
    emscripten::function("ColorAlphaBlend", &JSColorAlphaBlend);
    emscripten::function("GetColor", &JSGetColor);
    //emscripten::function("GetPixelColor", &GetPixelColor);
    //emscripten::function("SetPixelColor", &SetPixelColor);
    //emscripten::function("GetPixelDataSize", &GetPixelDataSize);
}
