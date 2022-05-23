#include "Transform.h"

Transform::Transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) :position(position), rotation(rotation), scale(scale)
{
}

glm::mat4 Transform::GetWorld()
{
	glm::mat4 world = glm::mat4(1.0f);
	world = glm::translate(world, position);
	world = glm::rotate(world, rotation.x, glm::vec3(1.0f, 0.f, 0.f));
	world = glm::rotate(world, rotation.y, glm::vec3(0.0f, 1.0f, 0.f));
	world = glm::rotate(world, rotation.z, glm::vec3(0.0f, 0.f, 1.0f));
	world = glm::scale(world, scale);
	return world;
}
