#pragma once
#include "DataStruct.h"

using namespace datastruct;
class Texture2D
{
private:
	static size_t offsetSize;
public:
	unsigned int width;
	unsigned int height;
	unsigned int nrComponents;


	unsigned char* data;
	unsigned int textureId;

	Texture2D(_Path path);
	Texture2D(std::ifstream & ifs);
	void Save(std::ofstream& ofs);
	void Load(std::ifstream& ifs);
	void GLSetup();
};

