#pragma once
#include "Entity.h"
#include "Transform.h"
#include "Camera.h"

class GameObject
{
public:

	Entity* entity;
	Transform transform;

	GameObject(Entity* entity, Transform transform);
	void Render(Camera* camera, float aspect);
};

