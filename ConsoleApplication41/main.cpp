#define _ASSIMP_
#include "DataStruct.h"
#include "Texture2D.h"
#include "Shader.h"
#include "Model.h"
#include "Mesh.h"
#include "Vertex.h"
#include "Camera.h"
#include "Transform.h"

#include "stb_image.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <assimp/Scene.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>

#include "Game.h"

#include "RenderList.h"
#include "GameManager.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);


using namespace datastruct;

const int SCR_WIDTH = 800;
const int SCR_HEIGHT = 600;


Game* game;

int main(int argc, char* argv[]) {

	//PrepareGame();


	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SAMPLES, 4);

	game = new Game(_Name("fbzGame"), 800, 600);


	GLFWwindow* window = glfwCreateWindow(game->width, game->height, game->name.data, NULL, NULL);
	if (window == NULL)
	{
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "GLAD INIT FAILED" << std::endl;
		return -1;
	}

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetKeyCallback(window, key_callback);

	//mesh->GlSetup();

	glEnable(GL_MULTISAMPLE);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	Resource* resource = new Resource();
	GameManager::Init(game, resource);

	game->Load();
	game->Init();
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		game->Render();
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	glfwDestroyWindow(window);

	return 0;

}


std::vector<_Path> GetPaths() {

	std::vector<_Path> paths;
	paths.push_back(_Path("m1.fbx"));
	return paths;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	game->OnChange(width, height);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
	if (key >= 0 && key < 1024)
	{
		//if (action == GLFW_PRESS)
		//	keyboard->press[key] = GL_TRUE;
		//else if (action == GLFW_RELEASE)
		//	keyboard->press[key] = GL_FALSE;

	}

}