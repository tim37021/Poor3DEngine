#include <Poor3D/Rendering/RenderEngine.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace Poor3D::Rendering;

RenderEngine::RenderEngine()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_DEPTH_CLAMP);

	glEnable(GL_TEXTURE_2D);
}

RenderEngine::render()
{

}