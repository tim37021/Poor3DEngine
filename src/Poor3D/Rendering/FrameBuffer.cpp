#include <Poor3D/Poor3D.h>

using namespace Poor3D::Rendering;

FrameBuffer::FrameBuffer()
{
	glGenFramebuffers(1, &m_id);
}

FrameBuffer::~FrameBuffer()
{
	glDeleteFramebuffers(1, &m_id);
}

void FrameBuffer::bind() const
{
	glBindFramebuffer(GL_FRAMEBUFFER, m_id);
}