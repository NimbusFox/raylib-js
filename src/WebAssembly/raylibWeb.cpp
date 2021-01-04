#include <emscripten/bind.h>
#include <emscripten/emscripten.h>
#include <raylib.h>

emscripten::val _loop = emscripten::val("");

void Loop() {
    if (_loop.isString()) {
        return;
    }

    _loop();
}

void SetLoop(emscripten::val loop) {
    _loop = loop;
    emscripten_set_main_loop(Loop, 0, 0);
}

EMSCRIPTEN_BINDINGS(raylibWeb) {
    emscripten::function("SetLoop", &SetLoop, emscripten::allow_raw_pointers());
}
