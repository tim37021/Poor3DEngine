#include <Poor3D/Poor3D.h>
#include <cstdio>

using namespace Poor3D::Rendering;

DepthTexture::DepthTexture(int w, int h)
	: Texture()
{
	width=w;
	height=h;

	bind();
	// Poor filtering. Needed !
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

	float color[]={1.0, 0.0, 0.0, 1.0};
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT24, w, h, 0, GL_DEPTH_COMPONENT, GL_FLOAT, 0);
}

DepthTexture::~DepthTexture()
{

}