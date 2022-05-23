#include "Model.h"
#include "Log.h"

#include <assimp/Scene.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>

size_t Model::offsetSize = offsetof(Model, meshes);

Model::Model(_Path path)
{
	static Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(path.data, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);
	new (this)Model(scene);

/*
	std::ifstream* ifs = path.GetIfStream();
	Load(*ifs);*/
}


void Model::Load(std::ifstream & ifs)
{
	ifs.read((char*)this, offsetSize);
	meshes.resize(numMesh);
	for (unsigned int i = 0; i < numMesh;i++) {
		meshes[i] = new Mesh(ifs);
	}
}

void Model::MeshDraw()
{
	for (Mesh* mesh : meshes) {
		mesh->Draw();
	}
}


void Model::Save(std::ofstream & ofs)
{
	LOGI("Model Save");
	numMesh = meshes.size();
	ofs.write((char*)this, offsetSize);
	for (unsigned int i = 0; i < numMesh; i++) {
		meshes[i]->Save(ofs);
	}
}

void Model::Save( _Path path)
{
	std::ofstream *ofs = path.GetOfStream();
	Save(*ofs);
}

void Model::GlSetup()
{
	for (Mesh* mesh : meshes) {
		mesh->GlSetup();
	}
	
}

void Model::Log()
{
	for (Mesh* mesh : meshes) {
		mesh->Log();
	}
}

Model::Model(const aiScene * scene){
	LoadWithAssimp(scene);
	GlSetup();
}

void Model::LoadWithAssimp(const aiScene * scene)
{
	numMesh = scene->mNumMeshes;
	numMaterial = scene->mNumMaterials;
	
	meshes.resize(numMesh);
	materials.resize(numMaterial);
	
	for (unsigned int i = 0; i < numMesh; i++) {
		meshes[i] = new Mesh(scene->mMeshes[i]);
	}
	for (unsigned int i = 0; i < numMaterial; i++) {
		materials[i] = new Material(scene->mMaterials[i]);
	}

	
}
