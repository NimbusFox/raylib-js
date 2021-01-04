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
emscripten::val FontRecsGetter(const Font& font) {
    auto output = emscripten::val::array();

    for (auto i = 0; i < font.charsCount; i++) {
        output.set(i, emscripten::val(font.recs[i]));
    }

    return output;
}

void FontRecsSetter(Font& font, emscripten::val recs) {
    auto count = 0;

    while (!recs[count].isUndefined() && count < font.charsCount) {
        font.recs[count] = recs[count].as<Rectangle>();
        count++;
    }
}

emscripten::val FontCharsGetter(const Font& font) {
    auto output = emscripten::val::array();

    for (auto i = 0; i < font.charsCount; i++) {
        output.set(i, emscripten::val(font.chars[i]));
    }

    return output;
}

void FontCharsSetter(Font& font, emscripten::val chars) {
    auto count = 0;

    while (!chars[count].isUndefined() && count < font.charsCount) {
        font.chars[count] = chars[count].as<CharInfo>();
        count++;
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
emscripten::val MeshVertexCountGetter(const Mesh& mesh) {
    return emscripten::val(mesh.vertexCount);
}

void MeshVertexCountSetter(Mesh& mesh, emscripten::val vertexCount) {
    if (vertexCount.isNumber()) {
        mesh.vertexCount = vertexCount.as<float>();

        realloc(mesh.vertices, sizeof(float) * (mesh.vertexCount * 3));
        realloc(mesh.texcoords, sizeof(float) * (mesh.vertexCount * 2));
        realloc(mesh.texcoords, sizeof(float) * (mesh.vertexCount * 2));
        realloc(mesh.texcoords2, sizeof(float) * (mesh.vertexCount * 2));
        realloc(mesh.normals, sizeof(float) * (mesh.vertexCount * 3));
        realloc(mesh.tangents, sizeof(float) * (mesh.vertexCount * 4));
        realloc(mesh.colors, sizeof(unsigned char) * (mesh.vertexCount * 4));
        realloc(mesh.indices, sizeof(unsigned short) * mesh.vertexCount);
        realloc(mesh.animVertices, sizeof(float) * (mesh.vertexCount * 3));
        realloc(mesh.animNormals, sizeof(float) * (mesh.vertexCount * 3));
        realloc(mesh.boneIds, sizeof(int) * (mesh.vertexCount * 4));
        realloc(mesh.boneWeights, sizeof(float) * (mesh.vertexCount * 4));
        realloc(mesh.vboId, sizeof(unsigned int) * mesh.vertexCount);
    }
}

emscripten::val MeshVerticesGetter(const Mesh& mesh) {
    auto output = emscripten::val::array();

    for (auto i = 0; i < mesh.vertexCount * 3; i++) {
        output.set(i, emscripten::val(mesh.vertices[i]));
    }

    return output;
}

void MeshVerticesSetter(Mesh& mesh, const emscripten::val& vertices) {
    auto count = 0;

    while (vertices[count].isNumber() && count < mesh.vertexCount * 3) {
        mesh.vertices[count] = vertices[count].as<float>();
        count++;
    }
}

emscripten::val MeshTexcoordsGetter(const Mesh& mesh) {
    auto output = emscripten::val::array();

    for (auto i = 0; i < mesh.vertexCount * 2; i++) {
        output.set(i, emscripten::val(mesh.texcoords[i]));
    }

    return output;
}

void MeshTexcoordsSetter(Mesh& mesh, emscripten::val texcoords) {
    auto count = 0;

    while (texcoords[count].isNumber() && count < mesh.vertexCount * 2) {
        mesh.texcoords[count] = texcoords[count].as<float>();
        count++;
    }
}

emscripten::val MeshTexcoords2Getter(const Mesh& mesh) {
    auto output = emscripten::val::array();

    for (auto i = 0; i < mesh.vertexCount * 2; i++) {
        output.set(i, emscripten::val(mesh.texcoords2[i]));
    }

    return output;
}

void MeshTexcoords2Setter(Mesh& mesh, emscripten::val texcoords2) {
    auto count = 0;

    while (texcoords2[count].isNumber() && count < mesh.vertexCount * 2) {
        mesh.texcoords2[count] = texcoords2[count].as<float>();
        count++;
    }
}

emscripten::val MeshNormalsGetter(const Mesh& mesh) {
    auto output = emscripten::val::array();

    for (auto i = 0; i < mesh.vertexCount * 3; i++) {
        output.set(i, emscripten::val(mesh.normals[i]));
    }

    return output;
}

void MeshNormalsSetter(Mesh& mesh, emscripten::val normals) {
    auto count = 0;

    while (normals[count].isNumber() && count < mesh.vertexCount * 3) {
        mesh.normals[count] = normals[count].as<float>();
        count++;
    }
}

emscripten::val MeshTangentsGetter(const Mesh& mesh) {
    auto output = emscripten::val::array();

    for (auto i = 0; i < mesh.vertexCount * 4; i++) {
        output.set(i, emscripten::val(mesh.tangents[i]));
    }

    return output;
}

void MeshTangentsSetter(Mesh& mesh, emscripten::val tangents) {
    auto count = 0;

    while (tangents[count].isNumber() && count < mesh.vertexCount * 4) {
        mesh.tangents[count] = tangents[count].as<float>();
        count++;
    }
}

emscripten::val MeshColorsGetter(const Mesh& mesh) {
    auto output = emscripten::val::array();

    for (auto i = 0; i < mesh.vertexCount * 4; i++) {
        output.set(i, emscripten::val(mesh.colors[i]));
    }

    return output;
}

void MeshColorsSetter(Mesh& mesh, emscripten::val colors) {
    auto count = 0;

    while (colors[count].isNumber() && count < mesh.vertexCount * 4) {
        mesh.colors[count] = colors[count].as<unsigned char>();
        count++;
    }
}

emscripten::val MeshIndiciesGetter(const Mesh& mesh) {
    auto output = emscripten::val::array();

    for (auto i = 0; i < mesh.vertexCount; i++) {
        output.set(i, emscripten::val(mesh.indices[i]));
    }

    return output;
}

void MeshIndiciesSetter(Mesh& mesh, emscripten::val indicies) {
    auto count = 0;

    while (indicies[count].isNumber() && count < mesh.vertexCount) {
        mesh.indices[count] = indicies[count].as<unsigned short>();
        count++;
    }
}

emscripten::val MeshAnimVerticesGetter(const Mesh& mesh) {
    auto output = emscripten::val::array();

    for (auto i = 0; i < mesh.vertexCount * 3; i++) {
        output.set(i, emscripten::val(mesh.animVertices[i]));
    }

    return output;
}

void MeshAnimVerticesSetter(Mesh& mesh, emscripten::val animVertices) {
    auto count = 0;

    while (animVertices[count].isNumber() && count < mesh.vertexCount * 3) {
        mesh.animVertices[count] = animVertices[count].as<float>();
        count++;
    }
}

emscripten::val MeshAnimNormalsGetter(const Mesh& mesh) {
    auto output = emscripten::val::array();

    for (auto i = 0; i < mesh.vertexCount * 3; i++) {
        output.set(i, emscripten::val(mesh.animNormals[i]));
    }

    return output;
}

void MeshAnimNormalsSetter(Mesh& mesh, emscripten::val animNormals) {
    auto count = 0;

    while (animNormals[count].isNumber() && count < mesh.vertexCount * 3) {
        mesh.animNormals[count] = animNormals[count].as<float>();
        count++;
    }
}

emscripten::val MeshBoneIdsGetter(const Mesh& mesh) {
    auto output = emscripten::val::array();

    for (auto i = 0; i < mesh.vertexCount * 4; i++) {
        output.set(i, emscripten::val(mesh.boneIds[i]));
    }

    return output;
}

void MeshBoneIdsSetter(Mesh& mesh, emscripten::val boneIds) {
    auto count = 0;

    while (boneIds[count].isNumber() && count < mesh.vertexCount * 4) {
        mesh.boneIds[count] = boneIds[count].as<int>();
        count++;
    }
}

emscripten::val MeshBoneWeightsGetter(const Mesh& mesh) {
    auto output = emscripten::val::array();

    for (auto i = 0; i < mesh.vertexCount * 4; i++) {
        output.set(i, emscripten::val(mesh.boneWeights[i]));
    }

    return output;
}

void MeshBoneWeightsSetter(Mesh& mesh, emscripten::val boneWeights) {
    auto count = 0;

    while (boneWeights[count].isNumber() && count < mesh.vertexCount * 4) {
        mesh.boneWeights[count] = boneWeights[count].as<float>();
        count++;
    }
}

emscripten::val MeshVboIdGetter(const Mesh& mesh) {
    auto output = emscripten::val::array();

    for (auto i = 0; i < mesh.vertexCount; i++) {
        output.set(i, emscripten::val(mesh.vboId[i]));
    }

    return output;
}

void MeshVboIdSetter(Mesh& mesh, emscripten::val vboId) {
    auto count = 0;

    while (vboId[count].isNumber() && count < mesh.vertexCount) {
        mesh.vboId[count] = vboId[count].as<unsigned int>();
        count++;
    }
}

#pragma endregion
#pragma region Material
emscripten::val MaterialShaderGetter(const Material& material) {
    return emscripten::val(material.shader);
}

void MaterialShaderSetter(Material& material, emscripten::val shader) {
    if (shader.isUndefined()) {
        return;
    }

    material.shader = shader.as<Shader>();
}

emscripten::val MaterialMapsGetter(const Material& material) {
    auto output = emscripten::val::array();

    for (auto i = 0; i < MAX_MATERIAL_MAPS; i++) {
        output.set(i, material.maps[i]);
    }

    return output;
}

void MaterialMapsSetter(Material& material, emscripten::val maps) {
    auto count = 0;

    while (!maps[count].isUndefined() && count < MAX_MATERIAL_MAPS) {
        material.maps[count] = maps[count].as<MaterialMap>();
        count++;
    }
}

emscripten::val MaterialParamsGetter(const Material& material) {
    auto output = emscripten::val::array();

    for (auto i = 0; i < *(&material.params + 1) - material.params; i++) {
        output.set(i, material.params[i]);
    }

    return output;
}

void MaterialParamsSetter(Material& material, emscripten::val params) {
    auto count = 0;

    while (!params[count].isUndefined() && count < *(&material.params + 1) - material.params) {
        material.params[count] = params[count].as<float>();
        count++;
    }
}
#pragma endregion
#pragma region Shader
emscripten::val ShaderIdGetter(const Shader& shader) {
    return emscripten::val(shader.id);
}

void ShaderIdSetter(Shader& shader, emscripten::val id) {
    shader.id = id.as<unsigned int>();
}

emscripten::val ShaderLocsGetter(const Shader& shader) {
    auto output = emscripten::val::array();

    for (auto i = 0; i < MAX_SHADER_LOCATIONS; i++) {
        output.set(i, emscripten::val(shader.locs[i]));
    }

    return output;
}

void ShaderLocsSetter(Shader& shader, emscripten::val locs) {
    auto count = 0;

    while (locs[count].isNumber() && count < MAX_SHADER_LOCATIONS) {
        shader.locs[count] = locs[count].as<int>();
        count++;
    }
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
emscripten::val ModelMeshCountGetter(const Model& model) {
    return emscripten::val(model.meshCount);
}

void ModelMeshCountSetter(Model& model, emscripten::val meshCount) {
    if (meshCount.isNumber()) {
        model.meshCount = meshCount.as<int>();
        realloc(model.meshes, sizeof(Mesh) * model.meshCount);
        realloc(model.meshMaterial, sizeof(int) * model.meshCount);
    }
}

emscripten::val ModelMaterialCountGetter(const Model& model) {
    return emscripten::val(model.materialCount);
}

void ModelMaterialCountSetter(Model& model, emscripten::val materialCount) {
    if (materialCount.isNumber()) {
        model.materialCount = materialCount.as<int>();
        realloc(model.materials, sizeof(Material) * model.materialCount);
    }
}

emscripten::val ModelMeshesGetter(const Model& model) {
    auto output = emscripten::val::array();

    for (auto i = 0; i < model.meshCount; i++) {
        output.set(i, emscripten::val(model.meshes[i]));
    }

    return output;
}

void ModelMeshesSetter(Model& model, emscripten::val meshes) {
    auto count = 0;

    while (!meshes[count].isUndefined() && count < model.meshCount) {
        model.meshes[count] = meshes[count].as<Mesh>();
        count++;
    }
}

emscripten::val ModelMaterialsGetter(const Model& model) {
    auto output = emscripten::val::array();

    for (auto i = 0; i < model.materialCount; i++) {
        output.set(i, emscripten::val(model.materials[i]));
    }

    return output;
}

void ModelMaterialsSetter(Model& model, emscripten::val materials) {
    auto count = 0;

    while (!materials[count].isUndefined() && count < model.materialCount) {
        model.materials[count] = materials[count].as<Material>();
        count++;
    }
}

emscripten::val ModelMeshMaterialGetter(const Model& model) {
    auto output = emscripten::val::array();

    for (auto i = 0; i < model.meshCount; i++) {
        output.set(i, emscripten::val(model.meshMaterial[i]));
    }

    return output;
}

void ModelMeshMaterialSetter(Model& model, emscripten::val meshMaterial) {
    auto count = 0;
    while (!meshMaterial[count].isUndefined() && count < model.meshCount) {
        model.meshMaterial[count] = meshMaterial[count].as<int>();
        count++;
    }
}

emscripten::val ModelBoneCountGetter(const Model& model) {
    return emscripten::val(model.boneCount);
}

void ModelBoneCountSetter(Model& model, emscripten::val boneCount) {
    if (boneCount.isNumber()) {
        model.boneCount = boneCount.as<int>();

        realloc(model.bones, sizeof(BoneInfo) * model.boneCount);
        realloc(model.bindPose, sizeof(Transform) * model.boneCount);
    }
}

emscripten::val ModelBonesGetter(const Model& model) {
    auto output = emscripten::val::array();

    for (auto i = 0; i < model.boneCount; i++) {
        output.set(i, emscripten::val(model.bones[i]));
    }

    return output;
}

void ModelBonesSetter(Model& model, emscripten::val bones) {
    auto count = 0;

    while (!bones[count].isUndefined() && count < model.boneCount) {
        model.bones[count] = bones[count].as<BoneInfo>();
        count++;
    }
}

emscripten::val ModelBindPoseGetter(const Model& model) {
    auto output = emscripten::val::array();

    for (auto i = 0; i < model.boneCount; i++) {
        output.set(i, emscripten::val(model.bindPose[i]));
    }

    return output;
}

void ModelBindPoseSetter(Model& model, emscripten::val bindPose) {
    auto count = 0;

    while (!bindPose[count].isUndefined() && count < model.boneCount) {
        model.bindPose[count]  = bindPose[count].as<Transform>();
        count++;
    }
}
#pragma endregion
#pragma region ModelAnimation
emscripten::val ModelAnimationBoneCountGetter(const ModelAnimation& modelAnimation) {
    return emscripten::val(modelAnimation.boneCount);
}

void ModelAnimationBoneCountSetter(ModelAnimation& modelAnimation, emscripten::val boneCount) {

}

emscripten::val ModelAnimationFrameCountGetter(const ModelAnimation& modelAnimation) {
    return emscripten::val(modelAnimation.frameCount);
}

void ModelAnimationFrameCountSetter(ModelAnimation& modelAnimation, emscripten::val frameCount) {
    
}

emscripten::val ModelAnimationBonesGetter(const ModelAnimation& modelAnimation) {
    auto output = emscripten::val::array();

    for (auto i = 0; i < modelAnimation.boneCount; i++) {
        output.set(i, emscripten::val(modelAnimation.bones[i]));
    }

    return output;
}

void ModelAnimationBonesSetter(ModelAnimation& modelAnimation, emscripten::val bones) {
    auto count = 0;

    while (!bones[count].isUndefined() && count < modelAnimation.boneCount) {
        modelAnimation.bones[count] = bones[count].as<BoneInfo>();
        count++;
    }
}

emscripten::val ModelAnimationFramePosesGetter(const ModelAnimation& modelAnimation) {
    auto output = emscripten::val::array();

    for (auto i = 0; i < modelAnimation.frameCount; i++) {
        output.set(i, emscripten::val::array());

        for (auto j = 0; j < modelAnimation.boneCount; j++) {
            output[i].set(j, emscripten::val(modelAnimation.framePoses[i][j]));
        }
    }

    return output;
}

void ModelAnimationFramePosesSetter(ModelAnimation& modelAnimation, emscripten::val framePoses) {
    auto count = 0;
    auto count2 = 0;

    while (framePoses[count].isArray() && count < modelAnimation.frameCount) {
        count2 = 0;

        while (!framePoses[count][count2].isUndefined() && count2 < modelAnimation.boneCount) {
            modelAnimation.framePoses[count][count2] = framePoses[count][count2].as<Transform>();
            count2++;
        }
        count++;
    }
}
#pragma endregion
#pragma region VrDeviceInfo
emscripten::val VrDeviceInfoLensDistortionValuesGetter(const VrDeviceInfo& vrDeviceInfo) {
    auto output = emscripten::val::array();

    output[0] = emscripten::val(vrDeviceInfo.lensDistortionValues[0]);
    output[1] = emscripten::val(vrDeviceInfo.lensDistortionValues[1]);
    output[2] = emscripten::val(vrDeviceInfo.lensDistortionValues[2]);
    output[3] = emscripten::val(vrDeviceInfo.lensDistortionValues[3]);

    return output;
}

void VrDeviceInfoLensDistortionValuesSetter(const VrDeviceInfo& vrDeviceInfo, emscripten::val lensDistortionValues) {
    return;
}

emscripten::val VrDeviceInfoChromaAbCorrectionGetter(const VrDeviceInfo& vrDeviceInfo) {
    auto output = emscripten::val::array();

    output[0] = emscripten::val(vrDeviceInfo.chromaAbCorrection[0]);
    output[1] = emscripten::val(vrDeviceInfo.chromaAbCorrection[1]);
    output[2] = emscripten::val(vrDeviceInfo.chromaAbCorrection[2]);
    output[3] = emscripten::val(vrDeviceInfo.chromaAbCorrection[3]);

    return output;
}

void VrDeviceInfoChromaAbCorrectionSetter(const VrDeviceInfo& vrDeviceInfo, emscripten::val chromaAbCorrection) {
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
        .field("vertexCount", &MeshVertexCountGetter, &MeshVertexCountSetter)
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
        .field("shader", &MaterialShaderGetter, &MaterialShaderSetter)
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
        .field("meshCount", &ModelMeshCountGetter, &ModelMeshCountSetter)
        .field("materialCount", &ModelMaterialCountGetter, &ModelMaterialCountSetter)
        .field("meshes", &ModelMeshesGetter, &ModelMeshesSetter)
        .field("materials", &ModelMaterialsGetter, &ModelMaterialsSetter)
        .field("meshMaterial", &ModelMeshMaterialGetter, &ModelMeshMaterialSetter)
        .field("boneCount", &ModelBoneCountGetter, &ModelBoneCountSetter)
        .field("bones", &ModelBonesGetter, &ModelBonesSetter)
        .field("bindPose", &ModelBindPoseGetter, &ModelBindPoseSetter);

    emscripten::value_object<BoundingBox>("BoundingBox")
        .field("min", &BoundingBox::min)
        .field("max", &BoundingBox::max);

    emscripten::value_object<ModelAnimation>("ModelAnimation")
        .field("boneCount", &ModelAnimationBoneCountGetter, &ModelAnimationBoneCountSetter)
        .field("frameCount", &ModelAnimationFrameCountGetter, &ModelAnimationFrameCountSetter)
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
