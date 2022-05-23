#include "Material.h"
#include "Log.h"

Material::Material(std::ifstream & ifs)
{
	Load(ifs);
}

void Material::Save(std::ofstream & ofs)
{
	ofs.write((char*)this, sizeof(*this));
	ofs.flush();
}

void Material::Load(std::ifstream & ifs)
{
	ifs.read((char*)this, sizeof(this));
}

void Material::GlSetup()
{
	if (hasDiffuse) {
		diffuse->GLSetup();
	}
	if (hasSpecular) {
		specular->GLSetup();
	}
}

Material::Material(aiMaterial * material)
{
	hasDiffuse = material->GetTextureCount(aiTextureType_DIFFUSE);
	hasSpecular = material->GetTextureCount(aiTextureType_SPECULAR);

	aiString path;
	if (hasDiffuse) {
		material->GetTexture(aiTextureType_DIFFUSE, 0, &path);
		LOGI(" diffuse Path %s", path.C_Str());

	}

	if (hasSpecular) {
		material->GetTexture(aiTextureType_SPECULAR, 0, &path);
		LOGI(" specular Path %s", path.C_Str());
	}
}
