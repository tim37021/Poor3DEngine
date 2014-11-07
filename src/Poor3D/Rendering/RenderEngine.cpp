#include <Poor3D/Poor3D.h>
#include <fstream>

using namespace Poor3D::Rendering;
using namespace std;

RenderEngine::RenderEngine()
	: m_depth_material("resource/shaders/depth.vs", "resource/shaders/depth.fs"),
	  m_shadow_fbo(1024, 1024)
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

void RenderEngine::render(Poor3D::Scene::Scene *s) const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	render_helper(s);
}

void RenderEngine::render2(Poor3D::Scene::Scene *s) const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	render_helper(s, &m_depth_material);
}

void RenderEngine::updateShadowMap(Poor3D::Scene::Scene *s) const
{
	Poor3D::Scene::Camera *originalCam=s->getCamera();
	for(unsigned int i=0; i<s->getLights()->size(); i++)
	{
		//TODO: passing scene is weird
		
		Light &l=*(s->getLights()->at(i));
		for(unsigned int j=0; j<l.shadow_map.size(); j++)
		{
			s->setCamera(&l.shadow_map[j].first);
			render_depth(s, l.shadow_map[j].second);
		}
	}

	s->setCamera(originalCam);

	DEFAULT_FRAMEBUFFER.bind();
}

void RenderEngine::render_helper(Poor3D::Scene::Scene *s, const Material *m) const
{
	auto &objects=*(s->getRootNodeList());
	for(unsigned int i=0; i<objects.size(); i++)
	{
		objects[i]->render(s, m);
	}
}

void screenshot (const char filename[],int x, int y)
{
	// get the image data
	long imageSize = x * y * 3;
	unsigned char *data = new unsigned char[imageSize];
	glReadPixels(0,0,x,y, GL_BGR,GL_UNSIGNED_BYTE,data);// split x and y sizes into bytes
	Poor3D::Utils::saveBMP(filename, data, x, y);
	delete[] data;
	data=NULL;
}

void RenderEngine::render_depth(Poor3D::Scene::Scene *s, const DepthTexture *depth) const
{
	m_shadow_fbo.bind();

	m_shadow_fbo.attach(*depth, GL_DEPTH_ATTACHMENT, 0);


	GLuint status;
	if ((status = glCheckFramebufferStatus(GL_FRAMEBUFFER)) != GL_FRAMEBUFFER_COMPLETE)
		fprintf(stderr, "3glCheckFramebufferStatus: error %p\n", reinterpret_cast<unsigned int *>(status));


	glDrawBuffer(GL_NONE);

	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	glViewport(0, 0, m_shadow_fbo.getWidth(), m_shadow_fbo.getHeight());

	render_helper(s, &m_depth_material);
	
	DEFAULT_FRAMEBUFFER.bind();
	glViewport(0, 0, 800, 600);
}