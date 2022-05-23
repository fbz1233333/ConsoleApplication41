#pragma once
#include "DataStruct.h"
#include "std.h"
#include "GameObject.h"
#include "Camera.h"
#include "Log.h"

using namespace datastruct;

class Scene
{
private:

private:
	static size_t offsetSize;
public:
	_Name name;
	int width, height;

	Scene();
	Scene(_Name name, int width, int height);
	std::vector<GameObject*> gameObjects;
	Camera *camera;
	float aspect;
public:

	void Load();
	void Init();
	void Update();
	void Render();

	void OnChange(int width, int height);
};
 
