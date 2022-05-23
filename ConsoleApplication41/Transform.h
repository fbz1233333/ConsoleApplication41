#pragma once
#include "glm.h"

class Transform
{
public:
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
	Transform(glm::vec3 position = glm::vec3(0.f), glm::vec3 rotation = glm::vec3(0.0f), glm::vec3 scale = glm::vec3(1.0f));
	
	glm::mat4 GetWorld();

};

