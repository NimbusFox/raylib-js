#include <emscripten/bind.h>
#include <emscripten/emscripten.h>
#include <raylib.h>

// Bindings up to date with raylib 3.5
// https://www.raylib.com/cheatsheet/cheatsheet.html

void JSDrawPixel(int posX, int posY, Color color) {
    DrawPixel(posX, posY, color);
}

void JSDrawPixelV(Vector2 position, Color color) {
    DrawPixelV(position, color);
}

void JSDrawLine(int startPosX, int startPosY, int endPosX, int endPosY, Color color) {
    DrawLine(startPosX, startPosY, endPosX, endPosY, color);
}

void JSDrawLineV(Vector2 startPos, Vector2 endPos, Color color) {
    DrawLineV(startPos, endPos, color);
}

void JSDrawLineEx(Vector2 startPos, Vector2 endPos, float thick, Color color) {
    DrawLineEx(startPos, endPos, thick, color);
}

void JSDrawLineBezier(Vector2 startPos, Vector2 endPos, float thick, Color color) {
    DrawLineBezier(startPos, endPos, thick, color);
}

void JSDrawLineStrip(std::vector<Vector2> points, Color color) {
    DrawLineStrip(points.data(), points.size(), color);
}
void JSDrawCircle(int centerX, int centerY, float radius, Color color) {
    DrawCircle(centerX, centerY, radius, color);
}

void JSDrawCircleSector(Vector2 center, float radius, int startAngle, int endAngle, int segments, Color color) {
    DrawCircleSector(center, radius, startAngle, endAngle, segments, color);
}

void JSDrawCircleSectorLines(Vector2 center, float radius, int startAngle, int endAngle, int segments, Color color) {
    DrawCircleSectorLines(center, radius, startAngle, endAngle, segments, color);
}

void JSDrawCircleGradient(int centerX, int centerY, float radius, Color color1, Color color2) {
    DrawCircleGradient(centerX, centerY, radius, color1, color2);
}

void JSDrawCircleV(Vector2 center, float radius, Color color) {
    DrawCircleV(center, radius, color);
}

void JSDrawCircleLines(int centerX, int centerY, float radius, Color color) {
    DrawCircleLines(centerX, centerY, radius, color);
}

void JSDrawEllipse(int centerX, int centerY, float radiusH, float radiusV, Color color) {
    DrawEllipse(centerX, centerY, radiusH, radiusV, color);
}

void JSDrawEllipseLines(int centerX, int centerY, float radiusH, float radiusV, Color color) {
    DrawEllipseLines(centerX, centerY, radiusH, radiusV, color);
}

void JSDrawRing(Vector2 center, float innerRadius, float outerRadius, int startAngle, int endAngle, int segments, Color color) {
    DrawRing(center, innerRadius, outerRadius, startAngle, endAngle, segments, color);
}

void JSDrawRingLines(Vector2 center, float innerRadius, float outerRadius, int startAngle, int endAngle, int segments, Color color) {
    DrawRingLines(center, innerRadius, outerRadius, startAngle, endAngle, segments, color);
}

void JSDrawRectangle(int posX, int posY, int width, int height, Color color) {
    DrawRectangle(posX, posY, width, height, color);
}

void JSDrawRectangleV(Vector2 position, Vector2 size, Color color) {
    DrawRectangleV(position, size, color);
}

void JSDrawRectangleRec(Rectangle rec, Color color) {
    DrawRectangleRec(rec, color);
}

void JSDrawRectanglePro(Rectangle rec, Vector2 origin, float rotation, Color color) {
    DrawRectanglePro(rec, origin, rotation, color);
}

void JSDrawRectangleGradientV(int posX, int posY, int width, int height, Color color1, Color color2) {
    DrawRectangleGradientV(posX, posY, width, height, color1, color2);
}

void JSDrawRectangleGradientH(int posX, int posY, int width, int height, Color color1, Color color2) {
    DrawRectangleGradientH(posX, posY, width, height, color1, color2);
}

void JSDrawRectangleGradientEx(Rectangle rec, Color col1, Color col2, Color col3, Color col4) {
    DrawRectangleGradientEx(rec, col1, col2, col3, col4);
}

void JSDrawRectangleLines(int posX, int posY, int width, int height, Color color) {
    DrawRectangleLines(posX, posY, width, height, color);
}

void JSDrawRectangleLinesEx(Rectangle rec, int lineThick, Color color) {
    DrawRectangleLinesEx(rec, lineThick, color);
}

void JSDrawRectangleRounded(Rectangle rec, float roundness, int segments, Color color) {
    DrawRectangleRounded(rec, roundness, segments, color);
}

void JSDrawRectangleRoundedLines(Rectangle rec, float roundness, int segments, int lineThick, Color color) {
    DrawRectangleRoundedLines(rec, roundness, segments, lineThick, color);
}

void JSDrawTriangle(Vector2 v1, Vector2 v2, Vector2 v3, Color color) {
    DrawTriangle(v1, v2, v3, color);
}

void JSDrawTriangleLines(Vector2 v1, Vector2 v2, Vector2 v3, Color color) {
    DrawTriangleLines(v1, v2, v3, color);
}

void JSDrawTriangleFan(std::vector<Vector2> points, Color color) {
    DrawTriangleFan(points.data(), points.size(), color);
}

void JSDrawTriangleStrip(std::vector<Vector2> points, Color color) {
    DrawTriangleStrip(points.data(), points.size(), color);
}

void JSDrawPoly(Vector2 center, int sides, float radius, float rotation, Color color) {
    DrawPoly(center, sides, radius, rotation, color);
}

void JSDrawPolyLines(Vector2 center, int sides, float radius, float rotation, Color color) {
    DrawPolyLines(center, sides, radius, rotation, color);
}

bool JSCheckCollisionRecs(Rectangle rec1, Rectangle rec2) {
    return CheckCollisionRecs(rec1, rec2);
}

bool JSCheckCollisionCircles(Vector2 center1, float radius1, Vector2 center2, float radius2) {
    return CheckCollisionCircles(center1, radius1, center2, radius2);
}

bool JSCheckCollisionCircleRec(Vector2 center, float radius, Rectangle rec) {
    return CheckCollisionCircleRec(center, radius, rec);
}

bool JSCheckCollisionPointRec(Vector2 point, Rectangle rec) {
    return CheckCollisionPointRec(point, rec);
}

bool JSCheckCollisionPointCircle(Vector2 point, Vector2 center, float radius) {
    return CheckCollisionPointCircle(point, center, radius);
}

bool JSCheckCollisionPointTriangle(Vector2 point, Vector2 p1, Vector2 p2, Vector2 p3) {
    return CheckCollisionPointTriangle(point, p1, p2, p3);
}

emscripten::val JSCheckCollisionLines(Vector2 startPos1, Vector2 endPos1, Vector2 startPos2, Vector2 endPos2) {
    Vector2 collisionPoint;
    if (!CheckCollisionLines(startPos1, endPos1, startPos2, endPos2, &collisionPoint)) {
        return emscripten::val(false);
    }

    return emscripten::val(collisionPoint);
}

Rectangle JSGetCollisionRec(Rectangle rec1, Rectangle rec2) {
    return GetCollisionRec(rec1, rec2);
}

EMSCRIPTEN_BINDINGS(raylibWebShapes) {
    // Basic shapes drawing functions
    emscripten::function("DrawPixel", &JSDrawPixel);
    emscripten::function("DrawPixelV", &JSDrawPixelV);
    emscripten::function("DrawLine", &JSDrawLine);
    emscripten::function("DrawLineV", &JSDrawLineV);
    emscripten::function("DrawLineEx", &JSDrawLineEx);
    emscripten::function("DrawLineBezier", &JSDrawLineBezier);
    emscripten::function("DrawLineStrip", &JSDrawLineStrip);
    emscripten::function("DrawCircle", &JSDrawCircle);
    emscripten::function("DrawCircleSector", &JSDrawCircleSector);
    emscripten::function("DrawCircleSectorLines", &JSDrawCircleSectorLines);
    emscripten::function("DrawCircleGradient", &JSDrawCircleGradient);
    emscripten::function("DrawCircleV", &JSDrawCircleV);
    emscripten::function("DrawCircleLines", &JSDrawCircleLines);
    emscripten::function("DrawElllipse", &JSDrawEllipse);
    emscripten::function("DrawEllipseLines", &JSDrawEllipseLines);
    emscripten::function("DrawRing", &JSDrawRing);
    emscripten::function("DrawRingLines", &JSDrawRingLines);
    emscripten::function("DrawRectangle", &JSDrawRectangle);
    emscripten::function("DrawRectangleV", &JSDrawRectangleV);
    emscripten::function("DrawRectangleRec", &JSDrawRectangleRec);
    emscripten::function("DrawRectanglePro", &JSDrawRectanglePro);
    emscripten::function("DrawRectangleGradientV", &JSDrawRectangleGradientV);
    emscripten::function("DrawRectangleGradientH", &JSDrawRectangleGradientH);
    emscripten::function("DrawRectangleGradientEx", &JSDrawRectangleGradientEx);
    emscripten::function("DrawRectangleLines", &JSDrawRectangleLines);
    emscripten::function("DrawRectangleLinesEx", &JSDrawRectangleLinesEx);
    emscripten::function("DrawRectangleRounded", &JSDrawRectangleRounded);
    emscripten::function("DrawRectangleRoundedLines", &JSDrawRectangleRoundedLines);
    emscripten::function("DrawTriangle", &JSDrawTriangle);
    emscripten::function("DrawTriangleLines", &JSDrawTriangleLines);
    emscripten::function("DrawTriangleFan", &JSDrawTriangleFan);
    emscripten::function("DrawTriangleStrip", &JSDrawTriangleStrip);
    emscripten::function("DrawPoly", &JSDrawPoly);
    emscripten::function("DrawPolyLines", &JSDrawPolyLines);
    
    // Basic shapes collision detection functions
    emscripten::function("CheckCollisionRecs", &JSCheckCollisionRecs);
    emscripten::function("CheckCollisionCircles", &JSCheckCollisionCircles);
    emscripten::function("CheckCollisionCircleRec", &JSCheckCollisionCircleRec);
    emscripten::function("CheckCollisionPointRec", &JSCheckCollisionPointRec);
    emscripten::function("CheckCollisionPointCircle", &JSCheckCollisionPointCircle);
    emscripten::function("CheckCollisionPointTriangle", &JSCheckCollisionPointTriangle);
    emscripten::function("CheckCollisionLines", &JSCheckCollisionLines);
    emscripten::function("GetCollisionRec", &JSGetCollisionRec);
}
