#pragma once
#include "DataStruct.h"
#include "Vertex.h"
#include "Face.h"

#include <vector>
#include <assimp/mesh.h>


using namespace datastruct;
class Mesh
{
public:
	char meshName[64];
	unsigned int numVertex;
	unsigned int numIndices;
	unsigned int numFace;
	unsigned int materialIndex;

	// head Vertex;
	std::vector<Vertex> vertices;
	std::vector<Face> faces;
	std::vector<unsigned int> indices;

private:
	unsigned int vao, vbo, ebo;

public:
	Mesh(std::vector<Vertex> vertices, std::vector<Face> faces);
	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);
	Mesh(std::ifstream & ifs);
	void Save(std::ofstream& ofs);
	Mesh(_Path path);
	void Load(std::ifstream& ifs);
	void Save(_Path path);

	Mesh(aiMesh* mesh);
	void LoadFromAssimp(aiMesh *mesh);

	void GlSetup();
	void Draw();
	void Log();
};

