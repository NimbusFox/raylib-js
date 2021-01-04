type Color = {
    r: number,
    g: number,
    b: number,
    a: number
};

type Vector2 = {
    x: number,
    y: number
};

type Vector3 = {
    x: number,
    y: number,
    z: number
};

type Vector4 = {
    x: number,
    y: number,
    z: number,
    w: number
};

type Camera2D = {
    offset: Vector2,
    target: Vector2,
    rotation: number,
    zoom: number
};

type Camera3D = {
    position: Vector3,
    target: Vector3,
    up: Vector3,
    fovy: number,
    type: number
};

type Texture = {
    id: number,
    width: number,
    height: number,
    mipmaps: number,
    format: number
};

type RenderTexture = {
    id: number,
    texture: Texture,
    depth: Texture
};

type RenderTexture2D = RenderTexture;

type Ray = {
    position: Vector3,
    direction: Vector3
};

type Matrix = {
    m0: number, m4: number, m8: number, m12: number,
    m1: number, m5: number, m9: number, m13: number,
    m2: number, m6: number, m10: number, m14: number,
    m3: number, m7: number, m11: number, m15: number
};

declare module Raylib {
    /**
     * System/Window config flags
     * 
     * NOTE: Every bit registers one state (use it with bit masks)
     * 
     * By default all flags are set to 0
     */
    export enum WindowFlag {
        /**Set to try enabling V-Sync on GPU */
        FLAG_VSYNC_HINT = 0x00000040,
        /**Set to run program in fullscreen */
        FLAG_FULLSCREEN_MODE = 0x00000002,
        /**Set to allow resizable window */
        FLAG_WINDOW_RESIZABLE = 0x00000004,
        // /**Set to disable window decoration (frame and buttons) */
        // FLAG_WINDOW_UNDECORATED = 0x00000008,
        // /**Set to hide window */
        // FLAG_WINDOW_HIDDEN = 0x00000080,
        // /**Set to minimize window (iconify) */
        // FLAG_WINDOW_MINIMIZED = 0x00000200,
        // /**Set to maximize window (expanded to monitor) */
        // FLAG_WINDOW_MAXIMIZED = 0x00000400,
        // /**Set to window non focused */
        // FLAG_WINDOW_UNFOCUSED = 0x00000800,
        // /**Set to window always on top */
        // FLAG_WINDOW_TOPMOST = 0x00001000,
        /**Set to allow windows running while minimized */
        FLAG_WINDOW_ALWAYS_RUN = 0x00000100,
        /**Set to allow transparent framebuffer */
        FLAG_WINDOW_TRANSPARENT = 0x00000010,
        /**Set to support HighDPI */
        FLAG_WINDOW_HIGHDPI = 0x00002000,
        /**Set to try enabling MSAA 4X */
        FLAG_MSAA_4X_HINT = 0x00000020,
        /**Set to try enabling interlaced video format (for V3D) */
        FLAG_INTERLACED_HINT = 0x00010000
    }

    export enum LogType {
        LOG_ALL = 0,
        LOG_TRACE = 1,
        LOG_DEBUG = 2,
        LOG_INFO = 3,
        LOG_WARNING = 4,
        LOG_ERROR = 5,
        LOG_FATAL = 6,
        LOG_NONE = 7
    }

    export enum Key {
        // Alphanumeric keys
        KEY_APOSTROPHE = 39,
        KEY_COMMA = 44,
        KEY_MINUS = 45,
        KEY_PERIOD = 46,
        KEY_SLASH = 47,
        KEY_ZERO = 48,
        KEY_ONE = 49,
        KEY_TWO = 50,
        KEY_THREE = 51,
        KEY_FOUR = 52,
        KEY_FIVE = 53,
        KEY_SIX = 54,
        KEY_SEVEN = 55,
        KEY_EIGHT = 56,
        KEY_NINE = 57,
        KEY_SEMICOLON = 59,
        KEY_EQUAL = 61,
        KEY_A = 65,
        KEY_B = 66,
        KEY_C = 67,
        KEY_D = 68,
        KEY_E = 69,
        KEY_F = 70,
        KEY_G = 71,
        KEY_H = 72,
        KEY_I = 73,
        KEY_J = 74,
        KEY_K = 75,
        KEY_L = 76,
        KEY_M = 77,
        KEY_N = 78,
        KEY_O = 79,
        KEY_P = 80,
        KEY_Q = 81,
        KEY_R = 82,
        KEY_S = 83,
        KEY_T = 84,
        KEY_U = 85,
        KEY_V = 86,
        KEY_W = 87,
        KEY_X = 88,
        KEY_Y = 89,
        KEY_Z = 90,

        // Function keys
        KEY_SPACE = 32,
        KEY_ESCAPE = 256,
        KEY_ENTER = 257,
        KEY_TAB = 258,
        KEY_BACKSPACE = 259,
        KEY_INSERT = 260,
        KEY_DELETE = 261,
        KEY_RIGHT = 262,
        KEY_LEFT = 263,
        KEY_DOWN = 264,
        KEY_UP = 265,
        KEY_PAGE_UP = 266,
        KEY_PAGE_DOWN = 267,
        KEY_HOME = 268,
        KEY_END = 269,
        KEY_CAPS_LOCK = 280,
        KEY_SCROLL_LOCK = 281,
        KEY_NUM_LOCK = 282,
        KEY_PRINT_SCREEN = 283,
        KEY_PAUSE = 284,
        KEY_F1 = 290,
        KEY_F2 = 291,
        KEY_F3 = 292,
        KEY_F4 = 293,
        KEY_F5 = 294,
        KEY_F6 = 295,
        KEY_F7 = 296,
        KEY_F8 = 297,
        KEY_F9 = 298,
        KEY_F10 = 299,
        KEY_F11 = 300,
        KEY_F12 = 301,
        KEY_LEFT_SHIFT = 340,
        KEY_LEFT_CONTROL = 341,
        KEY_LEFT_ALT = 342,
        KEY_LEFT_SUPER = 343,
        KEY_RIGHT_SHIFT = 344,
        KEY_RIGHT_CONTROL = 345,
        KEY_RIGHT_ALT = 346,
        KEY_RIGHT_SUPER = 347,
        KEY_KB_MENU = 348,
        KEY_LEFT_BRACKET = 91,
        KEY_BACKSLASH = 92,
        KEY_RIGHT_BRACKET = 93,
        KEY_GRAVE = 96,

        // Keypad keys
        KEY_KP_0 = 320,
        KEY_KP_1 = 321,
        KEY_KP_2 = 322,
        KEY_KP_3 = 323,
        KEY_KP_4 = 324,
        KEY_KP_5 = 325,
        KEY_KP_6 = 326,
        KEY_KP_7 = 327,
        KEY_KP_8 = 328,
        KEY_KP_9 = 329,
        KEY_KP_DECIMAL = 330,
        KEY_KP_DIVIDE = 331,
        KEY_KP_MULTIPLY = 332,
        KEY_KP_SUBTRACT = 333,
        KEY_KP_ADD = 334,
        KEY_KP_ENTER = 335,
        KEY_KP_EQUAL = 336
    }

    export enum GamepadButton {
        GAMEPAD_BUTTON_UNKNOWN = 0,

        // This is normally a DPAD
        GAMEPAD_BUTTON_LEFT_FACE_UP = 1,
        GAMEPAD_BUTTON_LEFT_FACE_RIGHT = 2,
        GAMEPAD_BUTTON_LEFT_FACE_DOWN = 3,
        GAMEPAD_BUTTON_LEFT_FACE_LEFT = 4,

        // This normally corresponds with PlayStation and Xbox controllers
        // XBOX: [Y,X,A,B]
        // PS3: [Triangle,Square,Cross,Circle]
        // No support for 6 button controllers though..
        GAMEPAD_BUTTON_RIGHT_FACE_UP = 5,
        GAMEPAD_BUTTON_RIGHT_FACE_RIGHT = 6,
        GAMEPAD_BUTTON_RIGHT_FACE_DOWN = 7,
        GAMEPAD_BUTTON_RIGHT_FACE_LEFT = 8,

        // Triggers
        GAMEPAD_BUTTON_LEFT_TRIGGER_1 = 9,
        GAMEPAD_BUTTON_LEFT_TRIGGER_2 = 10,
        GAMEPAD_BUTTON_RIGHT_TRIGGER_1 = 11,
        GAMEPAD_BUTTON_RIGHT_TRIGGER_2 = 12,

        // These are buttons in the center of the gamepad
        GAMEPAD_BUTTON_MIDDLE_LEFT = 13,     //PS3 Select
        GAMEPAD_BUTTON_MIDDLE = 14,          //PS Button/XBOX Button
        GAMEPAD_BUTTON_MIDDLE_RIGHT = 15,    //PS3 Start

        // These are the joystick press in buttons
        GAMEPAD_BUTTON_LEFT_THUMB = 16,
        GAMEPAD_BUTTON_RIGHT_THUMB = 17
    }

    export enum MouseButton {
        MOUSE_LEFT_BUTTON = 0,
        MOUSE_RIGHT_BUTTON = 1,
        MOUSE_MIDDLE_BUTTON = 2
    }

    export enum GestureType {
        GESTURE_NONE = 0,
        GESTURE_TAP = 1,
        GESTURE_DOUBLETAP = 2,
        GESTURE_HOLD = 4,
        GESTURE_DRAG = 8,
        GESTURE_SWIPE_RIGHT = 16,
        GESTURE_SWIPE_LEFT = 32,
        GESTURE_SWIPE_UP = 64,
        GESTURE_SWIPE_DOWN = 128,
        GESTURE_PINCH_IN = 256,
        GESTURE_PINCH_OUT = 512
    }

    export enum CameraMode {
        CAMERA_CUSTOM = 0,
        CAMERA_FREE = 1,
        CAMERA_ORBITAL = 2,
        CAMERA_FIRST_PERSON = 3,
        CAMERA_THIRD_PERSON = 4
    }

    export enum CameraType {
        CAMERA_PERSPECTIVE = 0,
        CAMERA_ORTHOGRAPHIC = 1
    }
}

interface IRaylib extends IRaylibCore { }

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
