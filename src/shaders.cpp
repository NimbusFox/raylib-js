#include <emscripten/bind.h>
#include <emscripten/emscripten.h>
#include <raylib.h>

// Bindings up to date with raylib 3.5
// https://www.raylib.com/cheatsheet/cheatsheet.html

Shader JSLoadShader(std::string vsFileName, std::string fsFileName) {
    return LoadShader(vsFileName.c_str(), fsFileName.c_str());
}

Shader JSLoadShaderCode(std::string vsCode, std::string fsCode) {
    return LoadShaderCode(vsCode.c_str(), fsCode.c_str());
}

void JSUnloadShader(Shader shader) {
    UnloadShader(shader);
}

Shader JSGetShaderDefault() {
    return GetShaderDefault();
}

Texture2D JSGetTextureDefault() {
    return GetTextureDefault();
}

Texture2D JSGetShapesTexture() {
    return GetShapesTexture();
}

Rectangle JSGetShapesTextureRec() {
    return GetShapesTextureRec();
}

void JSSetShapesTexture(Texture2D texture, Rectangle source) {
    SetShapesTexture(texture, source);
}

int JSGetShaderLocation(Shader shader, std::string uniformName) {
    return GetShaderLocation(shader, uniformName.c_str());
}

int JSGetShaderLocationAttrib(Shader shader, std::string attribName) {
    return GetShaderLocationAttrib(shader, attribName.c_str());
}

void SetShaderValueFloat(Shader shader, int uniformLoc, float value) {
    SetShaderValue(shader, uniformLoc, &value, UNIFORM_FLOAT);
}

void SetShaderValueInt(Shader shader, int uniformLoc, int value) {
    SetShaderValue(shader, uniformLoc, &value, UNIFORM_INT);
}

void SetShaderValueVec2(Shader shader, int uniformLoc, Vector2 value) {
    SetShaderValue(shader, uniformLoc, &value, UNIFORM_VEC2);
}

void SetShaderValueVec3(Shader shader, int uniformLoc, Vector3 value) {
    SetShaderValue(shader, uniformLoc, &value, UNIFORM_VEC3);
}

void SetShaderValueVec4(Shader shader, int uniformLoc, Vector4 value) {
    SetShaderValue(shader, uniformLoc, &value, UNIFORM_VEC4);
}

void SetShaderValueFloatV(Shader shader, int uniformLoc, float value, int count) {
    SetShaderValueV(shader, uniformLoc, &value, UNIFORM_FLOAT, count);
}

void SetShaderValueIntV(Shader shader, int uniformLoc, int value, int count) {
    SetShaderValueV(shader, uniformLoc, &value, UNIFORM_INT, count);
}

void SetShaderValueVec2V(Shader shader, int uniformLoc, Vector2 value, int count) {
    SetShaderValueV(shader, uniformLoc, &value, UNIFORM_VEC2, count);
}

void SetShaderValueVec3V(Shader shader, int uniformLoc, Vector3 value, int count) {
    SetShaderValueV(shader, uniformLoc, &value, UNIFORM_VEC3, count);
}

void SetShaderValueVec4V(Shader shader, int uniformLoc, Vector4 value, int count) {
    SetShaderValueV(shader, uniformLoc, &value, UNIFORM_VEC4, count);
}

void JSSetShaderValueMatrix(Shader shader, int uniformLoc, Matrix mat) {
    SetShaderValueMatrix(shader, uniformLoc, mat);
}

void JSSetShaderValueTexture(Shader shader, int uniformLoc, Texture2D texture) {
    SetShaderValueTexture(shader, uniformLoc, texture);
}

void JSSetMatrixProjection(Matrix proj) {
    SetMatrixProjection(proj);
}

void JSSetMatrixModelview(Matrix view) {
    SetMatrixModelview(view);
}

Matrix JSGetMatrixModelview() {
    return GetMatrixModelview();
}

Matrix JSGetMatrixProjection() {
    return GetMatrixProjection();
}

void JSBeginShaderMode(Shader shader) {
    BeginShaderMode(shader);
}

void JSUpdateVrTracking(Camera *camera) {
    UpdateVrTracking(camera);
}

void JSSetVrConfiguration(VrDeviceInfo info, Shader distortion) {
    SetVrConfiguration(info, distortion);
}

EMSCRIPTEN_BINDINGS(raylibWebShaders) {
    // Shader loading/unloading functions
    emscripten::function("LoadShader", &JSLoadShader);
    emscripten::function("LoadShaderCode", &JSLoadShaderCode);
    emscripten::function("UnloadShader", &JSUnloadShader);

    emscripten::function("GetShaderDefault", &JSGetShaderDefault);
    emscripten::function("GetTextureDefault", &JSGetTextureDefault);
    emscripten::function("GetShapesTexture", &JSGetShapesTexture);
    emscripten::function("GetShapesTextureRec", &JSGetShapesTextureRec);
    emscripten::function("SetShapesTexture", &JSSetShapesTexture);

    // Shader configuration functions
    emscripten::function("GetShaderLocation", &JSGetShaderLocation);
    emscripten::function("GetShaderLocationAttrib", &JSGetShaderLocationAttrib);
    emscripten::function("SetShaderValueFloat", &SetShaderValueFloat);
    emscripten::function("SetShaderValueInt", &SetShaderValueInt);
    emscripten::function("SetShaderValueVec2", &SetShaderValueVec2);
    emscripten::function("SetShaderValueVec3", &SetShaderValueVec3);
    emscripten::function("SetShaderValueVec4", &SetShaderValueVec4);
    ;
    emscripten::function("SetShaderValueFloatV", &SetShaderValueFloatV);
    emscripten::function("SetShaderValueIntV", &SetShaderValueIntV);
    emscripten::function("SetShaderValueVec2V", &SetShaderValueVec2V);
    emscripten::function("SetShaderValueVec3V", &SetShaderValueVec3V);
    emscripten::function("SetShaderValueVec4V", &SetShaderValueVec4V);
    emscripten::function("SetShaderValueMatrix", &JSSetShaderValueMatrix);
    emscripten::function("SetShaderValueTexutre", &JSSetShaderValueTexture);
    emscripten::function("SetMatrixProjection", &JSSetMatrixProjection);
    emscripten::function("SetMatrixModelview", &JSSetMatrixModelview);
    emscripten::function("GetMatrixModelview", &JSGetMatrixModelview);
    emscripten::function("GetMatrixProjection", &JSGetMatrixProjection);

    // Shading begin/end functions
    emscripten::function("BeginShaderMode", &JSBeginShaderMode);
    emscripten::function("EndShaderMode", &EndShaderMode);
    emscripten::function("BeginBlendMode", &BeginBlendMode);
    emscripten::function("EndBlendMode", &EndBlendMode);

    // VR control functions
    emscripten::function("InitVrSimulator", &InitVrSimulator);
    emscripten::function("CloseVrSimulator", &CloseVrSimulator);
    emscripten::function("UpdateVrTracking", &JSUpdateVrTracking, emscripten::allow_raw_pointer<Camera>());
    emscripten::function("SetVrConfiguration", &JSSetVrConfiguration);
    emscripten::function("IsVrSimulatorReady", &IsVrSimulatorReady);
    emscripten::function("ToggleVrMode", &ToggleVrMode);
    emscripten::function("BeginVrDrawing", &BeginVrDrawing);
    emscripten::function("EndVrDrawing", &EndVrDrawing);
}
