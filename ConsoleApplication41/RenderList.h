#pragma once
#include "std.h"
#include "Model.h"
#include "Mesh.h"
#include "Shader.h"
#include "Camera.h"

class RenderList
{
public:
	std::vector<Mesh* > meshes;
	std::vector<Model* > models;

	void GlSetup();
	void Render(Shader* shader,Camera* camera,float aspect);
};

