import Raylib from "../../../bin/raylibWeb.js";

declare let Module: any;

function loop() {
    Raylib.raylibC.BeginDrawing();

    Raylib.raylibC.ClearBackground({ r: 245, g: 245, b: 245, a: 255 });

    (Raylib.raylibC as any).DrawText("Congrats! You created your first window!", 190, 200, 20, { r: 200, g: 200, b: 200, a: 255 })

    Raylib.raylibC.EndDrawing();

    setTimeout(loop);
}

Module.onRuntimeInitialized = function () {
    Raylib.raylibC.InitWindow(800, 450);
    loop();
}

Raylib.init();
