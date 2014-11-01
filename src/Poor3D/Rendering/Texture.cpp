#include <Poor3D/Poor3D.h>

using namespace Poor3D::Rendering;

Texture::Texture(int width, int height, void *image)
{
	glGenTextures(1, &m_id);
	// "Bind" the newly created texture : all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_2D, m_id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// Give the image to OpenGL
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, image);
	 
}

Texture::~Texture()
{
	glDeleteTextures(1, &m_id);
}

void Texture::bind(GLenum text_unit) const
{
	glActiveTexture(text_unit);
	glBindTexture(GL_TEXTURE_2D, m_id);
}