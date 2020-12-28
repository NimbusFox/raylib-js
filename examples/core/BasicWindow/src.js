function loop() {

    Module.BeginDrawing();

        Module.ClearBackground({ r: 245, g: 245, b: 245, a: 255 });

        Module.DrawText("Congrats! You created your first window!", 190, 200, 20, { r: 200, g: 200, b: 200, a: 255 })

    Module.EndDrawing();
}

Module.onRuntimeInitialized = function () {
    Module.SetLoop(loop);
    Module.InitWindow(800, 450);
}
