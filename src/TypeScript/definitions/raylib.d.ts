type IntPtr = number;

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

type Image = {
    data: number,
    width: number,
    height: number,
    mipmaps: number,
    format: number
};

type Texture = {
    id: number,
    width: number,
    height: number,
    mipmaps: number,
    format: number
};

type Texture2D = Texture;
type TextureCubemap = Texture;

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

type Rectangle = {
    x: number,
    y: number,
    width: number,
    height: number
};

type AnimImage = {
    image: Image,
    frames: number
};

type CharInfo = {
    value: number,
    offsetX: number,
    offsetY: number,
    advanceX: number,
    image: Image
};

type Font = {
    baseSize: number,
    charsCount: number,
    charsPadding: number,
    texture: Texture2D,
    recs: Array<Rectangle>,
    chars: Array<CharInfo>
};

type NPatchInfo = {
    source: Rectangle,
    left: number,
    top: number,
    right: number,
    bottom: number,
    type: Raylib.NPatchType
};

type Codepoint = {
    result: number,
    bytesProcessed: number
};

type BoundingBox = {
    min: Vector3,
    max: Vector3
};

type RayHitInfo = {
    hit: boolean,
    distance: number,
    position: Vector3,
    normal: Vector3
};

type Shader = {
    id: number,
    locs: Array<number>
};
