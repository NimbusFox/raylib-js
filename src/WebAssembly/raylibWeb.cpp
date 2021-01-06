#include <emscripten/bind.h>
#include <emscripten/emscripten.h>
#include <raylib.h>

void Dispose(intptr_t pointer) {
    delete reinterpret_cast<void *>(pointer);
}

intptr_t CreateVector2(float x, float y) {
    return reinterpret_cast<intptr_t>(new Vector2(Vector2{x, y}));
}

void Vector2SetX(intptr_t pointer, float x) {
    reinterpret_cast<Vector2 *>(pointer)->x = x;
}

float Vector2GetX(intptr_t pointer) {
    return reinterpret_cast<Vector2 *>(pointer)->x;
}

void Vector2SetY(intptr_t pointer, float y) {
    reinterpret_cast<Vector2 *>(pointer)->y = y;
}

float Vector2GetY(intptr_t pointer) {
    return reinterpret_cast<Vector2 *>(pointer)->y;
}

intptr_t CreateVector3(float x, float y, float z) {
    return reinterpret_cast<intptr_t>(new Vector3(Vector3{x, y, z}));
}

void Vector3SetX(intptr_t pointer, float x) {
    reinterpret_cast<Vector3 *>(pointer)->x = x;
}

float Vector3GetX(intptr_t pointer) {
    return reinterpret_cast<Vector3 *>(pointer)->x;
}

void Vector3SetY(intptr_t pointer, float y) {
    reinterpret_cast<Vector3 *>(pointer)->y = y;
}

float Vector3GetY(intptr_t pointer) {
    return reinterpret_cast<Vector3 *>(pointer)->y;
}

void Vector3SetZ(intptr_t pointer, float z) {
    reinterpret_cast<Vector3 *>(pointer)->z = z;
}

float Vector3GetZ(intptr_t pointer) {
    return reinterpret_cast<Vector3 *>(pointer)->z;
}

intptr_t CreateCamera3D() {
    auto camera = new Camera3D();

    return reinterpret_cast<intptr_t>(camera);
}

intptr_t GetCamera3DPosition(intptr_t pointer) {
    return reinterpret_cast<intptr_t>(&reinterpret_cast<Camera3D*>(pointer)->position);
}

intptr_t GetCamera3DTarget(intptr_t pointer) {
    return reinterpret_cast<intptr_t>(&reinterpret_cast<Camera3D*>(pointer)->target);
}

intptr_t GetCamera3DUp(intptr_t pointer) {
    return reinterpret_cast<intptr_t>(&reinterpret_cast<Camera3D*>(pointer)->up);
}

float Camera3DGetFovy(intptr_t pointer) {
    return reinterpret_cast<Camera3D *>(pointer)->fovy;
}

void Camera3DSetFovy(intptr_t pointer, float fovy) {
    reinterpret_cast<Camera3D *>(pointer)->fovy = fovy;
}

int Camera3DGetType(intptr_t pointer) {
    return reinterpret_cast<Camera3D *>(pointer)->type;
}

EMSCRIPTEN_BINDINGS(raylibWeb) {
    emscripten::function("Dispose", &Dispose);

    emscripten::function("CreateVector2", &CreateVector2);
    emscripten::function("Vector2SetX", &Vector2SetX);
    emscripten::function("Vector2GetX", &Vector2GetX);
    emscripten::function("Vector2SetY", &Vector2SetY);
    emscripten::function("Vector2GetY", &Vector2GetY);

    emscripten::function("CreateVector3", &CreateVector3);
    emscripten::function("Vector3SetX", &Vector3SetX);
    emscripten::function("Vector3GetX", &Vector3GetX);
    emscripten::function("Vector3SetY", &Vector3SetY);
    emscripten::function("Vector3GetY", &Vector3GetY);
    emscripten::function("Vector3SetZ", &Vector3SetZ);
    emscripten::function("Vector3GetZ", &Vector3GetZ);

    emscripten::function("CreateCamera3D", &CreateCamera3D);
    emscripten::function("GetCamera3DPosition", &GetCamera3DPosition);
    emscripten::function("GetCamera3DTarget", &GetCamera3DTarget);
    emscripten::function("GetCamera3DUp", &GetCamera3DUp);
    emscripten::function("Camera3DGetFovy", &Camera3DGetFovy);
    emscripten::function("Camera3DSetFovy", &Camera3DSetFovy);
    emscripten::function("Camera3DGetType", &Camera3DGetType);
}
