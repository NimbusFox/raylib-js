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



interface IraylibCore {
    ClearBackground(color: Color): void;
    InitWindow(width: number, height: number): void;
    SetClipboardText(text: string): void;
    BeginMode2D(camera: Camera2D): void;
    BeginCameraMode3D(camera: Camera3D): void;
    BeginTextureMode(target: RenderTexture2D): void;
    GetMouseRay(mousePosition: Vector2, camera: Camera3D): Ray;
    GetCameraMatrix(camera: Camera3D): Matrix;
    GetCameraMatrix2D(camera: Camera2D): Matrix;
    GetWorldToScreen(position: Vector3, camera: Camera3D): Vector2;
    GetWorldToScreenEx(position: Vector3, camera: Camera3D, width: number, height: number): Vector2;
    GetWorldToScreen2D(position: Vector2, camera: Camera2D): Vector2;
    GetScreenToWorld2D(position: Vector2, camera: Camera2D): Vector2;
    TraceLog(logType: number, text: string): void;
}
