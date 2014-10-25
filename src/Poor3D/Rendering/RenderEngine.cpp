#include <Poor3D/Poor3D.h>

using namespace Poor3D::Rendering;

RenderEngine::RenderEngine()
{
	//glClearColor(1.0f, 0.0f, 0.0f, 0.0f);

	/*glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_DEPTH_CLAMP);
*/
	//glEnable(GL_TEXTURE_2D);
	//
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_DEPTH_CLAMP);
}

void RenderEngine::render(const Poor3D::Math::Mat4 &proj,
	Poor3D::Scene::Camera &cam,
	const Poor3D::Scene::Scene *s)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for(int i=0; i<s->objects.size(); i++)
	{
		s->objects[i]->render(proj, cam);
	}
}
