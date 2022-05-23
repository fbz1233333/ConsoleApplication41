#include "GameObject.h"
#include "GameManager.h"
#include "Renderer3D.h"
GameObject::GameObject(Entity * entity, Transform transform) :entity(entity), transform(transform)
{
}

void GameObject::Render(Camera * camera, float aspect)
{
	Renderer3D::Render(entity->model, GameManager::GetColorShader(), camera, aspect, transform);

}
