import Raylib from "./raylibWeb.js";

class PointerClass {
    public pointer: IntPtr;
    protected unloadFirst: boolean;
    protected unloaded: boolean;

    constructor(needsUnloading: boolean) {
        this.pointer = 0;
        this.unloadFirst = needsUnloading;
        this.unloaded = false;
    }

    public dispose(): void {
        if (this.unloadFirst && !this.unloaded) {
            throw Error("You must unload first before disposing");
        }
        Raylib.raylibC.Dispose(this.pointer);
    }
}

export class Vector2 extends PointerClass {
    constructor(x: number, y: number, sub: boolean = false) {
        super(false);
        if (!sub) {
            this.pointer = Raylib.raylibC.CreateVector2(x, y);
        }
    }

    public set x(value: number) {
        Raylib.raylibC.Vector2SetX(this.pointer, value);
    }

    public get x() {
        return Raylib.raylibC.Vector2GetX(this.pointer);
    }

    public set y(value: number) {
        Raylib.raylibC.Vector2SetY(this.pointer, value);
    }

    public get y() {
        return Raylib.raylibC.Vector2GetY(this.pointer);
    }
}

export class Vector3 extends PointerClass {
    constructor(x: number, y: number, z: number, sub: boolean = false) {
        super(false);
        if (!sub) {
            this.pointer = Raylib.raylibC.CreateVector3(x, y, z);
        }
    }

    public set x(value: number) {
        Raylib.raylibC.Vector3SetX(this.pointer, value);
    }

    public get x() {
        return Raylib.raylibC.Vector3GetX(this.pointer);
    }

    public set y(value: number) {
        Raylib.raylibC.Vector3SetY(this.pointer, value);
    }

    public get y() {
        return Raylib.raylibC.Vector3GetY(this.pointer);
    }

    public set z(value: number) {
        Raylib.raylibC.Vector3SetZ(this.pointer, value);
    }

    public get z() {
        return Raylib.raylibC.Vector3GetZ(this.pointer);
    }
}

export class Camera3D extends PointerClass {
    public readonly position: Vector3;
    public readonly target: Vector3;
    public readonly up: Vector3;

    constructor() {
        super(false);

        this.pointer = Raylib.raylibC.CreateCamera3D();

        this.position = new Vector3(0, 0, 0, true);
        this.position.pointer = Raylib.raylibC.GetCamera3DPosition(this.pointer);

        this.target = new Vector3(0, 0, 0,  true);
        this.target.pointer = Raylib.raylibC.GetCamera3DTarget(this.pointer);

        this.up = new Vector3(0, 0, 0,  true);
        this.up.pointer = Raylib.raylibC.GetCamera3DUp(this.pointer);;
    }

    public set fovy(value: number) {
        Raylib.raylibC.Camera3DSetFovy(this.pointer, value);
    }

    public get fovy() {
        return Raylib.raylibC.Camera3DGetFovy(this.pointer);
    }

    public get type() {
        return Raylib.raylibC.Camera3DGetType(this.pointer);
    }
}
