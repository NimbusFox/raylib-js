#include <config.h>
#include <emscripten/bind.h>
#include <emscripten/emscripten.h>
#include <raylib.h>

#include "JSAnimImage.h"
#include "JSCodepoint.h"

// Bindings up to date with raylib 3.5
// https://www.raylib.com/cheatsheet/cheatsheet.html

#pragma region GettersSetters

#pragma region Font
std::vector<Rectangle> FontRecsGetter(const Font& font) {
    auto recs = std::vector<Rectangle>();

    for (auto i = 0; i < font.charsCount; i++) {
        recs.push_back(font.recs[i]);
    }

    return recs;
}

void FontRecsSetter(Font& font, std::vector<Rectangle> recs) {
    for (auto i = 0; i < recs.size() || i < font.charsCount; i++) {
        font.recs[i] = recs[i];
    }
}

std::vector<CharInfo> FontCharsGetter(const Font& font) {
    auto chars = std::vector<CharInfo>();

    for (auto i = 0; i < font.charsCount; i++) {
        chars.push_back(font.chars[i]);
    }

    return chars;
}

void FontCharsSetter(Font& font, std::vector<CharInfo> chars) {
    for (auto i = 0; i < chars.size() || i < font.charsCount; i++) {
        font.chars[i] = chars[i];
    }
}
#pragma endregion
#pragma region Image

intptr_t ImageDataGetter(const Image& image) {
    return reinterpret_cast<intptr_t>(image.data);
}

void ImageDataSetter(Image& image, intptr_t val) {
    image.data = reinterpret_cast<void*>(val);
}

#pragma endregion
#pragma region Mesh

std::vector<float> MeshVerticesGetter(const Mesh& mesh) {
    auto output = std::vector<float>();

    for (auto i = 0; i < mesh.vertexCount * 3; i++) {
        output.push_back(mesh.vertices[i]);
    }

    return output;
}

void MeshVerticesSetter(Mesh& mesh, std::vector<float> vertices) {
    if (vertices.size() != mesh.vertexCount * 3) {
        return;
    }

    mesh.vertices = vertices.data();
}

std::vector<float> MeshTexcoordsGetter(const Mesh& mesh) {
    auto output = std::vector<float>();

    for (auto i = 0; i < mesh.vertexCount * 2; i++) {
        output.push_back(mesh.texcoords[i]);
    }

    return output;
}

void MeshTexcoordsSetter(Mesh& mesh, std::vector<float> texcoords) {
    if (texcoords.size() != mesh.vertexCount * 2) {
        return;
    }

    mesh.texcoords = texcoords.data();
}

std::vector<float> MeshTexcoords2Getter(const Mesh& mesh) {
    auto output = std::vector<float>();

    for (auto i = 0; i < mesh.vertexCount * 2; i++) {
        output.push_back(mesh.texcoords2[i]);
    }

    return output;
}

void MeshTexcoords2Setter(Mesh& mesh, std::vector<float> texcoords2) {
    if (texcoords2.size() != mesh.vertexCount * 2) {
        return;
    }

    mesh.texcoords2 = texcoords2.data();
}

std::vector<float> MeshNormalsGetter(const Mesh& mesh) {
    auto output = std::vector<float>();

    for (auto i = 0; i < mesh.vertexCount * 3; i++) {
        output.push_back(mesh.normals[i]);
    }

    return output;
}

void MeshNormalsSetter(Mesh& mesh, std::vector<float> normals) {
    if (normals.size() != mesh.vertexCount * 3) {
        return;
    }

    mesh.normals = normals.data();
}

std::vector<float> MeshTangentsGetter(const Mesh& mesh) {
    auto output = std::vector<float>();

    for (auto i = 0; i < mesh.vertexCount * 4; i++) {
        output.push_back(mesh.tangents[i]);
    }

    return output;
}

void MeshTangentsSetter(Mesh& mesh, std::vector<float> tangents) {
    if (tangents.size() != mesh.vertexCount * 4) {
        return;
    }

    mesh.tangents = tangents.data();
}

std::vector<unsigned char> MeshColorsGetter(const Mesh& mesh) {
    auto output = std::vector<unsigned char>();

    for (auto i = 0; i < mesh.vertexCount * 4; i++) {
        output.push_back(mesh.colors[i]);
    }

    return output;
}

void MeshColorsSetter(Mesh& mesh, std::vector<unsigned char> colors) {
    if (colors.size() != mesh.vertexCount * 4) {
        return;
    }

    mesh.colors = colors.data();
}

std::vector<unsigned short> MeshIndiciesGetter(const Mesh& mesh) {
    auto output = std::vector<unsigned short>();

    for (auto i = 0; i < mesh.vertexCount; i++) {
        output.push_back(mesh.indices[i]);
    }

    return output;
}

void MeshIndiciesSetter(Mesh& mesh, std::vector<unsigned short> indicies) {
    if (indicies.size() != mesh.vertexCount) {
        return;
    }

    mesh.indices = indicies.data();
}

std::vector<float> MeshAnimVerticesGetter(const Mesh& mesh) {
    auto output = std::vector<float>();

    for (auto i = 0; i < mesh.vertexCount * 3; i++) {
        output.push_back(mesh.animVertices[i]);
    }

    return output;
}

void MeshAnimVerticesSetter(Mesh& mesh, std::vector<float> animVertices) {
    if (animVertices.size() != mesh.vertexCount * 3) {
        return;
    }

    mesh.animVertices = animVertices.data();
}

std::vector<float> MeshAnimNormalsGetter(const Mesh& mesh) {
    auto output = std::vector<float>();

    for (auto i = 0; i < mesh.vertexCount * 3; i++) {
        output.push_back(mesh.animNormals[i]);
    }

    return output;
}

void MeshAnimNormalsSetter(Mesh& mesh, std::vector<float> animNormals) {
    if (animNormals.size() != mesh.vertexCount * 3) {
        return;
    }

    mesh.animNormals = animNormals.data();
}

std::vector<int> MeshBoneIdsGetter(const Mesh& mesh) {
    auto output = std::vector<int>();

    for (auto i = 0; i < mesh.vertexCount * 4; i++) {
        output.push_back(mesh.boneIds[i]);
    }

    return output;
}

void MeshBoneIdsSetter(Mesh& mesh, std::vector<int> boneIds) {
    if (boneIds.size() != mesh.vertexCount * 4) {
        return;
    }

    mesh.boneIds = boneIds.data();
}

std::vector<float> MeshBoneWeightsGetter(const Mesh& mesh) {
    auto output = std::vector<float>();

    for (auto i = 0; i < mesh.vertexCount * 4; i++) {
        output.push_back(mesh.boneWeights[i]);
    }

    return output;
}

void MeshBoneWeightsSetter(Mesh& mesh, std::vector<float> boneWeights) {
    if (boneWeights.size() != mesh.vertexCount * 4) {
        return;
    }

    mesh.boneWeights = boneWeights.data();
}

std::vector<unsigned int> MeshVboIdGetter(const Mesh& mesh) {
    auto output = std::vector<unsigned int>();

    for (auto i = 0; i < mesh.vertexCount; i++) {
        output.push_back(mesh.vboId[i]);
    }

    return output;
}

void MeshVboIdSetter(Mesh& mesh, std::vector<unsigned int> vboId) {
    if (vboId.size() != mesh.vertexCount) {
        return;
    }

    mesh.vboId = vboId.data();
}

#pragma endregion
#pragma region Material

emscripten::val MaterialMapsGetter(const Material& material) {
    auto output = std::vector<MaterialMap>();

    for (auto i = 0; i < MAX_MATERIAL_MAPS; i++) {
        output.push_back(material.maps[i]);
    }

    return emscripten::val::array(output);
}

void MaterialMapsSetter(Material& material, emscripten::val maps) {
    auto count = 0;
    auto mats = std::vector<MaterialMap>();
    while (!maps[count].isUndefined()) {
        mats.push_back(maps[count].as<MaterialMap>());
        count++;
    }

    material.maps = mats.data();
}

emscripten::val MaterialParamsGetter(const Material& material) {
    auto output = std::vector<float>();

    for (auto i = 0; i < *(&material.params + 1) - material.params; i++) {
        output.push_back(material.params[i]);
    }

    return emscripten::val::array(output);
}

void MaterialParamsSetter(Material& material, emscripten::val params) {
    auto count = 0;
    auto param = std::vector<float>();

    while (!params[count].isUndefined()) {
        param.push_back(params[count].as<float>());
        count++;
    }

    material.params = param.data();
}
#pragma endregion
#pragma region Shader
emscripten::val ShaderIdGetter(const Shader& shader) {
    return emscripten::val(shader.id);
}

void ShaderIdSetter(Shader& shader, emscripten::val id) {
    shader.id = id.as<unsigned int>();
}

std::vector<int> ShaderLocsGetter(const Shader& shader) {
    auto output = std::vector<int>();

    for (auto i = 0; i < MAX_SHADER_LOCATIONS; i++) {
        output.push_back(shader.locs[i]);
    }

    return output;
}

void ShaderLocsSetter(Shader& shader, std::vector<int> locs) {
    if (locs.size() != MAX_SHADER_LOCATIONS) {
        return;
    }

    shader.locs = locs.data();
}
#pragma endregion
#pragma region BoneInfo
std::string BoneInfoNameGetter(const BoneInfo& boneInfo) {
    return boneInfo.name;
}

void BoneInfoNameSetter(BoneInfo& boneInfo, std::string name) {
    if (name.size() > 32) {
        return;
    }

    memset(boneInfo.name, 0, 32);

    for (auto i = 0; i < name.size(); i++) {
        boneInfo.name[i] = name[i];
    }
}
#pragma endregion
#pragma region Model
std::vector<Mesh> ModelMeshesGetter(const Model& model) {
    auto output = std::vector<Mesh>();

    for (auto i = 0; i < model.meshCount; i++) {
        output.push_back(model.meshes[i]);
    }

    return output;
}

void ModelMeshesSetter(Model& model, std::vector<Mesh> meshes) {
    model.meshCount = meshes.size();

    model.meshes = meshes.data();
}

emscripten::val ModelMaterialsGetter(const Model& model) {
    auto output = std::vector<Material>();

    for (auto i = 0; i < model.materialCount; i++) {
        output.push_back(model.materials[i]);
    }

    return emscripten::val::array(output);
}

void ModelMaterialsSetter(Model& model, emscripten::val materials) {
    auto count = 0;
    auto mats = std::vector<Material>();
    while (!materials[count].isUndefined()) {
        mats.push_back(materials[count].as<Material>());
        count++;
    }

    model.materialCount = count;

    model.materials = mats.data();
}

emscripten::val ModelMeshMaterialGetter(const Model& model) {
    auto output = std::vector<int>();

    for (auto i = 0; i < model.meshCount; i++) {
        output.push_back(model.meshMaterial[i]);
    }

    return emscripten::val::array(output);
}

void ModelMeshMaterialSetter(Model& model, emscripten::val meshMaterial) {
    auto count = 0;
    auto mats = std::vector<int>();
    while (!meshMaterial[count].isUndefined()) {
        mats.push_back(meshMaterial[count].as<int>());
        count++;
    }

    model.meshMaterial = mats.data();
}

std::vector<BoneInfo> ModelBonesGetter(const Model& model) {
    auto output = std::vector<BoneInfo>();

    for (auto i = 0; i < model.boneCount; i++) {
        output.push_back(model.bones[i]);
    }

    return output;
}

void ModelBonesSetter(Model& model, std::vector<BoneInfo> bones) {
    model.boneCount = bones.size();

    model.bones = bones.data();
}

std::vector<Transform> ModelBindPoseGetter(const Model& model) {
    auto output = std::vector<Transform>();

    for (auto i = 0; i < model.boneCount; i++) {
        output.push_back(model.bindPose[i]);
    }

    return output;
}

void ModelBindPoseSetter(Model& model, std::vector<Transform> bindPose) {
    if (bindPose.size() > model.boneCount) {
        return;
    }

    model.bindPose = bindPose.data();
}
#pragma endregion
#pragma region ModelAnimation
std::vector<BoneInfo> ModelAnimationBonesGetter(const ModelAnimation& modelAnimation) {
    auto output = std::vector<BoneInfo>();

    for (auto i = 0; i < modelAnimation.boneCount; i++) {
        output.push_back(modelAnimation.bones[i]);
    }

    return output;
}

void ModelAnimationBonesSetter(ModelAnimation& modelAnimation, std::vector<BoneInfo> bones) {
    modelAnimation.boneCount = bones.size();

    modelAnimation.bones = bones.data();
}

std::vector<std::vector<Transform>> ModelAnimationFramePosesGetter(const ModelAnimation& modelAnimation) {
    auto output = std::vector<std::vector<Transform>>();

    for (auto i = 0; i < modelAnimation.frameCount; i++) {
        output.push_back(std::vector<Transform>());

        for (auto j = 0; j < modelAnimation.boneCount; j++) {
            output[i].push_back(modelAnimation.framePoses[i][j]);
        }
    }

    return output;
}

void ModelAnimationFramePosesSetter(ModelAnimation& modelAnimation, std::vector<std::vector<Transform>> framePoses) {
    modelAnimation.frameCount = framePoses.size();

    modelAnimation.framePoses = new Transform*[modelAnimation.frameCount];

    for (auto i = 0; i < framePoses.size(); i++) {
        modelAnimation.framePoses[i] = new Transform[framePoses[i].size()];

        for (auto j = 0; j < framePoses[i].size(); i++) {
            modelAnimation.framePoses[i][j] = framePoses[i][j];
        }
    }
}
#pragma endregion
#pragma region VrDeviceInfo
std::vector<float> VrDeviceInfoLensDistortionValuesGetter(const VrDeviceInfo& vrDeviceInfo) {
    auto output = std::vector<float>();

    output.push_back(vrDeviceInfo.lensDistortionValues[0]);
    output.push_back(vrDeviceInfo.lensDistortionValues[1]);
    output.push_back(vrDeviceInfo.lensDistortionValues[2]);
    output.push_back(vrDeviceInfo.lensDistortionValues[3]);

    return output;
}

void VrDeviceInfoLensDistortionValuesSetter(const VrDeviceInfo& vrDeviceInfo, std::vector<float> lensDistortionValues) {
    return;
}

std::vector<float> VrDeviceInfoChromaAbCorrectionGetter(const VrDeviceInfo& vrDeviceInfo) {
    auto output = std::vector<float>();

    output.push_back(vrDeviceInfo.chromaAbCorrection[0]);
    output.push_back(vrDeviceInfo.chromaAbCorrection[1]);
    output.push_back(vrDeviceInfo.chromaAbCorrection[2]);
    output.push_back(vrDeviceInfo.chromaAbCorrection[3]);

    return output;
}

void VrDeviceInfoChromaAbCorrectionSetter(const VrDeviceInfo& vrDeviceInfo, std::vector<float> chromaAbCorrection) {
    return;
}
#pragma endregion
#pragma endregion

EMSCRIPTEN_BINDINGS(raylibWebStructs) {
    emscripten::value_object<Color>("Color")
        .field("r", &Color::r)
        .field("g", &Color::g)
        .field("b", &Color::b)
        .field("a", &Color::a);

    emscripten::value_object<Vector2>("Vector2")
        .field("x", &Vector2::x)
        .field("y", &Vector2::y);

    emscripten::value_object<Vector3>("Vector3")
        .field("x", &Vector3::x)
        .field("y", &Vector3::y)
        .field("z", &Vector3::z);

    emscripten::value_object<Camera2D>("Camera2D")
        .field("offset", &Camera2D::offset)
        .field("target", &Camera2D::target)
        .field("rotation", &Camera2D::rotation)
        .field("zoom", &Camera2D::zoom);

    emscripten::value_object<Camera3D>("Camera3D")
        .field("position", &Camera3D::position)
        .field("target", &Camera3D::target)
        .field("up", &Camera3D::up)
        .field("fovy", &Camera3D::fovy)
        .field("type", &Camera3D::type);

    emscripten::value_object<Texture2D>("Texture2D")
        .field("id", &Texture2D::id)
        .field("width", &Texture2D::width)
        .field("height", &Texture2D::height)
        .field("mipmaps", &Texture2D::mipmaps)
        .field("format", &Texture2D::format);

    emscripten::value_object<RenderTexture2D>("RenderTexture2D")
        .field("id", &RenderTexture2D::id)
        .field("texture", &RenderTexture2D::texture)
        .field("depth", &RenderTexture2D::texture);

    emscripten::value_object<Ray>("Ray")
        .field("position", &Ray::position)
        .field("direction", &Ray::direction);

    emscripten::value_object<Matrix>("Matrix")
        .field("m0", &Matrix::m0)
        .field("m4", &Matrix::m4)
        .field("m8", &Matrix::m8)
        .field("m12", &Matrix::m12)
        .field("m1", &Matrix::m1)
        .field("m5", &Matrix::m5)
        .field("m9", &Matrix::m9)
        .field("m13", &Matrix::m13)
        .field("m2", &Matrix::m2)
        .field("m6", &Matrix::m6)
        .field("m10", &Matrix::m10)
        .field("m14", &Matrix::m14)
        .field("m3", &Matrix::m3)
        .field("m7", &Matrix::m7)
        .field("m11", &Matrix::m11)
        .field("m15", &Matrix::m15);

    emscripten::value_object<Rectangle>("Rectangle")
        .field("x", &Rectangle::x)
        .field("y", &Rectangle::y)
        .field("width", &Rectangle::width)
        .field("height", &Rectangle::height);

    emscripten::value_object<Image>("Image")
        .field("data", &ImageDataGetter, &ImageDataSetter)
        .field("width", &Image::width)
        .field("height", &Image::height)
        .field("mipmaps", &Image::mipmaps)
        .field("format", &Image::format);

    emscripten::value_object<Font>("Font")
        .field("baseSize", &Font::baseSize)
        .field("charsCount", &Font::charsCount)
        .field("charsPadding", &Font::charsPadding)
        .field("texture", &Font::texture)
        .field("Rectangle", &FontRecsGetter, &FontRecsSetter)
        .field("chars", &FontCharsGetter, &FontCharsSetter);

    emscripten::value_object<JSAnimImage>("AnimImage")
        .field("image", &JSAnimImage::image)
        .field("frames", &JSAnimImage::frames);

    emscripten::value_object<JSCodepoint>("Codepoint")
        .field("result", &JSCodepoint::result)
        .field("bytesProcessed", &JSCodepoint::bytesProcessed);

    emscripten::value_object<NPatchInfo>("NPatchInfo")
        .field("source", &NPatchInfo::source)
        .field("left", &NPatchInfo::left)
        .field("top", &NPatchInfo::top)
        .field("right", &NPatchInfo::right)
        .field("bottom", &NPatchInfo::bottom)
        .field("type", &NPatchInfo::type);

    emscripten::value_object<Mesh>("Mesh")
        .field("vertexCount", &Mesh::vertexCount)
        .field("triangleCount", &Mesh::triangleCount)
        .field("vertices", &MeshVerticesGetter, &MeshVerticesSetter)
        .field("texcoords", &MeshTexcoordsGetter, &MeshTexcoordsSetter)
        .field("texcoords2", &MeshTexcoords2Getter, &MeshTexcoords2Setter)
        .field("normals", &MeshNormalsGetter, &MeshNormalsSetter)
        .field("tangents", &MeshTangentsGetter, &MeshTangentsSetter)
        .field("colors", &MeshColorsGetter, &MeshColorsSetter)
        .field("indices", &MeshIndiciesGetter, &MeshIndiciesSetter)
        .field("animVerticies", &MeshAnimVerticesGetter, &MeshAnimVerticesSetter)
        .field("animNormals", &MeshAnimNormalsGetter, &MeshAnimNormalsSetter)
        .field("boneIds", &MeshBoneIdsGetter, &MeshBoneIdsSetter)
        .field("boneWeights", &MeshBoneWeightsGetter, &MeshBoneWeightsSetter)
        .field("vaoId", &Mesh::vaoId)
        .field("vboId", &MeshVboIdGetter, &MeshVboIdSetter);

    emscripten::value_object<Material>("Material")
        .field("shader", &Material::shader)
        .field("maps", &MaterialMapsGetter, &MaterialMapsSetter)
        .field("params", &MaterialParamsGetter, &MaterialParamsSetter);

    emscripten::value_object<MaterialMap>("MaterialMap")
        .field("texture", &MaterialMap::texture)
        .field("color", &MaterialMap::color)
        .field("value", &MaterialMap::value);

    emscripten::value_object<Shader>("Shader")
        .field("id", &ShaderIdGetter, &ShaderIdSetter)
        .field("locs", &ShaderLocsGetter, &ShaderLocsSetter);

    emscripten::value_object<BoneInfo>("BoneInfo")
        .field("name", &BoneInfoNameGetter, &BoneInfoNameSetter)
        .field("parent", &BoneInfo::parent);

    emscripten::value_object<Transform>("Transform")
        .field("translation", &Transform::translation)
        .field("rotation", &Transform::rotation)
        .field("scale", &Transform::scale);

    emscripten::value_object<Model>("Model")
        .field("transform", &Model::transform)
        .field("meshCount", &Model::meshCount)
        .field("materialCount", &Model::materialCount)
        .field("meshes", &ModelMeshesGetter, &ModelMeshesSetter)
        .field("materials", &ModelMaterialsGetter, &ModelMaterialsSetter)
        .field("meshMaterial", &ModelMeshMaterialGetter, &ModelMeshMaterialSetter)
        .field("boneCount", &Model::boneCount)
        .field("bones", &ModelBonesGetter, &ModelBonesSetter)
        .field("bindPose", &ModelBindPoseGetter, &ModelBindPoseSetter);

    emscripten::value_object<BoundingBox>("BoundingBox")
        .field("min", &BoundingBox::min)
        .field("max", &BoundingBox::max);

    emscripten::value_object<ModelAnimation>("ModelAnimation")
        .field("boneCount", &ModelAnimation::boneCount)
        .field("frameCount", &ModelAnimation::frameCount)
        .field("bones", &ModelAnimationBonesGetter, &ModelAnimationBonesSetter)
        .field("framePoses", &ModelAnimationFramePosesGetter, &ModelAnimationFramePosesSetter);

    emscripten::value_object<RayHitInfo>("RayHitInfo")
        .field("hit", &RayHitInfo::hit)
        .field("distance", &RayHitInfo::distance)
        .field("position", &RayHitInfo::position)
        .field("normal", &RayHitInfo::normal);

    emscripten::value_object<VrDeviceInfo>("VRDeviceInfo")
        .field("hResolution", &VrDeviceInfo::hResolution)
        .field("vResolution", &VrDeviceInfo::vResolution)
        .field("hScreenSize", &VrDeviceInfo::hScreenSize)
        .field("vScreenSize", &VrDeviceInfo::vScreenSize)
        .field("vScreenCenter", &VrDeviceInfo::vScreenCenter)
        .field("eyeToScreenDistance", &VrDeviceInfo::eyeToScreenDistance)
        .field("lensSeparationDistance", &VrDeviceInfo::lensSeparationDistance)
        .field("interpupillaryDistance", &VrDeviceInfo::interpupillaryDistance)
        .field("lensDistortionValues", &VrDeviceInfoLensDistortionValuesGetter, &VrDeviceInfoLensDistortionValuesSetter)
        .field("chromaAbCorrection", &VrDeviceInfoChromaAbCorrectionGetter, &VrDeviceInfoChromaAbCorrectionSetter);

    emscripten::register_vector<int>("vector<int>");
    emscripten::register_vector<unsigned char>("vector<unsigned char>");
    emscripten::register_vector<float>("vector<float>");
    emscripten::register_vector<unsigned short>("vector<unsigned short>");
    emscripten::register_vector<unsigned int>("vector<unsigned int>");

    emscripten::register_vector<Vector2>("vector<Vector2>");
    emscripten::register_vector<Vector3>("vector<Vector3>");
    emscripten::register_vector<Vector4>("vector<Vector4>");
    emscripten::register_vector<Color>("vector<Color>");
    emscripten::register_vector<CharInfo>("vector<CharInfo>");
    emscripten::register_vector<Rectangle>("vector<Rectangle>");
    emscripten::register_vector<std::vector<Rectangle>>("vector<vector<Rectangel>>");
    emscripten::register_vector<Mesh>("vector<Mesh>");
    emscripten::register_vector<Material>("vector<Material>");
    emscripten::register_vector<MaterialMap>("vector<MaterialMap>");
    emscripten::register_vector<BoneInfo>("vector<BoneInfo>");
    emscripten::register_vector<Transform>("vector<Transform>");
    emscripten::register_vector<std::vector<Transform>>("vector<std::vector<Transform>>");
    emscripten::register_vector<ModelAnimation>("vector<ModelAnimation>");
}
