#pragma once
#include <map>
#include <vector>
#include "DataStruct.h"
#include "Shader.h"
#include "Model.h"

using namespace datastruct;

class Resource
{
public:
	std::map<std::string, Model*> models;
	std::map<std::string, Shader*> shaders;
	Shader* shader;
	Shader* color;

	Resource();
	void Init();
	void LoadModel(_Path path);
	void LoadShader(_Path path);
	Model* GetModel(_Path path);
	Shader* GetShader(_Path path);
	Shader* GetColorShader();


};

