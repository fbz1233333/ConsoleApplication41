#pragma once
#include "DataStruct.h"
#include "Material.h"
#include "Mesh.h"

#include <vector>
#include <assimp/scene.h>

using namespace datastruct;
class Model
{
private:
	static size_t offsetSize;
public:
	unsigned int numMesh;
	unsigned int numMaterial;
	// Start
	std::vector<Mesh*> meshes;
	std::vector<Material*> materials;

	Model(_Path path);
	void Save(std::ofstream& ofs);
	void Save(_Path path);
	void Load(std::ifstream& ifs);
	void MeshDraw();
	void GlSetup();
	void Log();
	
	Model(const aiScene* scene);
	void LoadWithAssimp(const aiScene* scene);
};

