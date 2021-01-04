/// <reference path="raylibEnums.d.ts" />
interface IRaylib extends IRaylibCore, IRaylibShapes, IRaylibTextures { }

interface IRaylibCore {
    InitWindow(width: number, height: number): void;
    IsWindowReady(): boolean;
    IsWindowFullScreen(): boolean;
    IsWindowFocused(): boolean;
    IsWindowState(flag: Raylib.WindowFlag): boolean;
    SetWindowState(flag: Raylib.WindowFlag): void;
    ClearWindowState(flag: Raylib.WindowFlag): void;
    ToggleFullScreen(): void;
    SetWindowSize(width: number, height: number): void;
    GetScreenWidth(): number;
    GetScreenHeight(): number;
    SetClipboardText(text: string): void;
    GetClipboardText(): string;

    ShowCursor(): void;
    HideCursor(): void;
    IsCursorHidden(): boolean;
    EnableCursor(): void;
    DisableCursor(): void;
    IsCursorOnScreen(): boolean;

    ClearBackground(color: Color): void;
    BeginDrawing(): void;
    EndDrawing(): void;
    BeginMode2D(): void;
    EndMode2D(): void;
    BeginMode3D(): void;
    EndMode3D(): void;
    BeginTextureMode(target: RenderTexture2D): void;
    EndTextureMode(): void;
    BeginScissorMode(x: number, y: number, width: number, height: number): void;
    EndScissorMode(): void;

    GetMouseRay(mousePosition: Vector2, camera: Camera3D): void;
    GetCameraMatrix(camera: Camera3D): Matrix;
    GetCameraMatrix2D(camera: Camera2D): Matrix;
    GetWorldToScreen(position: Vector3, camera: Camera3D): Vector2;
    GetWorldToScreenEx(position: Vector3, camera: Camera3D, width: number, height: number): Vector2;
    GetWorldToScreen2D(position: Vector2, camera: Camera2D): Vector2;
    GetScreenToWorld2D(position: Vector2, camera: Camera2D): Vector2;

    SetTargetFPS(fps: number): void;
    GetFPS(): number;
    GetFrameTime(): number;
    GetTime(): number;

    SetConfigFlags(flags: Raylib.WindowFlag): void;

    SetTraceLogLevel(logType: Raylib.LogType): void;
    SetTraceLogExit(logType: Raylib.LogType): void;
    TraceLog(logType: Raylib.LogType, text: string): void;

    GetRandomValue(min: number, max: number): number;

    LoadFileData(fileName: string): Array<number>;
    LoadFileText(fileName: string): string;
    FileExists(fileName: string): boolean;
    DirectoryExists(dirPath: string): boolean;
    IsFileExtension(fileName: string, ext: string): boolean;
    GetFileExtension(fileName: string): string;
    GetFileName(filePath: string): string;
    GetFileNameWithoutExt(filePath: string): string;
    GetDirectoryPath(dirPath: string): string;
    GetPrevDirectoryPath(dirPath: string): string;
    GetWorkingDirectory(): string;

    CompressData(data: Array<number>): Array<number>;
    DecompressData(data: Array<number>): Array<number>;

    SaveStorageValue(position: number, value: number): boolean;
    LoadStorageValue(position: number): number;

    IsKeyPressed(key: Raylib.Key): boolean;
    IsKeyDown(key: Raylib.Key): boolean;
    IsKeyReleased(key: Raylib.Key): boolean;
    IsKeyUp(key: Raylib.Key): boolean;
    GetKeyPressed(): Raylib.Key;
    GetCharPressed(): number;

    IsGamepadAvailable(gamepad: number): boolean;
    IsGamepadName(gamepad: number, name: string): boolean;
    GetGamepadName(gamepad: number): string;
    IsGamepadButtonPressed(gamepad: number, button: Raylib.GamepadButton): boolean;
    IsGamepadButtonDown(gamepad: number, button: Raylib.GamepadButton): boolean;
    IsGamepadButtonRelease(gamepad: number, button: Raylib.GamepadButton): boolean;
    IsGamepadButtonUp(gamepad: number, button: Raylib.GamepadButton): boolean;
    GetGamepadButtonPressed(): number;
    GetGamepadAxisCount(gamepad: number): number;
    GetGamepadAxisMovement(gamepad: number, axis: number): number;

    IsMouseButtonPressed(button: Raylib.MouseButton): boolean;
    IsMouseButtonDown(button: Raylib.MouseButton): boolean;
    IsMouseButtonRelease(button: Raylib.MouseButton): boolean;
    IsMouseButtonUp(button: Raylib.MouseButton): boolean;
    GetMouseX(): number;
    GetMouseY(): number;
    GetMousePosition(): Vector2;
    SetMousePosition(x: number, y: number): void;
    SetMouseOffset(offsetX: number, offsetY: number): void;
    SetMouseScale(scaleX: number, scaleY: number): void;
    GetMouseWheelMove(): number;
    GetMouseCursor(): number;
    SetMouseCursor(cursor: number): void;

    GetTouchX(): number;
    GetTouchY(): number;
    GetTouchPosition(index: number): Vector2;

    SetGesturesEnabled(gestureFlags: Raylib.GestureType): void;
    IsGestureDetected(gesture: Raylib.GestureType): boolean;
    GetGestureDetected(): number;
    GetTouchPointsCount(): number;
    GetGestureHoldDuration(): number;
    GetGestureDragVector(): Vector2;
    GetGestureDragAngle(): number;
    GetGesturePinchVector(): Vector2;
    GetGesturePinchAngle(): number;

    SetCameraMode(camera: Camera3D, mode: Raylib.CameraMode): void;
    UpdateCamera(camera: Camera3D): Camera3D;
    SetCameraPanControl(keyPan: Raylib.Key): void;
    SetCameraAltControl(keyAlt: Raylib.Key): void;
    SetCameraSmoothZoomControl(keySmoothZoom: Raylib.Key): void;
    SetCameraMoveControls(keyFront: Raylib.Key, keyBack: Raylib.Key, keyRight: Raylib.Key, keyLeft: Raylib.Key, keyUp: Raylib.Key, keyDown: Raylib.Key): void;
}

interface IRaylibShapes {
    DrawPixel(posX: number, posY: number, color: Color): void;
    DrawPixelV(position: Vector2, color: Color): void;
    DrawLine(startPosX: number, startPosY: number, endPosx: number, endPosY: number, color: Color): void;
    DrawLineV(startPos: Vector2, endPos: Vector2, color: Color): void;
    DrawLineEx(startPos: Vector2, endPos: Vector2, thick: number, color: Color): void;
    DrawLineBezier(startPos: Vector2, endPos: Vector2, thick: number, color: Color): void;
    DrawLineStrip(points: Array<Vector2>, color: Color): void;
    DrawCircle(centerX: number, centerY: number, radius: number, color: Color): void;
    DrawCircleSector(center: Vector2, radius: number, startAngle: number, endAngle: number, segments: number, color: Color): void;
    DrawCircleSectorLines(center: Vector2, radius: number, startAngle: number, endAngle: number, segments: number, color: Color): void;
    DrawCircleGradient(centerX: number, centerY: number, radius: number, color1: Color, color2: Color): void;
    DrawCircleV(center: Vector2, radius: number, color: Color): void;
    DrawCircleLines(centerX: number, centerY: number, radius: number, color: Color): void;
    DrawEllipse(centerX: number, centerY: number, radiusH: number, radiusV: number, color: Color): void;
    DrawEllipseLines(centerX: number, centerY: number, radiusH: number, radiusV: number, color: Color): void;
    DrawRing(center: Vector2, innerRadius: number, outerRadius: number, startAngle: number, endAngle: number, segments: number, color: Color): void;
    DrawRingLines(center: Vector2, innerRadius: number, outerRadius: number, startAngle: number, endAngle: number, segments: number, color: Color): void;
    DrawRectangle(posX: number, posY: number, width: number, height: number, color: Color): void;
    DrawRectangleV(position: Vector2, size: Vector2, color: Color): void;
    DrawRectangleRec(rec: Rectangle, color: Color): void;
    DrawRectanglePro(rec: Rectangle, origin: Vector2, rotation: number, color: Color): void;
    DrawRectangleGradientV(posX: number, posY: number, width: number, height: number, color1: Color, color2: Color): void;
    DrawRectangleGradientH(posX: number, posY: number, width: number, height: number, color1: Color, color2: Color): void;
    DrawRectangleGradientEx(rec: Rectangle, col1: Color, col2: Color, col3: Color, col4: Color): void;
    DrawRectangleLines(posX: number, posY: number, width: number, height: number, color: Color): void;
    DrawRectangleLinesEx(rec: Rectangle, lineThick: number, color: Color): void;
    DrawRectangleRounded(rec: Rectangle, roundness: number, segments: number, color: Color): void;
    DrawRectangleRoundedLines(rec: Rectangle, roundness: number, segments: number, lineThick: number, color: Color): void;
    DrawTriangle(v1: Vector2, v2: Vector2, v3: Vector2, color: Color): void;
    DrawTriangleLines(v1: Vector2, v2: Vector2, v3: Vector2, color: Color): void;
    DrawTriangleFan(points: Array<Vector2>, color: Color): void;
    DrawTriangleStrip(points: Array<Vector2>, color: Color): void;
    DrawPoly(center: Vector2, sides: number, radius: number, rotation: number, color: Color): void;
    DrawPolyLines(center: Vector2, sides: number, radius: number, rotation: number, color: Color): void;

    CheckCollisionRecs(rec1: Rectangle, rec2: Rectangle): boolean;
    CheckCollisionCircles(center1: Vector2, radius1: number, center2: Vector2, radius2: number): boolean;
    CheckCollisionCircleRec(center: Vector2, radius: number, rec: Rectangle): boolean;
    CheckCollisionPointRec(point: Vector2, rec: Rectangle): boolean;
    CheckCollisionPointCircle(point: Vector2, center: Vector2, radius: number): boolean;
    CheckCollisionPointTriangle(point: Vector2, p1: Vector2, p2: Vector2, p3: Vector2): boolean;
    CheckCollisionLines(startPos1: Vector2, endPos1: Vector2, startPos2: Vector2, endPos2: Vector2): boolean;
    GetCollisionRec(rec1: Rectangle, rec2: Rectangle): Rectangle;
}

interface IRaylibTextures {
    LoadImage(fileName: string): Image;
    LoadImageRaw(fileName: string, width: number, height: number, format: Raylib.PixelFormat, headerSize: number): Image;
    LoadImageAnim(fileName: string): AnimImage;
    LoadImageFromMemory(fileType: string, fileData: Array<number>): Image;
    UnloadImage(image: Image): void;

    GenImageColor(width: number, height: number, color: Color): Image;
    GenImageGradientV(width: number, height: number, top: Color, bottom: Color): Image;
    GenImageGradientH(width: number, height: number, left: Color, right: Color): Image;
    GenImageGradientRadial(width: number, height: number, density: number, inner: Color, outer: Color): Image;
    GenImageChecked(width: number, height: number, checksX: number, checksY: number, col1: Color, col2: Color): Image;
    GenImageWhiteNoise(width: number, height: number, factor: number): Image;
    GenImagePerlNoise(width: number, height: number, offsetX: number, offsetY: number, scale: number): Image;
    GenImageCellular(width: number, height: number, tileSize: number): Image;

    ImageCopy(image: Image): Image;
    ImageFromImage(image: Image, rec: Rectangle): Image;
    ImageText(text: string, fontSize: number, color: Color): Image;
    ImageTextEx(font: Font, text: string, fontSize: number, spacing: number, tint: Color): Image;
    ImageFormat(image: Image, newFormat: number): void;
    ImageToPOT(image: Image, fill: Color): void;
    ImageCrop(image: Image, crop: Rectangle): void;
    ImageAlphaCrop(image: Image, threshold: number): void;
    ImageAlphaClear(image: Image, color: Color, threshold: number): void;
    ImageAlphaMask(image: Image, alphaMask: Image): void;
    ImageAlphaPremultiply(image: Image): void;
    ImageResize(image: Image, newWidth: number, newHeight: number): void;
    ImageResizeNN(image: Image, newWidth: number, newHeight: number): void;
    ImageResizeCanvas(image: Image, newWidth: number, newHeight: number, offsetX: number, offsetY: number, fill: Color): void;
    ImageMipmaps(image: Image): void;
    ImageDither(image: Image, rBpp: number, gBpp: number, bBpp: number, aBpp: number): void;
    ImageFlipVertical(image: Image): void;
    ImageFlipHorizontal(image: Image): void;
    ImageRotateCW(image: Image): void;
    ImageRotateCCW(image: Image): void;
    ImageColorTint(image: Image, color: Color): void;
    ImageColorInvert(image: Image): void;
    ImageColorGrayscale(image: Image): void;
    ImageColorContrast(image: Image, contrast: number): void;
    ImageColorBrightness(image: Image, brightness: number): void;
    ImageColorReplace(image: Image, color: Color, replace: Color): void;
    LoadImagePalette(image: Image, maxPaletteSize: number): Array<Color>;
    GetImageAlphaBorder(image: Image, threshold: number): Rectangle;

    ImageClearBackground(dst: Image, color: Color): void;
    ImageDrawPixel(dst: Image, posX: number, posY: number, color: Color): void;
    ImageDrawPixelV(dst: Image, postion: Vector2, color: Color): void;
    ImageDrawLine(dst: Image, startPosX: number, startPosY: number, endPosX: number, endPosY: number, color: Color): void;
    ImageDrawLineV(dst: Image, start: Vector2, end: Vector2, color: Color): void;
    ImageDrawCircle(dst: Image, centerX: number, centerY: number, radius: number, color: Color): void;
    ImageDrawCircleV(dst: Image, center: Vector2, radius: number, color: Color): void;
    ImageDrawRectangle(dst: Image, posX: number, posY: number, width: number, height: number, color: Color): void;
    ImageDrawRectangleV(dst: Image, position: Vector2, size: Vector2, color: Color): void;
    ImageDrawRectangleRec(dst: Image, rec: Rectangle, color: Color): void;
    ImageDrawRectangleLines(dst: Image, rec: Rectangle, thick: number, color: Color): void;
    ImageDraw(dst: Image, src: Image, srcRec: Rectangle, dstRec: Rectangle, color: Color): void;
    ImageDrawText(dst: Image, text: string, posX: number, posY: number, fontSize: number, color: Color): void;
    ImageDrawTextEx(dst: Image, font: Font, text: string, position: Vector2, fontSize: number, spacing: number, tint: Color): void;

    LoadTexture(fileName: string): Texture2D;
    LoadTextureFromImage(image: Image): Texture2D;
    LoadTextureCubemap(image: Image, layoutType: Raylib.CubemapLayoutType): TextureCubemap;
    LoadRenderTexture(width: number, height: number): RenderTexture2D;
    UnloadTexture(texture: Texture2D): void;
    UnloadRenderTexture(target: RenderTexture2D): void;
    UpdateTexture(texture: Texture2D, pixels: Array<Color>): void;
    UpdateTextureRec(text: Texture2D, rec: Rectangle, pixels: Array<Color>): void;
    GetTextureData(texture: Texture2D): Image;
    GetScreenData(): Image;

    GenTextureMipmaps(texture: Texture2D): Texture2D;
    SetTextureFilter(texture: Texture2D, filterMode: Raylib.TextureFilterMode): void;
    SetTextureWrap(texture: Texture2D, wrapMode: Raylib.TextureWrapMode): void;

    DrawTexture(texture: Texture2D, posX: number, posY: number, tint: Color): void;
    DrawTextureV(texture: Texture2D, position: Vector2, tint: Color): void;
    DrawTextureEx(texture: Texture2D, position: Vector2, rotation: number, scale: number, tint: Color): void;
    DrawTextureRec(texture: Texture2D, source: Rectangle, position: Vector2, tint: Color): void;
    DrawTextureQuad(texture: Texture2D, tiling: Vector2, offset: Vector2, quad: Rectangle, tint: Color): void;
    DrawTextureTiled(texture: Texture2D, source: Rectangle, dest: Rectangle, origin: Vector2, rotation: number, scale: number, tint: Color): void;
    DrawTexturePro(texture: Texture2D, source: Rectangle, dest: Rectangle, origin: Vector2, rotation: number, tint: Color): void;
    DrawTextureNPatch(texture: Texture2D, nPatchInfo: NPatchInfo, dest: Rectangle, origin: Vector2, rotation: number, tint: Color): void;

    Fade(color: Color, alpha: number): Color;
    ColorToInt(color: Color): number;
    ColorNormalize(color: Color): Vector4;
    ColorFromNormalized(normalized: Vector4): Color;
    ColorToHSV(color: Color): Vector3;
    ColorAlpha(color: Color, alpha: number): Color;
    ColorAlphaBlend(dst: Color, src: Color, tint: Color): Color;
    GetColor(hexValue: number): Color;
}
