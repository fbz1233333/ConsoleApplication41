#include "Scene.h"
#include "Shader.h"
#include "Model.h"
#include "Transform.h"
#include "Entity.h"
#include "GameManager.h"

size_t Scene::offsetSize = sizeof(Scene);

Scene::Scene()
{
}

Scene::Scene(_Name name, int width, int height) :name(name), width(width), height(height)
{
	if (height != 0) {
		this->aspect = (float)width / (float)height;
	}
}

glm::vec3 lightPos;
Entity* entity;
GameObject* gameObject;

void Scene::Load()
{
}

void Scene::Init()
{
	entity = new Entity(GameManager::GetModel("rs/car1.obj"));
	gameObject = new GameObject(entity, Transform());
	gameObjects.push_back(gameObject);
	
	camera = new Camera(glm::vec3(20.0f, 20.0f, 0.0f));
	camera->Front = -glm::vec3(20.0f, 20.0f, 0.0f);

	lightPos = glm::vec3(2.0f, 0.0f, 5.0f);
}

void Scene::Update()
{
}

void Scene::Render()
{
	for (GameObject* gameObject : gameObjects) {

		gameObject->Render(camera, aspect);

	}

}

void Scene::OnChange(int width, int height)
{
	this->width = width;
	this->height = height;
	if (this->height != 0) {
		this->aspect = (float)width / (float)height;
	}
}






