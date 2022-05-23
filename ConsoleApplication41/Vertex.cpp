#include "Vertex.h"

Vertex::Vertex(std::ifstream & ifs)
{
	Load(ifs);
}

void Vertex::Save(std::ofstream & ofs)
{
	ofs.write((char*)this, sizeof(*this));
}

void Vertex::Load(std::ifstream & ifs)
{
	ifs.read((char*)this, sizeof(this));
}

Vertex::Vertex()
{
}

Vertex::Vertex(glm::vec3 position) :position(position)
{
}
