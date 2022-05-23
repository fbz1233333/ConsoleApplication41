#pragma once
#include "glm.h"

class Camera {
public:
	glm::vec3 Position;
	glm::vec3 Front;
	glm::vec3 WorldUp;

	float Zoom;
	float minDistance;
	float maxDistance;

	Camera(
		glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f),
		glm::vec3 worldUp = glm::vec3(0.0f, 0.0f, 1.0f),

		float Zoom = 45.0f,
		float minDistance = 0.1f,
		float maxDistance = 1000.0f
	);

	glm::mat4 GetViewMatrix();
	glm::mat4 GetProjection(const float& aspect);

};