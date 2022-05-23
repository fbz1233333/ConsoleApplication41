#include "Camera.h"


Camera::Camera(
	glm::vec3 position,
	glm::vec3 front,
	glm::vec3 worldUp,
	float Zoom,
	float minDistance,
	float maxDistance):
	Position(position),
	Front(front),
	Zoom(Zoom),
	minDistance(minDistance),
	maxDistance(maxDistance),
	WorldUp(worldUp)
{

}

glm::mat4 Camera::GetProjection(const float & aspect)
{
	return glm::perspective(glm::radians(Zoom), aspect, minDistance, maxDistance);
}


glm::mat4 Camera::GetViewMatrix()
{
	return glm::lookAt(Position, Position + Front, WorldUp);
}


