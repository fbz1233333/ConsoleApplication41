#pragma once
#include "DataStruct.h"
#include "Texture2D.h"

#include <assimp/material.h>

using namespace datastruct;

class Material
{
public:
	bool hasDiffuse;
	bool hasSpecular;

	Texture2D* diffuse;
	Texture2D* specular;

	Material(std::ifstream & ifs);
	void Save(std::ofstream& ofs);
	void Load(std::ifstream& ifs);

	void GlSetup();

	Material(aiMaterial* material);

};

