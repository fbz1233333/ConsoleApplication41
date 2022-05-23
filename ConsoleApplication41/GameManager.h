#pragma once
#include "Game.h"
#include "Resource.h"

class GameManager
{
public:
	static Game* game;
	static Resource* resource;

	static void Init(Game* game, Resource* resource);

	static Model* GetModel(std::string path);

	static Shader* GetShader(std::string path);

	static Shader* GetShader();
	static Shader* GetColorShader();



};

