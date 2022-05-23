#include "Game.h"
#include "Shader.h"
#include "Model.h"
#include "Transform.h"
#include "Entity.h"

size_t Game::offsetSize = offsetof(Game, scenes);


void Game::Load()
{
	// 从文件中载入
	Scene* scene = new Scene(_Name("Scene1"), width, height);
	scenes.push_back(scene);
	currentScene = scene;
}

void Game::Init() {

	currentScene->Init();
}

void Game::Update()
{
	currentScene->Update();
}

void Game::Render()
{

	currentScene->Render();

}

void Game::OnChange(int width, int height)
{

	currentScene->OnChange(width, height);
}


Game::Game(_Name name, int width, int height) :name(name), width(width), height(height)
{
	Load();
}
