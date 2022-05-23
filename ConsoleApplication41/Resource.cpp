#include "Resource.h"

Resource::Resource()
{
	Init();
}

void Resource::Init()
{
	LoadModel(_Path("rs/car1.obj"));
	LoadShader(_Path("glsl/model"));
	LoadShader(_Path("glsl/color"));
	shader = shaders["glsl/model"];
	color = shaders["glsl/color"];
}

void Resource::LoadModel(_Path path)
{
	models[path.data] = new Model(path);
}

void Resource::LoadShader(_Path path)
{
	shaders[path.data] = new Shader(path);
}

Model * Resource::GetModel(_Path path)
{
	if (path.GetIfStream()) {
		return models[path.data];
	}
}

Shader * Resource::GetShader(_Path path)
{
	if (path.GetIfStream()) {
		return shaders[path.data];
	}
}

Shader * Resource::GetColorShader()
{
	return color;
}
