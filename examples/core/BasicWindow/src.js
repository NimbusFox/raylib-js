import Raylib from "../../../bin/raylibWeb.js";
function loop() {
    Raylib.BeginDrawing();
    Raylib.ClearBackground({ r: 245, g: 245, b: 245, a: 255 });
    Raylib.DrawText("Congrats! You created your first window!", 190, 200, 20, { r: 200, g: 200, b: 200, a: 255 });
    Raylib.EndDrawing();
    setTimeout(loop);
}
Module.onRuntimeInitialized = function () {
    Raylib.InitWindow(800, 450);
    loop();
};
Raylib.init();
