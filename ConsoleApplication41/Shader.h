#pragma once
#include "DataStruct.h"
#include "gl.h"
#include "glm.h"

using namespace datastruct;
class Shader
{
private:
	unsigned int ID;

public:


	void LoadFromPath(_Path vertexPath, _Path fragmentPath);
	void LoadFromPath(_Path vertexPath, _Path fragmentPath, _Path geomertry);

	void LoadFromCode(const char* vShaderCode, const char* fShaderCode, const char* geometry = nullptr);

	Shader(_Path path);
	Shader(_Path vertexPath, _Path fragmentPath);
	Shader(_Path vertexPath, _Path fragmentPath, _Path geometryPath);

	void Use() const;

	void SetBool(const std::string &name, bool value)const;

	void SetInt(const std::string &name, int value) const;

	void SetFloat(const std::string &name, float value) const;

	void SetVec2(const std::string &name, const glm::vec2 &value) const;

	void SetVec2(const std::string &name, float x, float y) const;

	void SetVec3(const std::string &name, const glm::vec3 &value) const;

	void SetVec3(const std::string &name, float x, float y, float z) const;

	void SetVec4(const std::string &name, const glm::vec4 &value) const;

	void SetVec4(const std::string &name, float x, float y, float z, float w);

	void SetMat2(const std::string &name, const glm::mat2 &mat) const;

	void SetMat3(const std::string &name, const glm::mat3 &mat) const;

	void SetMat4(const std::string &name, const glm::mat4 &mat) const;

private:

	void checkCompileErrors(GLuint shader, std::string type);

};