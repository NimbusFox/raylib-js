#include <emscripten/bind.h>
#include <raylib.h>
#include "JSFont.h"
#include "JSImage.h"
#include "JSAnimImage.h"

// Bindings up to date with raylib 3.5
// https://www.raylib.com/cheatsheet/cheatsheet.html

EMSCRIPTEN_BINDINGS(raylibWebStructs) {
    emscripten::value_object<Color>("Color")
        .field("r", &Color::r)
        .field("g", &Color::g)
        .field("b", &Color::b)
        .field("a", &Color::a);

    emscripten::value_object<Vector2>("Vector2")
        .field("x", &Vector2::x)
        .field("y", &Vector2::y);

    emscripten::value_object<Vector3>("Vector3")
        .field("x", &Vector3::x)
        .field("y", &Vector3::y)
        .field("z", &Vector3::z);

    emscripten::value_object<Camera2D>("Camera2D")
        .field("offset", &Camera2D::offset)
        .field("target", &Camera2D::target)
        .field("rotation", &Camera2D::rotation)
        .field("zoom", &Camera2D::zoom);

    emscripten::value_object<Camera3D>("Camera3D")
        .field("positon", &Camera3D::position)
        .field("target", &Camera3D::target)
        .field("up", &Camera3D::up)
        .field("fovy", &Camera3D::fovy)
        .field("type", &Camera3D::type);

    emscripten::value_object<Texture2D>("Texture2D")
        .field("id", &Texture2D::id)
        .field("width", &Texture2D::width)
        .field("height", &Texture2D::height)
        .field("mipmaps", &Texture2D::mipmaps)
        .field("format", &Texture2D::format);

    emscripten::value_object<RenderTexture2D>("RenderTexture2D")
        .field("id", &RenderTexture2D::id)
        .field("texture", &RenderTexture2D::texture)
        .field("depth", &RenderTexture2D::texture);

    emscripten::value_object<Ray>("Ray")
        .field("position", &Ray::position)
        .field("direction", &Ray::direction);

    emscripten::value_object<Matrix>("Matrix")
        .field("m0", &Matrix::m0) .field("m4", &Matrix::m4) .field("m8", &Matrix::m8) .field("m12", &Matrix::m12)
        .field("m1", &Matrix::m1) .field("m5", &Matrix::m5) .field("m9", &Matrix::m9) .field("m13", &Matrix::m13)
        .field("m2", &Matrix::m2) .field("m6", &Matrix::m6) .field("m10", &Matrix::m10) .field("m14", &Matrix::m14)
        .field("m3", &Matrix::m3) .field("m7", &Matrix::m7) .field("m11", &Matrix::m11) .field("m15", &Matrix::m15);

    emscripten::value_object<Rectangle>("Rectangle")
        .field("x", &Rectangle::x)
        .field("y", &Rectangle::y)
        .field("width", &Rectangle::width)
        .field("height", &Rectangle::height);

    emscripten::value_object<JSImage>("Image")
        .field("id", &JSImage::id)
        .field("width", &JSImage::width)
        .field("height", &JSImage::height)
        .field("mipmaps", &JSImage::mipmaps)
        .field("format", &JSImage::format);

    emscripten::value_object<JSFont>("Font")
        .field("id", &JSFont::id)
        .field("baseSize", &JSFont::baseSize)
        .field("charsCount", &JSFont::charsCount)
        .field("charsPadding", &JSFont::charsPadding)
        .field("texture", &JSFont::texture);

    emscripten::value_object<JSAnimImage>("AnimImage")
        .field("image", &JSAnimImage::image)
        .field("frames", &JSAnimImage::frames);

    emscripten::value_object<NPatchInfo>("NPatchInfo")
        .field("source", &NPatchInfo::source)
        .field("left", &NPatchInfo::left)
        .field("top", &NPatchInfo::top)
        .field("right", &NPatchInfo::right)
        .field("bottom", &NPatchInfo::bottom)
        .field("type", &NPatchInfo::type);
    
    emscripten::register_vector<unsigned char>("vector<unsigned char>");
    emscripten::register_vector<Vector2>("vector<Vector2>");
    emscripten::register_vector<Vector3>("vector<Vector3>");
    emscripten::register_vector<Vector4>("vector<Vector4>");
    emscripten::register_vector<Color>("vector<Color>");
}