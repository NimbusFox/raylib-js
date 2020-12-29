#include "cacheDatabase.h"

unsigned int currentId = 1u;

std::map<unsigned int, Model> CacheDatabase::models = std::map<unsigned int, Model>();
std::map<unsigned int, Mesh> CacheDatabase::meshes = std::map<unsigned int, Mesh>();
std::map<unsigned int, Material> CacheDatabase::materials = std::map<unsigned int, Material>();

unsigned int CacheDatabase::AddModel(Model model) {
    models.insert({currentId, model});

    return currentId++;
}

unsigned int CacheDatabase::AddMesh(Mesh mesh) {
    meshes.insert({currentId, mesh});

    return currentId++;
}

unsigned int CacheDatabase::AddMaterial(Material material) {
    materials.insert({currentId, material});

    return currentId++;
}

Model& CacheDatabase::GetModel(unsigned int id) {
    return models[id];
}

Mesh& CacheDatabase::GetMesh(unsigned int id) {
    return meshes[id];
}

Material& CacheDatabase::GetMaterial(unsigned int id) {
    return materials[id];
}

void CacheDatabase::RemoveModel(unsigned int id) {
    UnloadModel(models[id]);
    models.erase(id);
}

void CacheDatabase::RemoveMesh(unsigned int id) {
    UnloadMesh(meshes[id]);
    meshes.erase(id);
}

void CacheDatabase::RemoveMaterial(unsigned int id) {
    UnloadMaterial(materials[id]);
    materials.erase(id);
}
