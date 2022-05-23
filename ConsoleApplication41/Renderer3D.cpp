#include "Renderer3D.h"
#include "GameManager.h"

void Renderer3D::Render(Model * model, Shader * shader, Camera * camera, float aspect, Transform transform, glm::vec3 color)
{
	shader->Use();
	shader->SetMat4("projection", camera->GetProjection(aspect));
	shader->SetMat4("view", camera->GetViewMatrix());
	shader->SetMat4("model", transform.GetWorld());
	shader->SetVec3("color", color);
	model->MeshDraw();
}
