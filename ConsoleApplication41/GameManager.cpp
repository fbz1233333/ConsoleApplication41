#include "GameManager.h"

Game* GameManager::game;
Resource* GameManager::resource;

void GameManager::Init(Game * game, Resource * resource)
{
	GameManager::game = game;
	GameManager::resource = resource;
}

Model * GameManager::GetModel(std::string path)
{
	return resource->GetModel(path);
}

Shader * GameManager::GetShader(std::string path)
{
	return resource->GetShader(path);
}

Shader * GameManager::GetShader()
{
	return resource->shader;
}

Shader * GameManager::GetColorShader()
{
	return resource->color;
}
