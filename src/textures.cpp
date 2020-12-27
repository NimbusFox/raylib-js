#include <emscripten/bind.h>
#include <emscripten/emscripten.h>
#include <raylib.h>

#include "JSAnimImage.h"
#include "JSImage.h"
#include "database/FontDatabase.h"
#include "database/ImageDatabase.h"

// Bindings up to date with raylib 3.5
// https://www.raylib.com/cheatsheet/cheatsheet.html

JSImage JSLoadImage(std::string fileName) {
    return ImageDatabase::AddImage(LoadImage(fileName.c_str()));
}

JSImage JSLoadImageRaw(std::string fileName, int width, int height, int format, int headerSize) {
    return ImageDatabase::AddImage(LoadImageRaw(fileName.c_str(), width, height, format, headerSize));
}

JSAnimImage JSLoadImageAnim(std::string fileName) {
    auto val = JSAnimImage();

    val.image = ImageDatabase::AddImage(LoadImageAnim(fileName.c_str(), &val.frames));

    return val;
}

JSImage JSLoadImageFromMemory(std::string fileType, std::vector<unsigned char> fileData) {
    return ImageDatabase::AddImage(LoadImageFromMemory(fileType.c_str(), fileData.data(), fileData.size()));
}

void JSUnloadImage(Image image) {
    UnloadImage(image);
}

JSImage JSGenImageColor(int width, int height, Color color) {
    return ImageDatabase::AddImage(GenImageColor(width, height, color));
}

JSImage JSGenImageGradientV(int width, int height, Color top, Color bottom) {
    return ImageDatabase::AddImage(GenImageGradientV(width, height, top, bottom));
}

JSImage JSGenImageGradientH(int width, int height, Color left, Color right) {
    return ImageDatabase::AddImage(GenImageGradientH(width, height, left, right));
}

JSImage JSGenImageGradientRadial(int width, int height, float density, Color inner, Color outer) {
    return ImageDatabase::AddImage(GenImageGradientRadial(width, height, density, inner, outer));
}

JSImage JSGenImageChecked(int width, int height, int checksX, int checksY, Color col1, Color col2) {
    return ImageDatabase::AddImage(GenImageChecked(width, height, checksX, checksY, col1, col2));
}

JSImage JSGenImageWhiteNoise(int width, int height, float factor) {
    return ImageDatabase::AddImage(GenImageWhiteNoise(width, height, factor));
}

JSImage JSGenImagePerlinNoise(int width, int height, int offsetX, int offsetY, float scale) {
    return ImageDatabase::AddImage(GenImagePerlinNoise(width, height, offsetX, offsetY, scale));
}

JSImage JSGenImageCellular(int width, int height, int tileSize) {
    return ImageDatabase::AddImage(GenImageCellular(width, height, tileSize));
}

JSImage JSImageCopy(JSImage image) {
    return ImageDatabase::AddImage(ImageCopy(*ImageDatabase::GetImage(image)));
}

JSImage JSImageFromImage(JSImage image, Rectangle rec) {
    return ImageDatabase::AddImage(ImageFromImage(*ImageDatabase::GetImage(image), rec));
}

JSImage JSImageText(std::string text, int fontSize, Color color) {
    return ImageDatabase::AddImage(ImageText(text.c_str(), fontSize, color));
}

JSImage JSImageTextEx(JSFont font, std::string text, float fontSize, float spacing, Color tint) {
    return ImageDatabase::AddImage(ImageTextEx(FontDatabase::GetFont(font), text.c_str(), fontSize, spacing, tint));
}

JSImage JSImageFormat(JSImage image, int newFormat) {
    ImageFormat(ImageDatabase::GetImage(image), newFormat);

    image.format = newFormat;

    return image;
}

void JSImageToPOT(JSImage image, Color fill) {
    ImageToPOT(ImageDatabase::GetImage(image), fill);
}

JSImage JSImageCrop(JSImage image, Rectangle crop) {
    ImageCrop(ImageDatabase::GetImage(image), crop);

    image.height = crop.height - crop.y;
    image.width = crop.width - crop.x;

    return image;
}

void JSImageAlphaCrop(JSImage image, float threshold) {
    ImageAlphaCrop(ImageDatabase::GetImage(image), threshold);
}

void JSImageAlphaClear(JSImage image, Color color, float threshold) {
    ImageAlphaClear(ImageDatabase::GetImage(image), color, threshold);
}

void JSImageAlphaMask(JSImage image, JSImage alphaMask) {
    ImageAlphaMask(ImageDatabase::GetImage(image), *ImageDatabase::GetImage(alphaMask));
}

void JSImageAlphaPremultiply(JSImage image) {
    ImageAlphaPremultiply(ImageDatabase::GetImage(image));
}

JSImage JSImageResize(JSImage image, int newWidth, int newHeight) {
    ImageResize(ImageDatabase::GetImage(image), newWidth, newHeight);

    image.width = newWidth;
    image.height = newHeight;

    return image;
}

JSImage JSImageResizeNN(JSImage image, int newWidth, int newHeight) {
    ImageResizeNN(ImageDatabase::GetImage(image), newWidth, newHeight);

    image.width = newWidth;
    image.height = newHeight;

    return image;
}

JSImage JSImageResizeCanvas(JSImage image, int newWidth, int newHeight, int offsetX, int offsetY, Color fill) {
    ImageResizeCanvas(ImageDatabase::GetImage(image), newWidth, newHeight, offsetX, offsetY, fill);

    image.width = newWidth;
    image.height = newHeight;

    return image;
}

void JSImageMipmaps(JSImage image) {
    ImageMipmaps(ImageDatabase::GetImage(image));
}

void JSImageDither(JSImage image, int rBpp, int gBpp, int bBpp, int aBpp) {
    ImageDither(ImageDatabase::GetImage(image), rBpp, gBpp, bBpp, aBpp);
}

void JSImageFlipVertical(JSImage image) {
    ImageFlipVertical(ImageDatabase::GetImage(image));
}

void JSImageFlipHorizontal(JSImage image) {
    ImageFlipHorizontal(ImageDatabase::GetImage(image));
}

void JSImageRotateCW(JSImage image) {
    ImageRotateCW(ImageDatabase::GetImage(image));
}

void JSImageRotateCCW(JSImage image) {
    ImageRotateCCW(ImageDatabase::GetImage(image));
}

void JSImageColorTint(JSImage image, Color color) {
    ImageColorTint(ImageDatabase::GetImage(image), color);
}

void JSImageColorInvert(JSImage image) {
    ImageColorInvert(ImageDatabase::GetImage(image));
}

void JSImageColorGrayscale(JSImage image) {
    ImageColorGrayscale(ImageDatabase::GetImage(image));
}

void JSImageColorContrast(JSImage image, float contrast) {
    ImageColorContrast(ImageDatabase::GetImage(image), contrast);
}

void JSImageColorBrightness(JSImage image, int brightness) {
    ImageColorBrightness(ImageDatabase::GetImage(image), brightness);
}

void JSImageColorReplace(JSImage image, Color color, Color replace) {
    ImageColorReplace(ImageDatabase::GetImage(image), color, replace);
}

std::vector<Color> JSLoadImagePalette(JSImage image, int maxPaletteSize) {
    auto count = 0;

    auto colors = LoadImagePalette(*ImageDatabase::GetImage(image), maxPaletteSize, &count);

    auto output = std::vector<Color>();

    for (auto i = 0; i < count; i++) {
        output.push_back(colors[i]);
    }

    return output;
}

Rectangle JSGetImageAlphaBorder(JSImage image, float threshold) {
    return GetImageAlphaBorder(*ImageDatabase::GetImage(image), threshold);
}

void JSImageClearBackground(JSImage dst, Color color) {
    ImageClearBackground(ImageDatabase::GetImage(dst), color);
}

void JSImageDrawPixel(JSImage dst, int posX, int posY, Color color) {
    ImageDrawPixel(ImageDatabase::GetImage(dst), posX, posY, color);
}

void JSImageDrawPixelV(JSImage dst, Vector2 position, Color color) {
    ImageDrawPixelV(ImageDatabase::GetImage(dst), position, color);
}

void JSImageDrawLine(JSImage dst, int startPosX, int startPosY, int endPosX, int endPosY, Color color) {
    ImageDrawLine(ImageDatabase::GetImage(dst), startPosX, startPosY, endPosX, endPosY, color);
}

void JSImageDrawLineV(JSImage dst, Vector2 start, Vector2 end, Color color) {
    ImageDrawLineV(ImageDatabase::GetImage(dst), start, end, color);
}

void JSImageDrawCircle(JSImage dst, int centerX, int centerY, int radius, Color color) {
    ImageDrawCircle(ImageDatabase::GetImage(dst), centerX, centerY, radius, color);
}

void JSImageDrawCircleV(JSImage dst, Vector2 center, int radius, Color color) {
    ImageDrawCircleV(ImageDatabase::GetImage(dst), center, radius, color);
}

void JSImageDrawRectangle(JSImage dst, int posX, int posY, int width, int height, Color color) {
    ImageDrawRectangle(ImageDatabase::GetImage(dst), posX, posY, width, height, color);
}

void JSImageDrawRectangleV(JSImage dst, Vector2 position, Vector2 size, Color color) {
    ImageDrawRectangleV(ImageDatabase::GetImage(dst), position, size, color);
}

void JSImageDrawRectangleRec(JSImage dst, Rectangle rec, Color color) {
    ImageDrawRectangleRec(ImageDatabase::GetImage(dst), rec, color);
}

void JSImageDrawRectangleLines(JSImage dst, Rectangle rec, int thick, Color color) {
    ImageDrawRectangleLines(ImageDatabase::GetImage(dst), rec, thick, color);
}

void JSImageDraw(JSImage dst, JSImage src, Rectangle srcRec, Rectangle dstRec, Color tint) {
    ImageDraw(ImageDatabase::GetImage(dst), *ImageDatabase::GetImage(src), srcRec, dstRec, tint);
}

void JSImageDrawText(JSImage dst, std::string text, int posX, int posY, int fontSize, Color color) {
    ImageDrawText(ImageDatabase::GetImage(dst), text.c_str(), posX, posY, fontSize, color);
}

void JSImageDrawTextEx(JSImage dst, JSFont font, std::string text, Vector2 position, float fontSize, float spacing, Color tint) {
    ImageDrawTextEx(ImageDatabase::GetImage(dst), FontDatabase::GetFont(font), text.c_str(), position, fontSize, spacing, tint);
}

Texture2D JSLoadTexture(std::string fileName) {
    return LoadTexture(fileName.c_str());
}

Texture2D JSLoadTextureFromImage(JSImage image) {
    return LoadTextureFromImage(*ImageDatabase::GetImage(image));
}

TextureCubemap JSLoadTextureCubemap(JSImage image, int layoutType) {
    return LoadTextureCubemap(*ImageDatabase::GetImage(image), layoutType);
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

JSImage JSGetTextureData(Texture2D texture) {
    return ImageDatabase::AddImage(GetTextureData(texture));
}

JSImage JSGetScreenData(void) {
    return ImageDatabase::AddImage(GetScreenData());
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
    emscripten::function("ImageCopy", &JSImageCopy);
    emscripten::function("ImageFromImage", &JSImageFromImage);
    emscripten::function("ImageText", &JSImageText);
    emscripten::function("ImageTextEx", &JSImageTextEx);
    emscripten::function("ImageFormat", &JSImageFormat);
    emscripten::function("ImageToPOT", &JSImageToPOT);
    emscripten::function("ImageCrop", &JSImageCrop);
    emscripten::function("ImageAlphaCrop", &JSImageAlphaCrop);
    emscripten::function("ImageAlphaClear", &JSImageAlphaClear);
    emscripten::function("ImageAlphaMask", &JSImageAlphaMask);
    emscripten::function("ImageAlphaPremultiply", &JSImageAlphaPremultiply);
    emscripten::function("ImageResize", &JSImageResize);
    emscripten::function("ImageResizeNN", &JSImageResizeNN);
    emscripten::function("ImageResizeCanvas", &JSImageResizeCanvas);
    emscripten::function("ImageMipmaps", &JSImageMipmaps);
    emscripten::function("ImageDither", &JSImageDither);
    emscripten::function("ImageFlipVertical", &JSImageFlipVertical);
    emscripten::function("ImageFlipHorizontal", &JSImageFlipHorizontal);
    emscripten::function("ImageRotateCW", &JSImageRotateCW);
    emscripten::function("ImageRotateCCW", &JSImageRotateCCW);
    emscripten::function("ImageColorTint", &JSImageColorTint);
    emscripten::function("ImageColorInvert", &JSImageColorInvert);
    emscripten::function("ImageColorGrayscale", &JSImageColorGrayscale);
    emscripten::function("ImageColorContrast", &JSImageColorContrast);
    emscripten::function("ImageColorBrightness", &JSImageColorBrightness);
    emscripten::function("ImageColorReplace", &JSImageColorReplace);
    //emscripten::function("LoadImageColors", &LoadImageColors);
    emscripten::function("LoadImagePalette", &JSLoadImagePalette);
    //emscripten::function("UnloadImageColors", &UnloadImageColors);
    //emscripten::function("UnloadImagePalette", &UnloadImagePalette);
    emscripten::function("GetImageAlphaBorder", &JSGetImageAlphaBorder);

    // Image drawing functions
    // NOTE: Image software-rendering functions (CPU)
    emscripten::function("ImageClearBackground", &JSImageClearBackground);
    emscripten::function("ImageDrawPixel", &JSImageDrawPixel);
    emscripten::function("ImageDrawPixelV", &JSImageDrawPixelV);
    emscripten::function("ImageDrawLine", &JSImageDrawLine);
    emscripten::function("ImageDrawLineV", &JSImageDrawLineV);
    emscripten::function("ImageDrawCircle", &JSImageDrawCircle);
    emscripten::function("ImageDrawCircleV", &JSImageDrawCircleV);
    emscripten::function("ImageDrawRectangle", &JSImageDrawRectangle);
    emscripten::function("ImageDrawRectangleV", &JSImageDrawRectangleV);
    emscripten::function("ImageDrawRectangleRec", &JSImageDrawRectangleRec);
    emscripten::function("ImageDrawRectangleLines", &JSImageDrawRectangleLines);
    emscripten::function("ImageDraw", &JSImageDraw);
    emscripten::function("ImageDrawText", &JSImageDrawText);
    emscripten::function("ImageDrawTextEx", &JSImageDrawTextEx);

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
