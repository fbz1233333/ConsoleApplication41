#pragma once
#include "Model.h"
#include "Camera.h"
#include "Shader.h"
#include "Transform.h"

class Renderer3D
{
public:
	static void Render(Model* model, Shader* shader, Camera* camera, float aspect, Transform transform,glm::vec3 color=glm::vec3(0.0f,1.0f,0.0f));

};

