#include <emscripten/bind.h>
#include <emscripten/emscripten.h>
#include <raylib.h>

// Bindings up to date with raylib 3.5
// https://www.raylib.com/cheatsheet/cheatsheet.html

void JSClearBackground(Color color) {
    ClearBackground(color);
}

void JSInitWindow(int width, int height) {
    InitWindow(width, height, "");
}

void JSSetClipboardText(std::string text) {
    SetClipboardText(text.c_str());
}

std::string JSGetClipboardText() {
    return GetClipboardText();
}

void JSBeginMode2D(Camera2D camera) {
    BeginMode2D(camera);
}

void JSBeginMode3D(Camera3D camera) {
    BeginMode3D(camera);
}

void JSBeginTextureMode(RenderTexture2D target) {
    BeginTextureMode(target);
}

Ray JSGetMouseRay(Vector2 mousePosition, Camera3D camera) {
    return GetMouseRay(mousePosition, camera);
}

Matrix JSGetCameraMatrix(Camera3D camera) {
    return GetCameraMatrix(camera);
}

Matrix JSGetCameraMatrix2D(Camera2D camera) {
    return GetCameraMatrix2D(camera);
}

Vector2 JSGetWorldToScreen(Vector3 position, Camera3D camera) {
    return GetWorldToScreen(position, camera);
}

Vector2 JSGetWorldToScreenEx(Vector3 position, Camera3D camera, int width, int height) {
    return GetWorldToScreenEx(position, camera, width, height);
}

Vector2 JSGetWorldToScreen2D(Vector2 position, Camera2D camera) {
    return GetWorldToScreen2D(position, camera);
}

Vector2 JSGetScreenToWorld2D(Vector2 position, Camera2D camera) {
    return GetScreenToWorld2D(position, camera);
}

void JSTraceLog(int logType, std::string text) {
    TraceLog(logType, text.c_str());
}

std::vector<unsigned char> JSLoadFileData(std::string fileName) {
    auto count = 0u;
    auto data =  LoadFileData(fileName.c_str(), &count);
    auto output = std::vector<unsigned char>();

    for (unsigned int i = 0; i < count; i++) {
        output.push_back(data[i]);
    }

    return output;
}

std::string JSLoadFileText(std::string fileName) {
    return LoadFileText(fileName.c_str());
}

bool JSFileExists(std::string fileName) {
    return FileExists(fileName.c_str());
}

bool JSDirectoryExists(std::string dirPath) {
    return DirectoryExists(dirPath.c_str());
}

bool JSIsFileExtension(std::string fileName, std::string ext) {
    return IsFileExtension(fileName.c_str(), ext.c_str());
}

std::string JSGetFileExtension(std::string fileName) {
    return GetFileExtension(fileName.c_str());
}

std::string JSGetFileName(std::string filePath) {
    return GetFileName(filePath.c_str());
}

std::string JSGetFileNameWithoutExt(std::string filePath) {
    return GetFileNameWithoutExt(filePath.c_str());
}

std::string JSGetDirectoryPath(std::string dirPath) {
    return GetDirectoryPath(dirPath.c_str());
}

std::string JSGetPrevDirectoryPath(std::string dirPath) {
    return GetPrevDirectoryPath(dirPath.c_str());
}

std::string JSGetWorkingDirectory() {
    return GetWorkingDirectory();
}

std::vector<unsigned char> JSCompressData(std::vector<unsigned char> data) {
    auto output = std::vector<unsigned char>();
    auto count = 0;

    auto cData = CompressData(data.data(), data.size(), &count);

    for (auto i = 0; i < count; i++) {
        output.push_back(cData[i]);
    }

    return output;
}

std::vector<unsigned char> JSDecompressData(std::vector<unsigned char> data) {
    auto output = std::vector<unsigned char>();
    auto count = 0;

    auto dData = DecompressData(data.data(), data.size(), &count);

    for (auto i = 0; i < count; i++) {
        output.push_back(dData[i]);
    }

    return output;
}

bool JSIsGamepadName(int gamepad, std::string name) {
    return IsGamepadName(gamepad, name.c_str());
}

std::string JSGetGamepadName(int gamepad) {
    return GetGamepadName(gamepad);
}

Vector2 JSGetMousePosition() {
    return GetMousePosition();
}

Vector2 JSGetTouchPosition(int index) {
    return GetTouchPosition(index);
}

Vector2 JSGetGestureDragVector() {
    return GetGestureDragVector();
}

Vector2 JSGetGesturePinchVector() {
    return GetGesturePinchVector();
}

void JSSetCameraMode(Camera3D camera, int mode) {
    SetCameraMode(camera, mode);
}

Camera3D JSUpdateCamera(Camera3D camera) {
    auto c = camera;
    UpdateCamera(&c);
    return c;
} 

EMSCRIPTEN_BINDINGS(raylibWebCore) {
    // Window-related functions
    emscripten::function("InitWindow", &JSInitWindow);
    //emscripten::function("WindowShouldClose", &WindowShouldClose);
    //emscripten::function("CloseWindow", &CloseWindow);
    emscripten::function("IsWindowReady", &IsWindowReady);
    emscripten::function("IsWindowFullScreen", &IsWindowFullscreen);
    //emscripten::function("IsWindowHidden", &IsWindowHidden);
    //emscripten::function("IsWindowMinimized", &IsWindowMinimized);
    //emscripten::function("IsWindowMaximized", &IsWindowMaximized);
    emscripten::function("IsWindowFocused", &IsWindowFocused);
    //emscripten::function("IsWindowResized", &IsWindowResized);
    emscripten::function("IsWindowState", &IsWindowState);
    emscripten::function("SetWindowState", &SetWindowState);
    emscripten::function("ClearWindowState", &ClearWindowState);
    emscripten::function("ToggleFullScreen", &ToggleFullscreen);
    //emscripten::function("MaximizeWindow", &MaximizeWindow);
    //emscripten::function("MinimizeWindow", &MinimizeWindow);
    //emscripten::function("RestoreWindow", &RestoreWindow);
    //emscripten::function("SetWindowIcon", &SetWindowIcon);
    //emscripten::function("SetWindowTitle", &SetWindowTitle);
    //emscripten::function("SetWindowPosition", &SetWindowPosition);
    //emscripten::function("SetWindowMonitor", &SetWindowMonitor);
    //emscripten::function("SetWindowMinSize", &SetWindowMinSize);
    emscripten::function("SetWindowSize", &SetWindowSize);
    //emscripten::function("GetWindowHandle", &GetWindowHandle);
    emscripten::function("GetScreenWidth", &GetScreenWidth);
    emscripten::function("GetScreenHeight", &GetScreenHeight);
    //emscripten::function("GetMonitorCount", &GetMonitorCount);
    //emscripten::function("GetMonitorPosition", &GetMonitorPosition);
    //emscripten::function("GetMonitorWidth", &GetMonitorWidth);
    //emscripten::function("GetMonitorHeight", &GetMonitorHeight);
    //emscripten::function("GetMonitorPhysicalWidth", &GetMonitorPhysicalWidth);
    //emscripten::function("GetMonitorPhysicalHeight", &GetMonitorPhysicalHeight);
    //emscripten::function("GetMonitorRefreshRate", &GetMonitorRefreshRate);
    //emscripten::function("GetWindowPosition", &GetWindowPosition);
    //emscripten::function("GetWindowScaleDPI", &GetWindowScaleDPI);
    //emscripten::function("GetMonitorName", &GetMonitorName);
    emscripten::function("SetClipboardText", &JSSetClipboardText);
    emscripten::function("GetClipboardText", &JSGetClipboardText);

    // Cursor-related functions
    emscripten::function("ShowCursor", &ShowCursor);
    emscripten::function("HideCursor", &HideCursor);
    emscripten::function("IsCursorHidden", &IsCursorHidden);
    emscripten::function("EnableCursor", &EnableCursor);
    emscripten::function("DisableCursor", &DisableCursor);
    emscripten::function("IsCursorOnScreen", &IsCursorOnScreen);

    // Drawing-related functions
    emscripten::function("ClearBackground", &JSClearBackground);
    emscripten::function("BeginDrawing", &BeginDrawing);
    emscripten::function("EndDrawing", &EndDrawing);
    emscripten::function("BeginMode2D", &JSBeginMode2D);
    emscripten::function("EndMode2D", &EndMode2D);
    emscripten::function("BeginMode3D", &JSBeginMode3D);
    emscripten::function("EndMode3D", &EndMode3D);
    emscripten::function("BeginTextureMode", &JSBeginTextureMode);
    emscripten::function("EndTextureMode", &EndTextureMode);
    emscripten::function("BeginScissorMode", &BeginScissorMode);
    emscripten::function("EndScissorMOde", &EndScissorMode);

    // Screen-space-related functions
    emscripten::function("GetMouseRay", JSGetMouseRay);
    emscripten::function("GetCameraMatrix", &JSGetCameraMatrix);
    emscripten::function("GetCameraMatrix2D", &JSGetCameraMatrix2D);
    emscripten::function("GetWorldToScreen", &JSGetWorldToScreen);
    emscripten::function("GetWorldToScreenEx", &JSGetWorldToScreenEx);
    emscripten::function("GetWorldToScreen2D", &JSGetWorldToScreen2D);
    emscripten::function("GetScreenToWorld2D", &JSGetScreenToWorld2D);

    // Timing-related functions
    emscripten::function("SetTargetFPS", &SetTargetFPS);
    emscripten::function("GetFPS", &GetFPS);
    emscripten::function("GetFrameTime", &GetFrameTime);
    emscripten::function("GetTime", &GetTime);

    // Misc. functions
    emscripten::function("SetConfigFlags", &SetConfigFlags);

    emscripten::function("SetTraceLogLevel", &SetTraceLogLevel);
    emscripten::function("SetTraceLogExit", &SetTraceLogExit);
    //emscripten::function("SetTraceLogCallback", &SetTraceLogCallback, emscripten::allow_raw_pointers());
    emscripten::function("TraceLog", &JSTraceLog);

    //emscripten::function("MemAlloc", &MemAlloc);
    //emscripten::function("MemFree", &MemFree);
    //emscripten::function("TakeScreenShot", &TakeScreenshot);
    emscripten::function("GetRandomValue", &GetRandomValue);

    // Files management functions
    emscripten::function("LoadFileData", &JSLoadFileData);
    //emscripten::function("UnloadFileData", &UnloadFileData);
    //emscripten::function("SaveFileData", &SaveFileData);
    emscripten::function("LoadFileText", &JSLoadFileText);
    //emscripten::function("SaveFileText", &SaveFileText);
    emscripten::function("FileExists", &JSFileExists);
    emscripten::function("DirectoryExists", &JSDirectoryExists);
    emscripten::function("IsFileExtension", &JSIsFileExtension);
    emscripten::function("GetFileExtension", &JSGetFileExtension);
    emscripten::function("GetFileName", &JSGetFileName);
    emscripten::function("GetFileNameWithoutExt", &JSGetFileNameWithoutExt);
    emscripten::function("GetDirectoryPath", &JSGetDirectoryPath);
    emscripten::function("GetPrevDirectoryPath", &JSGetPrevDirectoryPath);
    emscripten::function("GetWorkingDirectory", &JSGetWorkingDirectory);

    emscripten::function("CompressData", &JSCompressData);
    emscripten::function("DecompressData", &JSDecompressData);

    // Persistent storage managment
    emscripten::function("SaveStorageValue", &SaveStorageValue);
    emscripten::function("LoadStorageValue", &LoadStorageValue);

    //emscripten::function("OpenUrl", &OpenURL);

    //------------------------------------------------------------------------------------
    // Input Handling Functions (Module: core)
    //------------------------------------------------------------------------------------

    // Input-related functions: keyboard
    emscripten::function("IsKeyPressed", &IsKeyPressed);
    emscripten::function("IsKeyDown", &IsKeyDown);
    emscripten::function("IsKeyReleased", &IsKeyReleased);
    emscripten::function("IsKeyUp", &IsKeyUp);
    //emscripten::function("SetExitKey", &SetExitKey);
    emscripten::function("GetKeyPressed", &GetKeyPressed);
    emscripten::function("GetCharPressed", &GetCharPressed);

    // Input-related functions: gamepads
    emscripten::function("IsGamepadAvailable", &IsGamepadAvailable);
    emscripten::function("IsGamepadName", &JSIsGamepadName);
    emscripten::function("GetGamepadName", &JSGetGamepadName);
    emscripten::function("IsGamepadButtonPressed", &IsGamepadButtonPressed);
    emscripten::function("IsGamepadButtonDown", &IsGamepadButtonDown);
    emscripten::function("IsGamepadButtonRelease", &IsGamepadButtonReleased);
    emscripten::function("IsGamepadButtonUp", &IsGamepadButtonUp);
    emscripten::function("GetGamepadButtonPressed", &GetGamepadButtonPressed);
    emscripten::function("GetGamepadAxisCount", &GetGamepadAxisCount);
    emscripten::function("GetGamepadAxisMovement", &GetGamepadAxisMovement);

    // Input-related functions: mouse
    emscripten::function("IsMouseButtonPressed", &IsMouseButtonDown);
    emscripten::function("IsMouseButtonDown", &IsMouseButtonDown);
    emscripten::function("IsMouseButtonReleased", &IsMouseButtonReleased);
    emscripten::function("IsMouseButtonUp", &IsMouseButtonUp);
    emscripten::function("GetMouseX", &GetMouseX);
    emscripten::function("GetMouseY", &GetMouseY);
    emscripten::function("GetMousePosition", &GetMousePosition);
    emscripten::function("SetMousePosition", &SetMousePosition);
    emscripten::function("SetMouseOffset", &SetMouseOffset);
    emscripten::function("SetMouseScale", &SetMouseScale);
    emscripten::function("GetMouseWheelMove", &GetMouseWheelMove);
    emscripten::function("GetMouseCursor", &GetMouseCursor);
    emscripten::function("SetMouseCurosor", &SetMouseCursor);

    // Input-related functions: touch
    emscripten::function("GetTouchX", &GetTouchX);
    emscripten::function("GetTouchY", &GetTouchY);
    emscripten::function("GetTouchPosition", &JSGetTouchPosition);

    //------------------------------------------------------------------------------------
    // Gestures and Touch Handling Functions (Module: gestures)
    //------------------------------------------------------------------------------------
    emscripten::function("SetGestureEnabled", &SetGesturesEnabled);
    emscripten::function("IsGestureDetected", &IsGestureDetected);
    emscripten::function("GetGestureDetected", &GetGestureDetected);
    emscripten::function("GetTouchPointsCount", &GetTouchPointsCount);
    emscripten::function("GetGestureHoldDuration", &GetGestureHoldDuration);
    emscripten::function("GetGestureDragVector", &JSGetGestureDragVector);
    emscripten::function("GetGestureDragAngle", &GetGestureDragAngle);
    emscripten::function("GetGesturePinchVector", &JSGetGesturePinchVector);
    emscripten::function("GetGesturePinchAngle", &GetGesturePinchAngle);

    //------------------------------------------------------------------------------------
    // Camera System Functions (Module: camera)
    //------------------------------------------------------------------------------------
    emscripten::function("SetCameraMode", &JSSetCameraMode);
    emscripten::function("UpdateCamera", &JSUpdateCamera);
    emscripten::function("SetCameraPanControl", &SetCameraPanControl);
    emscripten::function("SetCameraAltControl", &SetCameraAltControl);
    emscripten::function("SetCameraSmoothZoomControl", &SetCameraSmoothZoomControl);
    emscripten::function("SetCameraMoveControls", &SetCameraMoveControls);
}