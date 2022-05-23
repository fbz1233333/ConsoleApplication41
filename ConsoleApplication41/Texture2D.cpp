#include "Texture2D.h"

size_t Texture2D::offsetSize = offsetof(Texture2D, data);

Texture2D::Texture2D(_Path path)
{
	std::ifstream *ifs = path.GetIfStream();
	Load(*ifs);
}

Texture2D::Texture2D(std::ifstream & ifs)
{
	Load(ifs);
}

void Texture2D::Save(std::ofstream & ofs)
{
	ofs.write((char*)this, sizeof(*this));
}

void Texture2D::Load(std::ifstream & ifs)
{
	ifs.read((char*)this, sizeof(this));
}

void Texture2D::GLSetup()
{
}
