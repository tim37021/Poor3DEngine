#include <Poor3D/Poor3D.h>

using namespace Poor3D::Rendering;

const FrameBuffer Poor3D::Rendering::DEFAULT_FRAMEBUFFER(0);

FrameBuffer::FrameBuffer()
{
	glGenFramebuffers(1, &m_id);
}

FrameBuffer::FrameBuffer(GLuint id)
	: m_id(id)
{
}

FrameBuffer::~FrameBuffer()
{
	if(m_id!=0)
		glDeleteFramebuffers(1, &m_id);
}

void FrameBuffer::bind() const
{
	glBindFramebuffer(GL_FRAMEBUFFER, m_id);
}

void FrameBuffer::attach(const Texture &t, GLenum attachment, int mipmap_level) const
{
	bind();
	glFramebufferTexture(GL_DRAW_FRAMEBUFFER, attachment, t.getID(), mipmap_level);
}