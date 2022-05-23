#pragma once
#include "DataStruct.h"
#include "std.h"
#include "Scene.h"
#include "Log.h"

using namespace datastruct;
class Game
{
private:
	static size_t offsetSize;
public:
	_Name name;
	int width;
	int height;

public:
	std::vector<Scene*> scenes;
	Scene* currentScene;

private:

public:
	Game(_Name name, int width, int height);

	void Load();
	void Init();
	void Update();
	void Render();
	void OnChange(int width, int height);
};

