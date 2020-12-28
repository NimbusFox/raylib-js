#include <emscripten/bind.h>
#include <emscripten/emscripten.h>
#include <raylib.h>

#include "cache/ModelCacheDatabase.h"

// Bindings up to date with raylib 3.5
// https://www.raylib.com/cheatsheet/cheatsheet.html

void JSDrawLine3D(Vector3 startPos, Vector3 endPos, Color color) {
    DrawLine3D(startPos, endPos, color);
}

void JSDrawPoint3D(Vector3 position, Color color) {
    DrawPoint3D(position, color);
}

void JSDrawCircle3D(Vector3 center, float radius, Vector3 rotationAxis, float rotationAngle, Color color) {
    DrawCircle3D(center, radius, rotationAxis, rotationAngle, color);
}

void JSDrawTriangle3D(Vector3 v1, Vector3 v2, Vector3 v3, Color color) {
    DrawTriangle3D(v1, v2, v3, color);
}

void JSDrawTriangleStrip3D(std::vector<Vector3> points, Color color) {
    DrawTriangleStrip3D(points.data(), points.size(), color);
}

void JSDrawCube(Vector3 position, float width, float height, float length, Color color) {
    DrawCube(position, width, height, length, color);
}

void JSDrawCubeV(Vector3 position, Vector3 size, Color color) {
    DrawCubeV(position, size, color);
}

void JSDrawCubeWires(Vector3 position, float width, float height, float length, Color color) {
    DrawCubeWires(position, width, height, length, color);
}

void JSDrawCubeWiresV(Vector3 position, Vector3 size, Color color) {
    DrawCubeWiresV(position, size, color);
}

void JSDrawCubeTexture(Texture2D texture, Vector3 position, float width, float height, float length, Color color) {
    DrawCubeTexture(texture, position, width, height, length, color);
}

void JSDrawSphere(Vector3 centerPos, float radius, Color color) {
    DrawSphere(centerPos, radius, color);
}

void JSDrawSphereEx(Vector3 centerPos, float radius, int rings, int slices, Color color) {
    DrawSphereEx(centerPos, radius, rings, slices, color);
}

void JSDrawSphereWires(Vector3 centerPos, float radius, int rings, int slices, Color color) {
    DrawSphereWires(centerPos, radius, rings, slices, color);
}

void JSDrawCylinder(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color) {
    DrawCylinder(position, radiusTop, radiusBottom, height, slices, color);
}
void JSDrawCylinderWires(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color) {
    DrawCylinderWires(position, radiusTop, radiusBottom, height, slices, color);
}

void JSDrawPlane(Vector3 centerPos, Vector2 size, Color color) {
    DrawPlane(centerPos, size, color);
}

void JSDrawRay(Ray ray, Color color) {
    DrawRay(ray, color);
}

void JSDrawGrid(int slices, float spacing) {
    DrawGrid(slices, spacing);
}

void JSDrawGizmo(Vector3 position) {
    DrawGizmo(position);
}

unsigned int JSLoadModel(std::string fileName) {
    return ModelCacheDatabase::AddModel(LoadModel(fileName.c_str()));
}

unsigned int JSLoadModelFromMesh(Mesh mesh) {
    return ModelCacheDatabase::AddModel(LoadModelFromMesh(mesh));
}

void JSUnloadModel(Model model) {
    UnloadModel(model);
}

void JSUnloadModelKeepMeshes(Model model) {
    UnloadModelKeepMeshes(model);
}

std::vector<Mesh> JSLoadMeshes(std::string fileName) {
    auto output = std::vector<Mesh>();

    auto count = 0;

    auto data = LoadMeshes(fileName.c_str(), &count);

    for (auto i = 0; i < count; i++) {
        output.push_back(data[i]);
    }

    return output;
}

void JSUnloadMesh(Mesh mesh) {
    UnloadMesh(mesh);
}

std::vector<Material> JSLoadMaterials(std::string fileName) {
    auto output = std::vector<Material>();

    auto count = 0;

    auto data = LoadMaterials(fileName.c_str(), &count);

    for (auto i = 0; i < count; i++) {
        output.push_back(data[i]);
    }

    return output;
}

Material JSLoadMaterialDefault() {
    return LoadMaterialDefault();
}

void JSUnloadMaterial(Material material) {
    UnloadMaterial(material);
}

void JSSetMaterialTexture(Material *material, int mapType, Texture2D texture) {
    SetMaterialTexture(material, mapType, texture);
}

void JSSetModelMeshMaterial(Model *model, int meshId, int materialId) {
    SetModelMeshMaterial(model, meshId, materialId);
}

std::vector<ModelAnimation> JSLoadModelAnimations(std::string fileName) {
    auto output = std::vector<ModelAnimation>();

    auto count = 0;

    auto data = LoadModelAnimations(fileName.c_str(), &count);

    for (auto i = 0; i < count; i++) {
        output.push_back(data[i]);
    }

    return output;
}

void JSUpdateModelAnimation(Model model, ModelAnimation anim, int frame) {
    UpdateModelAnimation(model, anim, frame);
}

void JSUnloadModelAnimation(ModelAnimation anim) {
    UnloadModelAnimation(anim);
}

bool JSIsModelAnimationValid(Model model, ModelAnimation anim) {
    return IsModelAnimationValid(model, anim);
}

Mesh JSGenMeshPoly(int sides, float radius) {
    return GenMeshPoly(sides, radius);
}

Mesh JSGenMeshPlane(float width, float length, int resX, int resZ) {
    return GenMeshPlane(width, length, resX, resZ);
}

Mesh JSGenMeshCube(float width, float height, float length) {
    return GenMeshCube(width, height, length);
}

Mesh JSGenMeshSphere(float radius, int rings, int slices) {
    return GenMeshSphere(radius, rings, slices);
}

Mesh JSGenMeshHemiSphere(float radius, int rings, int slices) {
    return GenMeshHemiSphere(radius, rings, slices);
}

Mesh JSGenMeshCylinder(float radius, float height, int slices) {
    return GenMeshCylinder(radius, height, slices);
}

Mesh JSGenMeshTorus(float radius, float size, int radSeg, int sides) {
    return GenMeshTorus(radius, size, radSeg, sides);
}

Mesh JSGenMeshKnot(float radius, float size, int radSeg, int sides) {
    return GenMeshKnot(radius, size, radSeg, sides);
}

Mesh JSGenMeshHeightmap(Image heightmap, Vector3 size) {
    return GenMeshHeightmap(heightmap, size);
}

Mesh JSGenMeshCubicmap(Image cubicmap, Vector3 cubeSize) {
    return GenMeshCubicmap(cubicmap, cubeSize);
}

BoundingBox JSMeshBoundingBox(Mesh mesh) {
    return MeshBoundingBox(mesh);
}

void JSMeshTangents(Mesh *mesh) {
    MeshTangents(mesh);
}

void JSMeshBinormals(Mesh *mesh) {
    MeshBinormals(mesh);
}

void JSMeshNormalsSmooth(Mesh *mesh) {
    MeshNormalsSmooth(mesh);
}

void JSDrawModel(unsigned int model, Vector3 position, float scale, Color tint) {
    DrawModel(*ModelCacheDatabase::GetModel(model), position, scale, tint);
}

void JSDrawModelEx(unsigned int model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint) {
    DrawModelEx(*ModelCacheDatabase::GetModel(model), position, rotationAxis, rotationAngle, scale, tint);
}

void JSDrawModelWires(unsigned int model, Vector3 position, float scale, Color tint) {
    DrawModelWires(*ModelCacheDatabase::GetModel(model), position, scale, tint);
}

void JSDrawModelWiresEx(unsigned int model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint) {
    DrawModelWiresEx(*ModelCacheDatabase::GetModel(model), position, rotationAxis, rotationAngle, scale, tint);
}

void JSDrawBoundingBox(BoundingBox box, Color color) {
    DrawBoundingBox(box, color);
}

void JSDrawBillboard(Camera camera, Texture2D texture, Vector3 center, float size, Color tint) {
    DrawBillboard(camera, texture, center, size, tint);
}

void JSDrawBillboardRec(Camera camera, Texture2D texture, Rectangle source, Vector3 center, float size, Color tint) {
    DrawBillboardRec(camera, texture, source, center, size, tint);
}

bool JSCheckCollisionSpheres(Vector3 center1, float radius1, Vector3 center2, float radius2) {
    return CheckCollisionSpheres(center1, radius1, center2, radius2);
}

bool JSCheckCollisionBoxes(BoundingBox box1, BoundingBox box2) {
    return CheckCollisionBoxes(box1, box2);
}

bool JSCheckCollisionBoxSphere(BoundingBox box, Vector3 center, float radius) {
    return CheckCollisionBoxSphere(box, center, radius);
}

bool JSCheckCollisionRaySphere(Ray ray, Vector3 center, float radius) {
    return CheckCollisionRaySphere(ray, center, radius);
}

emscripten::val JSCheckCollisionRaySphereEx(Ray ray, Vector3 center, float radius) {
    Vector3 collision;
    if (CheckCollisionRaySphereEx(ray, center, radius, &collision)) {
        return emscripten::val(collision);
    }

    return emscripten::val(false);
}

bool JSCheckCollisionRayBox(Ray ray, BoundingBox box) {
    return CheckCollisionRayBox(ray, box);
}

RayHitInfo JSGetCollisionRayMesh(Ray ray, Mesh mesh, Matrix transform) {
    return GetCollisionRayMesh(ray, mesh, transform);
}

RayHitInfo JSGetCollisionRayModel(Ray ray, Model model) {
    return GetCollisionRayModel(ray, model);
}

RayHitInfo JSGetCollisionRayTriangle(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3) {
    return GetCollisionRayTriangle(ray, p1, p2, p3);
}

RayHitInfo JSGetCollisionRayGround(Ray ray, float groundHeight) {
    return GetCollisionRayGround(ray, groundHeight);
}

void SetModelTexture(unsigned int id, unsigned int materialIndex, unsigned int mapsIndex, Texture2D texture) {
    ModelCacheDatabase::GetModel(id)->materials[materialIndex].maps[mapsIndex].texture = texture;
}

EMSCRIPTEN_BINDINGS(raylibWebModels) {
    // Basic geometric 3D shapes drawing functions
    emscripten::function("DrawLine3D", &JSDrawLine3D);
    emscripten::function("DrawPoint3D", &JSDrawPoint3D);
    emscripten::function("DrawCircle3D", &JSDrawCircle3D);
    emscripten::function("DrawTriangle3D", &JSDrawTriangle3D);
    emscripten::function("DrawTriangleStrip3D", &JSDrawTriangleStrip3D);
    emscripten::function("DrawCube", &JSDrawCube);
    emscripten::function("DrawCubeV", &JSDrawCubeV);
    emscripten::function("DrawCubeWires", &JSDrawCubeWires);
    emscripten::function("DrawCubeWiresV", &JSDrawCubeWiresV);
    emscripten::function("DrawCubeTexture", &JSDrawCubeTexture);
    emscripten::function("DrawSphere", &JSDrawSphere);
    emscripten::function("DrawSpehereEx", &JSDrawSphereEx);
    emscripten::function("DrawSphereWires", &JSDrawSphereWires);
    emscripten::function("DrawCylinder", &JSDrawCylinder);
    emscripten::function("DrawCylinderWires", &JSDrawCylinderWires);
    emscripten::function("DrawPlane", &JSDrawPlane);
    emscripten::function("DrawRay", &JSDrawRay);
    emscripten::function("DrawGrid", &JSDrawGrid);
    emscripten::function("DrawGizmo", &JSDrawGizmo);

    // Model loading/unloading functions
    emscripten::function("LoadModel", &JSLoadModel);
    emscripten::function("LoadModelFromMesh", &JSLoadModelFromMesh);
    emscripten::function("UnloadModel", &JSUnloadModel);
    emscripten::function("UnloadModelKeepMeshes", &JSUnloadModelKeepMeshes);

    // Mesh loading/unloading functions
    emscripten::function("LoadMeshes", &JSLoadMeshes);
    emscripten::function("UnloadMesh", &JSUnloadMesh);
    //emscripten::function("ExportMesh", &ExportMesh);

    // Material loading/unloading functions
    emscripten::function("LoadMaterials", &JSLoadMaterials);
    emscripten::function("LoadMaterialDefault", &JSLoadMaterialDefault);
    emscripten::function("UnloadMaterial", &JSUnloadMaterial);
    emscripten::function("SetMaterialTexture", &JSSetMaterialTexture, emscripten::allow_raw_pointer<Material>());
    emscripten::function("SetModelMeshMaterial", &JSSetModelMeshMaterial, emscripten::allow_raw_pointer<Model>());

    // Model animations loading/unloading functions
    emscripten::function("LoadModelAnimation", &JSLoadModelAnimations);
    emscripten::function("UpdateModelAnimation", &JSUpdateModelAnimation);
    emscripten::function("UnloadModelAnimation", &JSUnloadModelAnimation);
    emscripten::function("IsModelAnimationValid", &JSIsModelAnimationValid);

    // Mesh generation functions
    emscripten::function("GenMeshPoly", &JSGenMeshPoly);
    emscripten::function("GenMeshPlane", &JSGenMeshPlane);
    emscripten::function("GenMeshCube", &JSGenMeshCube);
    emscripten::function("GenMeshSphere", &JSGenMeshSphere);
    emscripten::function("GenMeshHemiSphere", &JSGenMeshHemiSphere);
    emscripten::function("GenMeshCylinder", &JSGenMeshCylinder);
    emscripten::function("GenMeshTorus", &JSGenMeshTorus);
    emscripten::function("GenMeshKnot", &JSGenMeshKnot);
    emscripten::function("GenMeshHeightmap", &JSGenMeshHeightmap);
    emscripten::function("GenMeshCubicmap", &JSGenMeshCubicmap);

    // Mesh manipulation functions
    emscripten::function("MeshBoundingBox", &JSMeshBoundingBox);
    emscripten::function("MeshTangents", &JSMeshTangents, emscripten::allow_raw_pointer<Mesh>());
    emscripten::function("MeshBinormals", &JSMeshBinormals, emscripten::allow_raw_pointer<Mesh>());
    emscripten::function("MeshNormalsSmooth", &JSMeshNormalsSmooth, emscripten::allow_raw_pointer<Mesh>());

    // Model drawing functions
    emscripten::function("DrawModel", &JSDrawModel);
    emscripten::function("DrawModelEx", &JSDrawModelEx);
    emscripten::function("DrawModelWires", &JSDrawModelWires);
    emscripten::function("DrawModelWiresEx", &JSDrawModelWiresEx);
    emscripten::function("DrawBoundingBox", &JSDrawBoundingBox);
    emscripten::function("DrawBillboard", &JSDrawBillboard);
    emscripten::function("DrawBillboardRec", &JSDrawBillboardRec);

    // Collision detection functions
    emscripten::function("CheckCollisionSpheres", &JSCheckCollisionSpheres);
    emscripten::function("CheckCollisionBoxes", &JSCheckCollisionBoxes);
    emscripten::function("CheckCollisionBoxSphere", &JSCheckCollisionBoxSphere);
    emscripten::function("CheckCollisionRaySphere", &JSCheckCollisionRaySphere);
    emscripten::function("CheckCollisionRaySphereEx", &JSCheckCollisionRaySphereEx);
    emscripten::function("CheckCollisionRayBox", &JSCheckCollisionRayBox);
    emscripten::function("GetCollisionRayMesh", &JSGetCollisionRayMesh);
    emscripten::function("GetCollisionRayModel", &JSGetCollisionRayModel);
    emscripten::function("GetCollisionRayTriangle", &JSGetCollisionRayTriangle);
    emscripten::function("GetCollisionRayGround", &JSGetCollisionRayGround);

    // raylib-web functions
    emscripten::function("SetModelTexture", &SetModelTexture);
}
