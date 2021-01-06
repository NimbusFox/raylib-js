/// <reference path="./definitions/raylib.d.ts" />
/// <reference path="./definitions/raylibModules.d.ts" />


import Enums from "./raylibEnums.js";
import * as Structs from "./raylibStructs.js";

const ignoreFunctions: Array<string> = [
    "BeginMode3D",
    "UpdateCamera",
    "SetCameraMode"
];

module Raylib {
    /** 
     * Only to be used when you want to talk to raylib directly.
     * 
     * Keep in mind you will be playing with pointers and not structs from here on out
     */
    export let raylibC: IRaylib;
    export const LIGHTGRAY: Color = { r: 200, g: 200, b: 200, a: 255 };
    export const GRAY: Color = { r: 130, g: 130, b: 130, a: 255 };
    export const DARKGRAY: Color = { r: 80, g: 80, b: 80, a: 255 };
    export const YELLOW: Color = { r: 253, g: 249, b: 0, a: 255 };
    export const GOLD: Color = { r: 255, g: 203, b: 0, a: 255 };
    export const ORANGE: Color = { r: 255, g: 161, b: 0, a: 255 };
    export const PINK: Color = { r: 255, g: 109, b: 194, a: 255 };
    export const RED: Color = { r: 230, g: 41, b: 55, a: 255 };
    export const MAROON: Color = { r: 190, g: 33, b: 55, a: 255 };
    export const GREEN: Color = { r: 0, g: 228, b: 48, a: 255 };
    export const LIME: Color = { r: 0, g: 158, b: 47, a: 255 };
    export const DARKGREEN: Color = { r: 0, g: 117, b: 44, a: 255 };
    export const SKYBLUE: Color = { r: 102, g: 191, b: 255, a: 255 };
    export const BLUE: Color = { r: 0, g: 121, b: 241, a: 255 };
    export const DARKBLUE: Color = { r: 0, g: 82, b: 172, a: 255 };
    export const PURPLE: Color = { r: 200, g: 122, b: 255, a: 255 };
    export const VIOLET: Color = { r: 135, g: 60, b: 190, a: 255 };
    export const DARKPURPLE: Color = { r: 112, g: 31, b: 126, a: 255 };
    export const BEIGE: Color = { r: 211, g: 176, b: 131, a: 255 };
    export const BROWN: Color = { r: 127, g: 106, b: 79, a: 255 };
    export const DARKBROWN: Color = { r: 76, g: 63, b: 47, a: 255 };

    export const WHITE: Color = { r: 255, g: 255, b: 255, a: 255 };
    export const BLACK: Color = { r: 0, g: 0, b: 0, a: 255 };
    export const BLANK: Color = { r: 0, g: 0, b: 0, a: 0 };
    export const MAGENTA: Color = { r: 255, g: 0, b: 255, a: 255 };
    export const RAYWHITE: Color = { r: 245, g: 245, b: 245, a: 255 };

    declare let raylib: (arg: any) => Promise<IRaylib>;

    export function init() {
        var module;
        if (window !== undefined) {
            module = (window as any).Module;
        }
        var init = module.onRuntimeInitialized;
        module.onRuntimeInitialized = undefined;
        raylib(module).then(ray => {
            raylibC = ray;

            for (let functionName in raylibC) {
                if (ignoreFunctions.indexOf(functionName) !== -1) {
                    continue;
                }

                if (Raylib.hasOwnProperty(functionName)) {
                    Raylib[functionName] = raylibC[functionName];
                }
            }

            init();
        });
    }

    export const WindowFlag = Enums.WindowFlag;
    export const LogType = Enums.LogType;
    export const Key = Enums.Key;
    export const GamepadButton = Enums.GamepadButton;
    export const MouseButton = Enums.MouseButton;
    export const GestureType = Enums.GestureType;
    export const CameraMode = Enums.CameraMode;
    export const CameraType = Enums.CameraType;
    export const PixelFormat = Enums.PixelFormat;
    export const CubemapLayoutType = Enums.CubemapLayoutType;
    export const TextureFilterMode = Enums.TextureFilterMode;
    export const TextureWrapMode = Enums.TextureWrapMode;
    export const NPatchType = Enums.NPatchType;
    export const MaterialMapType = Enums.MaterialMapType;
    export const BlendMode = Enums.BlendMode;

    export const Vector2 = Structs.Vector2;
    export const Vector3 = Structs.Vector3;
    export const Camera3D = Structs.Camera3D;

    //#region PlaceholderFunctions

    export function SetModelTexture(id: number, materialIndex: number, mapsIndex: number, texture: Texture2D): void {
        throw new Error("Method not implemented.");
    }

    export function InitWindow(width: number, height: number): void {
        throw new Error("Method not implemented.");
    }

    export function IsWindowReady(): boolean {
        throw new Error("Method not implemented.");
    }

    export function IsWindowFullScreen(): boolean {
        throw new Error("Method not implemented.");
    }

    export function IsWindowFocused(): boolean {
        throw new Error("Method not implemented.");
    }

    export function IsWindowState(flag: Enums.WindowFlag): boolean {
        throw new Error("Method not implemented.");
    }

    export function SetWindowState(flag: Enums.WindowFlag): void {
        throw new Error("Method not implemented.");
    }

    export function ClearWindowState(flag: Enums.WindowFlag): void {
        throw new Error("Method not implemented.");
    }

    export function ToggleFullScreen(): void {
        throw new Error("Method not implemented.");
    }

    export function SetWindowSize(width: number, height: number): void {
        throw new Error("Method not implemented.");
    }

    export function GetScreenWidth(): number {
        throw new Error("Method not implemented.");
    }

    export function GetScreenHeight(): number {
        throw new Error("Method not implemented.");
    }

    export function SetClipboardText(text: string): void {
        throw new Error("Method not implemented.");
    }

    export function GetClipboardText(): string {
        throw new Error("Method not implemented.");
    }

    export function ShowCursor(): void {
        throw new Error("Method not implemented.");
    }

    export function HideCursor(): void {
        throw new Error("Method not implemented.");
    }

    export function IsCursorHidden(): boolean {
        throw new Error("Method not implemented.");
    }

    export function EnableCursor(): void {
        throw new Error("Method not implemented.");
    }

    export function DisableCursor(): void {
        throw new Error("Method not implemented.");
    }

    export function IsCursorOnScreen(): boolean {
        throw new Error("Method not implemented.");
    }

    export function ClearBackground(color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function BeginDrawing(): void {
        throw new Error("Method not implemented.");
    }

    export function EndDrawing(): void {
        throw new Error("Method not implemented.");
    }

    export function BeginMode2D(): void {
        throw new Error("Method not implemented.");
    }

    export function EndMode2D(): void {
        throw new Error("Method not implemented.");
    }

    export function BeginMode3D(camera: Structs.Camera3D): void {
        raylibC.BeginMode3D(camera.pointer);
    }

    export function EndMode3D(): void {
        throw new Error("Method not implemented.");
    }

    export function BeginTextureMode(target: RenderTexture): void {
        throw new Error("Method not implemented.");
    }

    export function EndTextureMode(): void {
        throw new Error("Method not implemented.");
    }

    export function BeginScissorMode(x: number, y: number, width: number, height: number): void {
        throw new Error("Method not implemented.");
    }

    export function EndScissorMode(): void {
        throw new Error("Method not implemented.");
    }

    export function GetMouseRay(mousePosition: Vector2, camera: Structs.Camera3D): Ray {
        throw new Error("Method not implemented.");
    }

    export function GetCameraMatrix(camera: Structs.Camera3D): Matrix {
        throw new Error("Method not implemented.");
    }

    export function GetCameraMatrix2D(camera: Camera2D): Matrix {
        throw new Error("Method not implemented.");
    }

    export function GetWorldToScreen(position: Vector3, camera: Structs.Camera3D): Vector2 {
        throw new Error("Method not implemented.");
    }

    export function GetWorldToScreenEx(position: Vector3, camera: Structs.Camera3D, width: number, height: number): Vector2 {
        throw new Error("Method not implemented.");
    }

    export function GetWorldToScreen2D(position: Vector2, camera: Camera2D): Vector2 {
        throw new Error("Method not implemented.");
    }

    export function GetScreenToWorld2D(position: Vector2, camera: Camera2D): Vector2 {
        throw new Error("Method not implemented.");
    }

    export function SetTargetFPS(fps: number): void {
        throw new Error("Method not implemented.");
    }

    export function GetFPS(): number {
        throw new Error("Method not implemented.");
    }

    export function GetFrameTime(): number {
        throw new Error("Method not implemented.");
    }

    export function GetTime(): number {
        throw new Error("Method not implemented.");
    }

    export function SetConfigFlags(flags: Enums.WindowFlag): void {
        throw new Error("Method not implemented.");
    }

    export function SetTraceLogLevel(logType: Enums.LogType): void {
        throw new Error("Method not implemented.");
    }

    export function SetTraceLogExit(logType: Enums.LogType): void {
        throw new Error("Method not implemented.");
    }

    export function TraceLog(logType: Enums.LogType, text: string): void {
        throw new Error("Method not implemented.");
    }

    export function GetRandomValue(min: number, max: number): number {
        throw new Error("Method not implemented.");
    }

    export function LoadFileData(fileName: string): number[] {
        throw new Error("Method not implemented.");
    }

    export function LoadFileText(fileName: string): string {
        throw new Error("Method not implemented.");
    }

    export function FileExists(fileName: string): boolean {
        throw new Error("Method not implemented.");
    }

    export function DirectoryExists(dirPath: string): boolean {
        throw new Error("Method not implemented.");
    }

    export function IsFileExtension(fileName: string, ext: string): boolean {
        throw new Error("Method not implemented.");
    }

    export function GetFileExtension(fileName: string): string {
        throw new Error("Method not implemented.");
    }

    export function GetFileName(filePath: string): string {
        throw new Error("Method not implemented.");
    }

    export function GetFileNameWithoutExt(filePath: string): string {
        throw new Error("Method not implemented.");
    }

    export function GetDirectoryPath(dirPath: string): string {
        throw new Error("Method not implemented.");
    }

    export function GetPrevDirectoryPath(dirPath: string): string {
        throw new Error("Method not implemented.");
    }

    export function GetWorkingDirectory(): string {
        throw new Error("Method not implemented.");
    }

    export function CompressData(data: number[]): number[] {
        throw new Error("Method not implemented.");
    }

    export function DecompressData(data: number[]): number[] {
        throw new Error("Method not implemented.");
    }

    export function SaveStorageValue(position: number, value: number): boolean {
        throw new Error("Method not implemented.");
    }

    export function LoadStorageValue(position: number): number {
        throw new Error("Method not implemented.");
    }

    export function IsKeyPressed(key: Enums.Key): boolean {
        throw new Error("Method not implemented.");
    }

    export function IsKeyDown(key: Enums.Key): boolean {
        throw new Error("Method not implemented.");
    }

    export function IsKeyReleased(key: Enums.Key): boolean {
        throw new Error("Method not implemented.");
    }

    export function IsKeyUp(key: Enums.Key): boolean {
        throw new Error("Method not implemented.");
    }

    export function GetKeyPressed(): Enums.Key {
        throw new Error("Method not implemented.");
    }

    export function GetCharPressed(): number {
        throw new Error("Method not implemented.");
    }

    export function IsGamepadAvailable(gamepad: number): boolean {
        throw new Error("Method not implemented.");
    }

    export function IsGamepadName(gamepad: number, name: string): boolean {
        throw new Error("Method not implemented.");
    }

    export function GetGamepadName(gamepad: number): string {
        throw new Error("Method not implemented.");
    }

    export function IsGamepadButtonPressed(gamepad: number, button: Enums.GamepadButton): boolean {
        throw new Error("Method not implemented.");
    }

    export function IsGamepadButtonDown(gamepad: number, button: Enums.GamepadButton): boolean {
        throw new Error("Method not implemented.");
    }

    export function IsGamepadButtonRelease(gamepad: number, button: Enums.GamepadButton): boolean {
        throw new Error("Method not implemented.");
    }

    export function IsGamepadButtonUp(gamepad: number, button: Enums.GamepadButton): boolean {
        throw new Error("Method not implemented.");
    }

    export function GetGamepadButtonPressed(): number {
        throw new Error("Method not implemented.");
    }

    export function GetGamepadAxisCount(gamepad: number): number {
        throw new Error("Method not implemented.");
    }

    export function GetGamepadAxisMovement(gamepad: number, axis: number): number {
        throw new Error("Method not implemented.");
    }

    export function IsMouseButtonPressed(button: Enums.MouseButton): boolean {
        throw new Error("Method not implemented.");
    }

    export function IsMouseButtonDown(button: Enums.MouseButton): boolean {
        throw new Error("Method not implemented.");
    }

    export function IsMouseButtonRelease(button: Enums.MouseButton): boolean {
        throw new Error("Method not implemented.");
    }

    export function IsMouseButtonUp(button: Enums.MouseButton): boolean {
        throw new Error("Method not implemented.");
    }

    export function GetMouseX(): number {
        throw new Error("Method not implemented.");
    }

    export function GetMouseY(): number {
        throw new Error("Method not implemented.");
    }

    export function GetMousePosition(): Vector2 {
        throw new Error("Method not implemented.");
    }

    export function SetMousePosition(x: number, y: number): void {
        throw new Error("Method not implemented.");
    }

    export function SetMouseOffset(offsetX: number, offsetY: number): void {
        throw new Error("Method not implemented.");
    }

    export function SetMouseScale(scaleX: number, scaleY: number): void {
        throw new Error("Method not implemented.");
    }

    export function GetMouseWheelMove(): number {
        throw new Error("Method not implemented.");
    }

    export function GetMouseCursor(): number {
        throw new Error("Method not implemented.");
    }

    export function SetMouseCursor(cursor: number): void {
        throw new Error("Method not implemented.");
    }

    export function GetTouchX(): number {
        throw new Error("Method not implemented.");
    }

    export function GetTouchY(): number {
        throw new Error("Method not implemented.");
    }

    export function GetTouchPosition(index: number): Vector2 {
        throw new Error("Method not implemented.");
    }

    export function SetGesturesEnabled(gestureFlags: Enums.GestureType): void {
        throw new Error("Method not implemented.");
    }

    export function IsGestureDetected(gesture: Enums.GestureType): boolean {
        throw new Error("Method not implemented.");
    }

    export function GetGestureDetected(): number {
        throw new Error("Method not implemented.");
    }

    export function GetTouchPointsCount(): number {
        throw new Error("Method not implemented.");
    }

    export function GetGestureHoldDuration(): number {
        throw new Error("Method not implemented.");
    }

    export function GetGestureDragVector(): Vector2 {
        throw new Error("Method not implemented.");
    }

    export function GetGestureDragAngle(): number {
        throw new Error("Method not implemented.");
    }

    export function GetGesturePinchVector(): Vector2 {
        throw new Error("Method not implemented.");
    }

    export function GetGesturePinchAngle(): number {
        throw new Error("Method not implemented.");
    }

    export function SetCameraMode(camera: Structs.Camera3D, mode: globalThis.Raylib.CameraMode): void {
        raylibC.SetCameraMode(camera.pointer, mode);
    }

    export function UpdateCamera(camera: Structs.Camera3D): void {
        raylibC.UpdateCamera(camera.pointer);
    }

    export function SetCameraPanControl(keyPan: Enums.Key): void {
        throw new Error("Method not implemented.");
    }

    export function SetCameraAltControl(keyAlt: Enums.Key): void {
        throw new Error("Method not implemented.");
    }

    export function SetCameraSmoothZoomControl(keySmoothZoom: Enums.Key): void {
        throw new Error("Method not implemented.");
    }

    export function SetCameraMoveControls(keyFront: Enums.Key, keyBack: Enums.Key, keyRight: Enums.Key, keyLeft: Enums.Key, keyUp: Enums.Key, keyDown: Enums.Key): void {
        throw new Error("Method not implemented.");
    }

    export function DrawPixel(posX: number, posY: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawPixelV(position: Vector2, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawLine(startPosX: number, startPosY: number, endPosx: number, endPosY: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawLineV(startPos: Vector2, endPos: Vector2, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawLineEx(startPos: Vector2, endPos: Vector2, thick: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawLineBezier(startPos: Vector2, endPos: Vector2, thick: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawLineStrip(points: Vector2[], color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawCircle(centerX: number, centerY: number, radius: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawCircleSector(center: Vector2, radius: number, startAngle: number, endAngle: number, segments: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawCircleSectorLines(center: Vector2, radius: number, startAngle: number, endAngle: number, segments: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawCircleGradient(centerX: number, centerY: number, radius: number, color1: Color, color2: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawCircleV(center: Vector2, radius: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawCircleLines(centerX: number, centerY: number, radius: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawEllipse(centerX: number, centerY: number, radiusH: number, radiusV: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawEllipseLines(centerX: number, centerY: number, radiusH: number, radiusV: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawRing(center: Vector2, innerRadius: number, outerRadius: number, startAngle: number, endAngle: number, segments: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawRingLines(center: Vector2, innerRadius: number, outerRadius: number, startAngle: number, endAngle: number, segments: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawRectangle(posX: number, posY: number, width: number, height: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawRectangleV(position: Vector2, size: Vector2, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawRectangleRec(rec: Rectangle, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawRectanglePro(rec: Rectangle, origin: Vector2, rotation: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawRectangleGradientV(posX: number, posY: number, width: number, height: number, color1: Color, color2: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawRectangleGradientH(posX: number, posY: number, width: number, height: number, color1: Color, color2: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawRectangleGradientEx(rec: Rectangle, col1: Color, col2: Color, col3: Color, col4: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawRectangleLines(posX: number, posY: number, width: number, height: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawRectangleLinesEx(rec: Rectangle, lineThick: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawRectangleRounded(rec: Rectangle, roundness: number, segments: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawRectangleRoundedLines(rec: Rectangle, roundness: number, segments: number, lineThick: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawTriangle(v1: Vector2, v2: Vector2, v3: Vector2, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawTriangleLines(v1: Vector2, v2: Vector2, v3: Vector2, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawTriangleFan(points: Vector2[], color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawTriangleStrip(points: Vector2[], color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawPoly(center: Vector2, sides: number, radius: number, rotation: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawPolyLines(center: Vector2, sides: number, radius: number, rotation: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function CheckCollisionRecs(rec1: Rectangle, rec2: Rectangle): boolean {
        throw new Error("Method not implemented.");
    }

    export function CheckCollisionCircles(center1: Vector2, radius1: number, center2: Vector2, radius2: number): boolean {
        throw new Error("Method not implemented.");
    }

    export function CheckCollisionCircleRec(center: Vector2, radius: number, rec: Rectangle): boolean {
        throw new Error("Method not implemented.");
    }

    export function CheckCollisionPointRec(point: Vector2, rec: Rectangle): boolean {
        throw new Error("Method not implemented.");
    }

    export function CheckCollisionPointCircle(point: Vector2, center: Vector2, radius: number): boolean {
        throw new Error("Method not implemented.");
    }

    export function CheckCollisionPointTriangle(point: Vector2, p1: Vector2, p2: Vector2, p3: Vector2): boolean {
        throw new Error("Method not implemented.");
    }

    export function CheckCollisionLines(startPos1: Vector2, endPos1: Vector2, startPos2: Vector2, endPos2: Vector2): boolean {
        throw new Error("Method not implemented.");
    }

    export function GetCollisionRec(rec1: Rectangle, rec2: Rectangle): Rectangle {
        throw new Error("Method not implemented.");
    }

    export function LoadImage(fileName: string): Image {
        throw new Error("Method not implemented.");
    }

    export function LoadImageRaw(fileName: string, width: number, height: number, format: Enums.PixelFormat, headerSize: number): Image {
        throw new Error("Method not implemented.");
    }

    export function LoadImageAnim(fileName: string): AnimImage {
        throw new Error("Method not implemented.");
    }

    export function LoadImageFromMemory(fileType: string, fileData: number[]): Image {
        throw new Error("Method not implemented.");
    }

    export function UnloadImage(image: Image): void {
        throw new Error("Method not implemented.");
    }

    export function GenImageColor(width: number, height: number, color: Color): Image {
        throw new Error("Method not implemented.");
    }

    export function GenImageGradientV(width: number, height: number, top: Color, bottom: Color): Image {
        throw new Error("Method not implemented.");
    }

    export function GenImageGradientH(width: number, height: number, left: Color, right: Color): Image {
        throw new Error("Method not implemented.");
    }

    export function GenImageGradientRadial(width: number, height: number, density: number, inner: Color, outer: Color): Image {
        throw new Error("Method not implemented.");
    }

    export function GenImageChecked(width: number, height: number, checksX: number, checksY: number, col1: Color, col2: Color): Image {
        throw new Error("Method not implemented.");
    }

    export function GenImageWhiteNoise(width: number, height: number, factor: number): Image {
        throw new Error("Method not implemented.");
    }

    export function GenImagePerlNoise(width: number, height: number, offsetX: number, offsetY: number, scale: number): Image {
        throw new Error("Method not implemented.");
    }

    export function GenImageCellular(width: number, height: number, tileSize: number): Image {
        throw new Error("Method not implemented.");
    }

    export function ImageCopy(image: Image): Image {
        throw new Error("Method not implemented.");
    }

    export function ImageFromImage(image: Image, rec: Rectangle): Image {
        throw new Error("Method not implemented.");
    }

    export function ImageText(text: string, fontSize: number, color: Color): Image {
        throw new Error("Method not implemented.");
    }

    export function ImageTextEx(font: Font, text: string, fontSize: number, spacing: number, tint: Color): Image {
        throw new Error("Method not implemented.");
    }

    export function ImageFormat(image: Image, newFormat: number): void {
        throw new Error("Method not implemented.");
    }

    export function ImageToPOT(image: Image, fill: Color): void {
        throw new Error("Method not implemented.");
    }

    export function ImageCrop(image: Image, crop: Rectangle): void {
        throw new Error("Method not implemented.");
    }

    export function ImageAlphaCrop(image: Image, threshold: number): void {
        throw new Error("Method not implemented.");
    }

    export function ImageAlphaClear(image: Image, color: Color, threshold: number): void {
        throw new Error("Method not implemented.");
    }

    export function ImageAlphaMask(image: Image, alphaMask: Image): void {
        throw new Error("Method not implemented.");
    }

    export function ImageAlphaPremultiply(image: Image): void {
        throw new Error("Method not implemented.");
    }

    export function ImageResize(image: Image, newWidth: number, newHeight: number): void {
        throw new Error("Method not implemented.");
    }

    export function ImageResizeNN(image: Image, newWidth: number, newHeight: number): void {
        throw new Error("Method not implemented.");
    }

    export function ImageResizeCanvas(image: Image, newWidth: number, newHeight: number, offsetX: number, offsetY: number, fill: Color): void {
        throw new Error("Method not implemented.");
    }

    export function ImageMipmaps(image: Image): void {
        throw new Error("Method not implemented.");
    }

    export function ImageDither(image: Image, rBpp: number, gBpp: number, bBpp: number, aBpp: number): void {
        throw new Error("Method not implemented.");
    }

    export function ImageFlipVertical(image: Image): void {
        throw new Error("Method not implemented.");
    }

    export function ImageFlipHorizontal(image: Image): void {
        throw new Error("Method not implemented.");
    }

    export function ImageRotateCW(image: Image): void {
        throw new Error("Method not implemented.");
    }

    export function ImageRotateCCW(image: Image): void {
        throw new Error("Method not implemented.");
    }

    export function ImageColorTint(image: Image, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function ImageColorInvert(image: Image): void {
        throw new Error("Method not implemented.");
    }

    export function ImageColorGrayscale(image: Image): void {
        throw new Error("Method not implemented.");
    }

    export function ImageColorContrast(image: Image, contrast: number): void {
        throw new Error("Method not implemented.");
    }

    export function ImageColorBrightness(image: Image, brightness: number): void {
        throw new Error("Method not implemented.");
    }

    export function ImageColorReplace(image: Image, color: Color, replace: Color): void {
        throw new Error("Method not implemented.");
    }

    export function LoadImagePalette(image: Image, maxPaletteSize: number): Color[] {
        throw new Error("Method not implemented.");
    }

    export function GetImageAlphaBorder(image: Image, threshold: number): Rectangle {
        throw new Error("Method not implemented.");
    }

    export function ImageClearBackground(dst: Image, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function ImageDrawPixel(dst: Image, posX: number, posY: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function ImageDrawPixelV(dst: Image, postion: Vector2, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function ImageDrawLine(dst: Image, startPosX: number, startPosY: number, endPosX: number, endPosY: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function ImageDrawLineV(dst: Image, start: Vector2, end: Vector2, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function ImageDrawCircle(dst: Image, centerX: number, centerY: number, radius: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function ImageDrawCircleV(dst: Image, center: Vector2, radius: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function ImageDrawRectangle(dst: Image, posX: number, posY: number, width: number, height: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function ImageDrawRectangleV(dst: Image, position: Vector2, size: Vector2, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function ImageDrawRectangleRec(dst: Image, rec: Rectangle, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function ImageDrawRectangleLines(dst: Image, rec: Rectangle, thick: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function ImageDraw(dst: Image, src: Image, srcRec: Rectangle, dstRec: Rectangle, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function ImageDrawText(dst: Image, text: string, posX: number, posY: number, fontSize: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function ImageDrawTextEx(dst: Image, font: Font, text: string, position: Vector2, fontSize: number, spacing: number, tint: Color): void {
        throw new Error("Method not implemented.");
    }

    export function LoadTexture(fileName: string): Texture {
        throw new Error("Method not implemented.");
    }

    export function LoadTextureFromImage(image: Image): Texture {
        throw new Error("Method not implemented.");
    }

    export function LoadTextureCubemap(image: Image, layoutType: Enums.CubemapLayoutType): Texture {
        throw new Error("Method not implemented.");
    }

    export function LoadRenderTexture(width: number, height: number): RenderTexture {
        throw new Error("Method not implemented.");
    }

    export function UnloadTexture(texture: Texture): void {
        throw new Error("Method not implemented.");
    }

    export function UnloadRenderTexture(target: RenderTexture): void {
        throw new Error("Method not implemented.");
    }

    export function UpdateTexture(texture: Texture, pixels: Color[]): void {
        throw new Error("Method not implemented.");
    }

    export function UpdateTextureRec(text: Texture, rec: Rectangle, pixels: Color[]): void {
        throw new Error("Method not implemented.");
    }

    export function GetTextureData(texture: Texture): Image {
        throw new Error("Method not implemented.");
    }

    export function GetScreenData(): Image {
        throw new Error("Method not implemented.");
    }

    export function GenTextureMipmaps(texture: Texture): Texture {
        throw new Error("Method not implemented.");
    }

    export function SetTextureFilter(texture: Texture, filterMode: Enums.TextureFilterMode): void {
        throw new Error("Method not implemented.");
    }

    export function SetTextureWrap(texture: Texture, wrapMode: Enums.TextureWrapMode): void {
        throw new Error("Method not implemented.");
    }

    export function DrawTexture(texture: Texture, posX: number, posY: number, tint: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawTextureV(texture: Texture, position: Vector2, tint: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawTextureEx(texture: Texture, position: Vector2, rotation: number, scale: number, tint: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawTextureRec(texture: Texture, source: Rectangle, position: Vector2, tint: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawTextureQuad(texture: Texture, tiling: Vector2, offset: Vector2, quad: Rectangle, tint: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawTextureTiled(texture: Texture, source: Rectangle, dest: Rectangle, origin: Vector2, rotation: number, scale: number, tint: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawTexturePro(texture: Texture, source: Rectangle, dest: Rectangle, origin: Vector2, rotation: number, tint: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawTextureNPatch(texture: Texture, nPatchInfo: NPatchInfo, dest: Rectangle, origin: Vector2, rotation: number, tint: Color): void {
        throw new Error("Method not implemented.");
    }

    export function Fade(color: Color, alpha: number): Color {
        throw new Error("Method not implemented.");
    }

    export function ColorToInt(color: Color): number {
        throw new Error("Method not implemented.");
    }

    export function ColorNormalize(color: Color): Vector4 {
        throw new Error("Method not implemented.");
    }

    export function ColorFromNormalized(normalized: Vector4): Color {
        throw new Error("Method not implemented.");
    }

    export function ColorToHSV(color: Color): Vector3 {
        throw new Error("Method not implemented.");
    }

    export function ColorAlpha(color: Color, alpha: number): Color {
        throw new Error("Method not implemented.");
    }

    export function ColorAlphaBlend(dst: Color, src: Color, tint: Color): Color {
        throw new Error("Method not implemented.");
    }

    export function GetColor(hexValue: number): Color {
        throw new Error("Method not implemented.");
    }

    export function GetFontDefault(): Font {
        throw new Error("Method not implemented.");
    }

    export function LoadFont(fileName: string): Font {
        throw new Error("Method not implemented.");
    }

    export function LoadFontEx(fileName: string, fontSize: number, fontChars: number[]): Font {
        throw new Error("Method not implemented.");
    }

    export function LoadFontFromImage(image: Image, key: Color, firstChar: number): Font {
        throw new Error("Method not implemented.");
    }

    export function LoadFontFromMemory(filyType: string, fileData: number[], fontSize: number, fontChars: number[]): Font {
        throw new Error("Method not implemented.");
    }

    export function UnloadFont(font: Font): void {
        throw new Error("Method not implemented.");
    }

    export function DrawFPS(posX: number, posY: number): void {
        throw new Error("Method not implemented.");
    }

    export function DrawText(text: string, posX: number, posY: number, fontSize: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawTextEx(font: Font, text: string, position: Vector2, fontSize: number, spacing: number, tint: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawTextRec(font: Font, text: string, rec: Rectangle, fontSize: number, spacing: number, wordWrap: boolean, tint: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawTextRecEx(font: Font, text: string, rec: Rectangle, fontSize: number, spacing: number, wordWrap: boolean, tint: Color, selectStart: number, selectLength: number, selectTint: Color, selectBackTint: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawTextCodepoint(font: Font, codepoint: number, position: Vector2, fontSize: number, tint: Color): void {
        throw new Error("Method not implemented.");
    }

    export function MeasureText(text: string, fontSize: number): number {
        throw new Error("Method not implemented.");
    }

    export function MeasureTextEx(font: Font, text: string, fontSize: number, spacing: number): Vector2 {
        throw new Error("Method not implemented.");
    }

    export function GetGlyphIndex(font: Font, codepoint: number): number {
        throw new Error("Method not implemented.");
    }

    export function TextToInteger(text: string): number {
        throw new Error("Method not implemented.");
    }

    export function TextToUtf8(codepoints: number[]): string {
        throw new Error("Method not implemented.");
    }

    export function GetCodepoints(text: string): number[] {
        throw new Error("Method not implemented.");
    }

    export function GetCodepointsCount(text: string): number {
        throw new Error("Method not implemented.");
    }

    export function GetNextCodepoint(text: string): Codepoint {
        throw new Error("Method not implemented.");
    }

    export function CodepointToUtf8(codepoint: number): string {
        throw new Error("Method not implemented.");
    }

    export function DrawLine3D(startPos: Vector3, endPos: Vector3, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawPoint3D(position: Vector3, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawCircle3D(center: Vector3, radius: number, rotationAxis: Vector3, rotationAngle: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawTriangle3D(v1: Vector3, v2: Vector3, v3: Vector3): void {
        throw new Error("Method not implemented.");
    }

    export function DrawTriangleStrip3D(points: Vector3[], color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawCube(position: Vector3, width: number, height: number, length: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawCubeV(position: Vector3, size: Vector3, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawCubeWires(position: Vector3, width: number, height: number, length: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawCubeWiresV(position: Vector3, size: Vector3, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawCubeTexture(texture: Texture, position: Vector3, width: number, height: number, length: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawSphere(centerPos: Vector3, radius: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawSpehereEx(centerPos: Vector3, radius: number, rings: number, slices: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawSphereWires(centerPos: Vector3, radius: number, rings: number, slices: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawCylinder(position: Vector3, radiusTop: number, radiusBottom: number, height: number, slices: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawCylinderWires(position: Vector3, radiusTop: number, radiusBottom: number, height: number, slices: number, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawPlane(centerPos: Vector3, size: Vector2, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawRay(ray: Ray, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawGrid(slices: number, spacing: number): void {
        throw new Error("Method not implemented.");
    }

    export function DrawGizmo(position: Vector3): void {
        throw new Error("Method not implemented.");
    }

    export function LoadModel(fileName: string): number {
        throw new Error("Method not implemented.");
    }

    export function LoadModelFromMesh(mesh: number): number {
        throw new Error("Method not implemented.");
    }

    export function UnloadModel(model: any): void {
        throw new Error("Method not implemented.");
    }

    export function UnloadModelKeepMeshes(model: any): void {
        throw new Error("Method not implemented.");
    }

    export function LoadMeshes(fileName: string): number[] {
        throw new Error("Method not implemented.");
    }

    export function UnloadMesh(mesh: any): void {
        throw new Error("Method not implemented.");
    }

    export function LoadMaterials(fileName: string): any[] {
        throw new Error("Method not implemented.");
    }

    export function LoadMaterialDefault() {
        throw new Error("Method not implemented.");
    }

    export function UnloadMaterial(material: any) {
        throw new Error("Method not implemented.");
    }

    export function SetMaterialTexture(material: any, mapType: Enums.MaterialMapType, texture: Texture): void {
        throw new Error("Method not implemented.");
    }

    export function SetModelMeshMaterial(model: any, meshId: number, materialId: number): void {
        throw new Error("Method not implemented.");
    }

    export function LoadModelAnimations(fileName: string): any[] {
        throw new Error("Method not implemented.");
    }

    export function UpdateModelAnimation(model: any, anim: any, frame: number): void {
        throw new Error("Method not implemented.");
    }

    export function UnloadModelAnimation(anim: any): void {
        throw new Error("Method not implemented.");
    }

    export function IsModelAnimationValid(mode: any, anim: any): boolean {
        throw new Error("Method not implemented.");
    }

    export function GenMeshPoly(sides: number, radius: number): number {
        throw new Error("Method not implemented.");
    }

    export function GenMeshPlane(width: number, length: number, resX: number, resZ: number): number {
        throw new Error("Method not implemented.");
    }

    export function GenMeshCube(width: number, height: number, length: number): number {
        throw new Error("Method not implemented.");
    }

    export function GenMeshSphere(radius: number, rings: number, slices: number): number {
        throw new Error("Method not implemented.");
    }

    export function GenMeshHemiSphere(radius: number, rings: number, slices: number): number {
        throw new Error("Method not implemented.");
    }

    export function GenMeshCylinder(radius: number, height: number, slices: number): number {
        throw new Error("Method not implemented.");
    }

    export function GenMeshTorus(radius: number, size: number, radSeg: number, sides: number): number {
        throw new Error("Method not implemented.");
    }

    export function GenMeshKnot(radius: number, size: number, radSeg: number, sides: number): number {
        throw new Error("Method not implemented.");
    }

    export function GenMeshHeightmap(heightMap: Image, size: Vector3): number {
        throw new Error("Method not implemented.");
    }

    export function GenMeshCubicmap(cubicmap: Image, cubeSize: Vector3): number {
        throw new Error("Method not implemented.");
    }

    export function MeshBoundingBox(mesh: any): BoundingBox {
        throw new Error("Method not implemented.");
    }

    export function MeshTangents(mesh: any): void {
        throw new Error("Method not implemented.");
    }

    export function MeshBinormals(mesh: any): void {
        throw new Error("Method not implemented.");
    }

    export function MeshNormalsSmooth(mesh: any): void {
        throw new Error("Method not implemented.");
    }

    export function DrawModel(model: number, position: Vector3, scale: number, tint: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawModelEx(model: number, position: Vector3, rotationAxis: Vector3, rotationAngle: number, scale: Vector3, tint: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawModelWires(model: number, position: Vector3, scale: number, tint: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawModelWiresEx(model: number, position: Vector3, rotationAxis: Vector3, rotationAngle: number, scale: Vector3, tint: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawBoundingBox(box: BoundingBox, color: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawBillboard(camera: Structs.Camera3D, texture: Texture, center: Vector3, size: number, tint: Color): void {
        throw new Error("Method not implemented.");
    }

    export function DrawBullboardRec(camera: Structs.Camera3D, texture: Texture, source: Rectangle, center: Vector3, size: number, tint: Color): void {
        throw new Error("Method not implemented.");
    }

    export function CheckCollisionSpheres(center1: Vector3, radius1: number, center2: Vector3, radius2: number): boolean {
        throw new Error("Method not implemented.");
    }

    export function CheckCollisionBoxes(box1: BoundingBox, box2: BoundingBox): boolean {
        throw new Error("Method not implemented.");
    }

    export function CheckCollisionBoxSphere(box: BoundingBox, center: Vector3, radius: number): boolean {
        throw new Error("Method not implemented.");
    }

    export function CheckCollisionRaySphere(ray: Ray, center: Vector3, radius: number): boolean {
        throw new Error("Method not implemented.");
    }

    export function CheckCollisionRaySphereEx(ray: Ray, center: Vector3, radius: number): boolean | Vector3 {
        throw new Error("Method not implemented.");
    }

    export function CheckCollisionRayBox(ray: Ray, box: BoundingBox): boolean {
        throw new Error("Method not implemented.");
    }

    export function GetCollisionRayMesh(ray: Ray, mesh: any, transform: Matrix): RayHitInfo {
        throw new Error("Method not implemented.");
    }

    export function GetCollisionRayModel(ray: Ray, model: any): RayHitInfo {
        throw new Error("Method not implemented.");
    }

    export function GetCollisionRayTriangle(ray: Ray, p1: Vector3, p2: Vector3, p3: Vector3): RayHitInfo {
        throw new Error("Method not implemented.");
    }

    export function GetCollisionRayGround(ray: Ray, groundHeight: number): RayHitInfo {
        throw new Error("Method not implemented.");
    }

    export function LoadShader(vsFileName: string, fsFileName: string): Shader {
        throw new Error("Method not implemented.");
    }

    export function LoadShaderCode(vsCode: string, fsCode: string): Shader {
        throw new Error("Method not implemented.");
    }

    export function UnloadShader(shader: Shader): void {
        throw new Error("Method not implemented.");
    }

    export function GetShaderDefault(): Shader {
        throw new Error("Method not implemented.");
    }

    export function GetTextureDefault(): Texture {
        throw new Error("Method not implemented.");
    }

    export function GetShapesTexture(): Texture {
        throw new Error("Method not implemented.");
    }

    export function GetShapesTextureRec(): Rectangle {
        throw new Error("Method not implemented.");
    }

    export function SetShapesTexture(texture: Texture, source: Rectangle): void {
        throw new Error("Method not implemented.");
    }

    export function GetShaderLocation(shader: Shader, uniformName: string): number {
        throw new Error("Method not implemented.");
    }

    export function GetShaderLocationAttrib(shader: Shader, atrribName: string): number {
        throw new Error("Method not implemented.");
    }

    export function SetShaderValueFloat(shader: Shader, uniformLoc: number, value: number): void {
        throw new Error("Method not implemented.");
    }

    export function SetShaderValueInt(shader: Shader, uniformLoc: number, value: number): void {
        throw new Error("Method not implemented.");
    }

    export function SetShaderValueVec2(shader: Shader, uniformLoc: number, value: Vector2): void {
        throw new Error("Method not implemented.");
    }

    export function SetShaderValueVec3(shader: Shader, uniformLoc: number, value: Vector3): void {
        throw new Error("Method not implemented.");
    }

    export function SetShaderValueVec4(shader: Shader, uniformLoc: number, value: Vector4): void {
        throw new Error("Method not implemented.");
    }

    export function SetShaderValueFloatV(shader: Shader, uniformLoc: number, value: number, count: number): void {
        throw new Error("Method not implemented.");
    }

    export function SetShaderValueIntV(shader: Shader, uniformLoc: number, value: number, count: number): void {
        throw new Error("Method not implemented.");
    }

    export function SetShaderValueVec2V(shader: Shader, uniformLoc: number, value: Vector2, count: number): void {
        throw new Error("Method not implemented.");
    }

    export function SetShaderValueVec3V(shader: Shader, uniformLoc: number, value: Vector3, count: number): void {
        throw new Error("Method not implemented.");
    }

    export function SetShaderValueVec4V(shader: Shader, uniformLoc: number, value: Vector4, count: number): void {
        throw new Error("Method not implemented.");
    }

    export function SetShaderValueMatrix(shader: Shader, uniformLoc: number, value: Matrix): void {
        throw new Error("Method not implemented.");
    }

    export function SetShaderValueTexture(shader: Shader, uniformLoc: number, value: Texture): void {
        throw new Error("Method not implemented.");
    }

    export function SetMatrixProjection(matrix: Matrix): void {
        throw new Error("Method not implemented.");
    }

    export function SetMatrixModelView(matrix: Matrix): void {
        throw new Error("Method not implemented.");
    }

    export function GetMatrixModelView(): Matrix {
        throw new Error("Method not implemented.");
    }

    export function GetMatrixProjection(): Matrix {
        throw new Error("Method not implemented.");
    }

    export function BeginShaderMode(shader: Shader): void {
        throw new Error("Method not implemented.");
    }

    export function EndShaderMode(): void {
        throw new Error("Method not implemented.");
    }

    export function BeginBlendMode(mode: Enums.BlendMode): void {
        throw new Error("Method not implemented.");
    }

    export function EndBlendMode(): void {
        throw new Error("Method not implemented.");
    }

    export function InitVrSimulator(): void {
        throw new Error("Method not implemented.");
    }

    export function CloseVrSimulator(): void {
        throw new Error("Method not implemented.");
    }

    export function UpdateVrTracking(camera: Structs.Camera3D): void {
        throw new Error("Method not implemented.");
    }

    export function SetVrConfiguration(info: any, distortion: Shader): void {
        throw new Error("Method not implemented.");
    }

    export function IsVrSimulatorReady(): boolean {
        throw new Error("Method not implemented.");
    }

    export function ToggleVrMode(): void {
        throw new Error("Method not implemented.");
    }

    export function BeginVrDrawing(): void {
        throw new Error("Method not implemented.");
    }

    export function EndVrDrawing(): void {
        throw new Error("Method not implemented.");
    }

    //#endregion

}

export default Raylib;
