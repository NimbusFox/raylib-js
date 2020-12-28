#ifndef MODELCACHE
#define MODELCACHE

#include <map>
#include "raylib.h"

class ModelCacheDatabase {
    private:
        static std::map<unsigned int, Model> models;
    public:
        static unsigned int AddModel(Model model);
        static Model* GetModel(unsigned int id);
        static void RemoveModel(unsigned int id);
};

#endif
