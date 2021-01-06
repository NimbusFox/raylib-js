import Raylib from "../../../bin/raylibWeb.js";
let models = [];
let texture;
let camera;
let position = { x: 0.0, y: 0.0, z: 0.0 };
let current = 0;
Module.onRuntimeInitialized = function () {
    Raylib.SetConfigFlags(Raylib.WindowFlag.FLAG_VSYNC_HINT);
    Raylib.InitWindow(1920, 1080);
    camera = new Raylib.Camera3D();
    camera.position.x = 5.0;
    camera.position.y = 5.0;
    camera.position.z = 5.0;
    camera.target.x = 0.0;
    camera.target.y = 0.0;
    camera.target.z = 0.0;
    camera.up.x = 0.0;
    camera.up.y = 1.0;
    camera.up.z = 0.0;
    camera.fovy = 90;
    let checked = Raylib.GenImageChecked(2, 2, 1, 1, { r: 255, g: 0, b: 0, a: 255 }, { r: 0, g: 255, b: 0, a: 255 });
    texture = Raylib.LoadTextureFromImage(checked);
    Raylib.UnloadImage(checked);
    models.push(Raylib.LoadModelFromMesh(Raylib.GenMeshPlane(2, 2, 5, 5)));
    models.push(Raylib.LoadModelFromMesh(Raylib.GenMeshCube(2.0, 1.0, 2.0)));
    models.push(Raylib.LoadModelFromMesh(Raylib.GenMeshSphere(2, 32, 32)));
    models.push(Raylib.LoadModelFromMesh(Raylib.GenMeshHemiSphere(2, 16, 16)));
    models.push(Raylib.LoadModelFromMesh(Raylib.GenMeshCylinder(1, 2, 16)));
    models.push(Raylib.LoadModelFromMesh(Raylib.GenMeshTorus(0.25, 4.0, 16, 32)));
    models.push(Raylib.LoadModelFromMesh(Raylib.GenMeshKnot(1.0, 2.0, 16, 128)));
    models.push(Raylib.LoadModelFromMesh(Raylib.GenMeshPoly(5, 2.0)));
    for (let i = 0; i < models.length; i++) {
        Raylib.SetModelTexture(models[i], 0, 0, texture);
    }
    Raylib.SetCameraMode(camera, 2);
    loop();
};
function loop() {
    Raylib.UpdateCamera(camera);
    if (Raylib.IsMouseButtonPressed(0)) {
        current = (current + 1) % models.length;
    }
    if (Raylib.IsKeyPressed(262)) {
        current++;
        if (current >= models.length) {
            current = 0;
        }
    }
    else if (Raylib.IsKeyPressed(263)) {
        current--;
        if (current < 0) {
            current = models.length - 1;
        }
    }
    Raylib.BeginDrawing();
    Raylib.ClearBackground({ r: 245, g: 245, b: 245, a: 255 });
    Raylib.BeginMode3D(camera);
    Raylib.DrawModel(models[current], position, 1.0, { r: 255, g: 255, b: 255, a: 255 });
    Raylib.DrawGrid(10, 1.0);
    Raylib.EndMode3D();
    Raylib.DrawFPS(0, 0);
    Raylib.EndDrawing();
    setTimeout(loop);
}
Raylib.init();
