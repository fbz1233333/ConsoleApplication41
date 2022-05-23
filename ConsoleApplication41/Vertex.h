#pragma once
#include "DataStruct.h"

#include <glm/glm.hpp>

using namespace datastruct;
class Vertex{

public:
	glm::vec3 position;
	glm::vec2 texCoords;
	glm::vec3 normals;

	Vertex(std::ifstream & ifs);
	void Save(std::ofstream& ofs);
	void Load(std::ifstream& ifs);

	Vertex();
	Vertex(glm::vec3 position);

};

