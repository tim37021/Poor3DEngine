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

FrameBuffer::FrameBuffer(int w, int h)
{
	glGenFramebuffers(1, &m_id);
	glBindFramebuffer(1, m_id);
	setWidth(w);
	setHeight(h);
	glBindFramebuffer(1, 0);
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
	GLuint cur=getCurrentFrameBufferID();
	bind();
	glFramebufferTexture(GL_DRAW_FRAMEBUFFER, attachment, t.getID(), mipmap_level);
	glBindFramebuffer(GL_FRAMEBUFFER, cur);
}

void FrameBuffer::setWidth(int _width)
{
	width=_width;
	glFramebufferParameteri(GL_DRAW_FRAMEBUFFER, GL_FRAMEBUFFER_DEFAULT_WIDTH, width);
}

void FrameBuffer::setHeight(int _height)
{
	height=_height;
	glFramebufferParameteri(GL_DRAW_FRAMEBUFFER, GL_FRAMEBUFFER_DEFAULT_HEIGHT, height);
}

GLenum FrameBuffer::getStatus() const
{
	GLuint cur=getCurrentFrameBufferID();
	bind();
	GLenum status=glCheckFramebufferStatus(GL_FRAMEBUFFER);
	glBindFramebuffer(GL_FRAMEBUFFER, cur);
	return status;
}

GLuint FrameBuffer::getCurrentFrameBufferID()
{
	GLint id;
	glGetIntegerv(GL_FRAMEBUFFER_BINDING, &id);
	return id;
}