#pragma once
#include "DataStruct.h"
#include <assimp/mesh.h>
#include <vector>

using namespace datastruct;
class Face
{
public:
	unsigned int numIndices;
	std::vector<unsigned int> indices;

	Face();
	Face(std::ifstream & ifs);
	void Save(std::ofstream& ofs);
	void Load(std::ifstream& ifs);

	Face(std::vector<unsigned int > indices);
	Face(aiFace* face);
	void LoadFromAssimp(aiFace* face);
};

