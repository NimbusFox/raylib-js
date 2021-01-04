#ifndef MODELCACHE
#define MODELCACHE

#include <map>
#include "raylib.h"

class CacheDatabase {
    private:
        static std::map<unsigned int, Model> models;
        static std::map<unsigned int, Mesh> meshes;
        static std::map<unsigned int, Material> materials;
    public:
        static unsigned int AddModel(Model model);
        static unsigned int AddMesh(Mesh mesh);
        static unsigned int AddMaterial(Material material);
        static Model& GetModel(unsigned int id);
        static Mesh& GetMesh(unsigned int id);
        static Material& GetMaterial(unsigned int id);
        static void RemoveModel(unsigned int id);
        static void RemoveMesh(unsigned int id);
        static void RemoveMaterial(unsigned int id);
};

#endif
