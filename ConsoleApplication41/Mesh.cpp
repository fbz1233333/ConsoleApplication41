#include "Mesh.h"
#include "Log.h"
#include "gl.h"

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<Face> faces) :vertices(vertices), faces(faces){

	numVertex = vertices.size();
	numFace = faces.size();

	for (unsigned int i = 0; i < numFace; i++) {
		indices.insert(indices.end(), faces[i].indices.begin(), faces[i].indices.end());
	}
	numIndices = indices.size();
}


Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices):vertices(vertices), indices(indices)
{
	numVertex = vertices.size();
	numIndices = indices.size();
}

Mesh::Mesh(std::ifstream & ifs)
{
	Load(ifs);
}

void Mesh::Save(std::ofstream & ofs)
{
	this->numVertex = vertices.size();
	this->numIndices = indices.size();

	ofs.write((char*)this, offsetof(Mesh, vertices));

	ofs.write((char*)&vertices[0], sizeof(Vertex)*numVertex);
	ofs.write((char*)&indices[0], sizeof(unsigned int) *numIndices);

}

Mesh::Mesh(_Path path)
{
	std::ifstream* ifs = path.GetIfStream();
	Load(*ifs);
}

void Mesh::Load(std::ifstream & ifs)
{
	ifs.read((char*)this, offsetof(Mesh, vertices));
	vertices.resize(numVertex);
	//LOGI(" num INdices %d ", numIndices);
	indices.resize(numIndices);


	ifs.read((char*)&vertices[0], sizeof(Vertex)* numVertex);
	ifs.read((char*)&indices[0], sizeof(unsigned int)*numIndices);


}

void Mesh::Save(_Path path)
{
	std::ofstream *ofs = path.GetOfStream();
	Save(*ofs);
}

Mesh::Mesh(aiMesh * mesh)
{
	LoadFromAssimp(mesh);

}

void Mesh::LoadFromAssimp(aiMesh * mesh)
{
	strcpy(meshName, mesh->mName.C_Str());
	LOGI("%s", mesh->mName.C_Str());
	materialIndex = mesh->mMaterialIndex;

	std::vector<Vertex> verticesI;
	std::vector<Face> facesI;

	numVertex = mesh->mNumVertices;
	numFace = mesh->mNumFaces;

	// Vertex
	for (unsigned int i = 0; i < numVertex; i++) {

		Vertex vertex;
		vertex.position.x = mesh->mVertices[i].x;
		vertex.position.y = mesh->mVertices[i].y;
		vertex.position.z = mesh->mVertices[i].z;

		vertex.texCoords.x = mesh->mTextureCoords[0][i].x;
		vertex.texCoords.y = mesh->mTextureCoords[0][i].y;

		vertex.normals.x = mesh->mNormals[i].x;
		vertex.normals.y = mesh->mNormals[i].y;
		vertex.normals.z = mesh->mNormals[i].z;

		verticesI.push_back(vertex);
	}

	// Face
	for (unsigned int i = 0; i < numFace; i++) {
		facesI.push_back(Face(&mesh->mFaces[i]));
	}
	// Indices
	new(this) Mesh(verticesI, facesI);
}

void Mesh::Draw() {
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, numIndices, GL_UNSIGNED_INT, 0);
}

void Mesh::Log()
{
	for (Vertex vertex : vertices) {
		LOGI("position (%f,%f,%f)", vertex.position.x, vertex.position.y, vertex.position.z);
	}
}

void Mesh::GlSetup()
{
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);

	glBindVertexArray(vao);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int)*numIndices, &indices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, numVertex * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normals));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texCoords));


	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}