#include <emscripten/bind.h>
#include <emscripten/emscripten.h>
#include <raylib.h>
#include "cache/CacheDatabase.h"

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

unsigned int currentId = 1u;

std::map<unsigned int, Model> CacheDatabase::models = std::map<unsigned int, Model>();

unsigned int CacheDatabase::AddModel(Model model) {
    models.insert({currentId, model});

    return currentId++;
}

Model* CacheDatabase::GetModel(unsigned int id) {
    return &models[id];
}

void CacheDatabase::RemoveModel(unsigned int id) {
    UnloadModel(models[id]);
    models.erase(id);
}
