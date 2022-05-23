#include "Face.h"

Face::Face()
{
}

Face::Face(std::ifstream & ifs)
{
	Load(ifs);
}

void Face::Save(std::ofstream & ofs)
{
	numIndices = indices.size();
	ofs.write((char*)this, offsetof(Face, indices));
	ofs.write((char*)&indices[0], numIndices * sizeof(unsigned int));

}

void Face::Load(std::ifstream & ifs)
{
	ifs.read((char*)this, offsetof(Face, indices));
	indices.resize(numIndices);
	
	ifs.read((char*)&indices[0], numIndices * sizeof(unsigned int));
}

Face::Face(std::vector<unsigned int> indices):indices(indices)
{
	numIndices = indices.size();
}

Face::Face(aiFace * face)
{
	LoadFromAssimp(face);
}

void Face::LoadFromAssimp(aiFace * face)
{
	numIndices = face->mNumIndices;
	indices.resize(numIndices);

	for (unsigned int i = 0; i < numIndices; i++) {
		indices[i] = face->mIndices[i];
	}
}
