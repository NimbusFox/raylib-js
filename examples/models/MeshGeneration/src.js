let models = [];
let texture;

let camera = { position: { x: 5.0, y: 5.0, z: 5.0 }, target: { x: 0.0, y: 0.0, z: 0.0 }, up: { x: 0.0, y: 1.0, z: 0.0 }, rotation: 45.0, zoom: 0, fovy: 90, type: 0 };

let position = { x: 0.0, y: 0.0, z: 0.0 };

let current = 0;

Module.onRuntimeInitialized = function () {
    Module.InitWindow(1920, 1080);

    let checked = Module.GenImageChecked(2, 2, 1, 1, { r: 255, g: 0, b: 0, a: 255 }, { r: 0, g: 255, b: 0, a: 255 });

    texture = Module.LoadTextureFromImage(checked);

    Module.UnloadImage(checked);

    models.push(Module.LoadModelFromMesh(Module.GenMeshPlane(2, 2, 5, 5)));
    models.push(Module.LoadModelFromMesh(Module.GenMeshCube(2.0, 1.0, 2.0)));
    models.push(Module.LoadModelFromMesh(Module.GenMeshSphere(2, 32, 32)));
    models.push(Module.LoadModelFromMesh(Module.GenMeshHemiSphere(2, 16, 16)));
    models.push(Module.LoadModelFromMesh(Module.GenMeshCylinder(1, 2, 16)));
    models.push(Module.LoadModelFromMesh(Module.GenMeshTorus(0.25, 4.0, 16, 32)));
    models.push(Module.LoadModelFromMesh(Module.GenMeshKnot(1.0, 2.0, 16, 128)));
    models.push(Module.LoadModelFromMesh(Module.GenMeshPoly(5, 2.0)));

    for (let i = 0; i < models.length; i++)  {
        Module.SetModelTexture(models[i], 0, 0, texture);
    }

    Module.SetCameraMode(camera, 2);

    loop();
}

function loop() {
    camera = Module.UpdateCamera(camera);

    if (Module.IsMouseButtonPressed(0)) {
        current = (current + 1) % models.length;
    }

    if (Module.IsKeyPressed(262)) {
        current++;

        if (current >= models.length) {
            current = 0;
        }
    } else if (Module.IsKeyPressed(263)) {
        current--;

        if (current < 0) {
            current = models.length - 1;
        }
    }

    Module.BeginDrawing();

        Module.ClearBackground({ r: 245, g: 245, b: 245, a: 255 });

        Module.BeginMode3D(camera);

            Module.DrawModel(models[current], position, 1.0, {r: 255, g: 255, b: 255, a: 255});

            Module.DrawGrid(10, 1.0);
        
        Module.EndMode3D();

        Module.DrawFPS(0, 0);

    Module.EndDrawing();

    setTimeout(loop);
}
