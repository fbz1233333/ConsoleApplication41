#include "RenderList.h"

void RenderList::GlSetup()
{
	for (Model* model : models) {
		model->GlSetup();
	}
	for (Mesh* mesh : meshes) {
		mesh->GlSetup();
	}
}

void RenderList::Render(Shader * shader, Camera * camera, float aspect)
{
	shader->Use();


}
