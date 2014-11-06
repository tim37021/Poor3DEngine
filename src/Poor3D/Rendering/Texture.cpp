#include <Poor3D/Poor3D.h>

using namespace Poor3D::Rendering;

Texture::Texture()
{
	glGenTextures(1, &m_id);
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

void Texture::unbind(GLenum text_unit) const
{
	glActiveTexture(text_unit);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::getRawImageData(void *buffer, int level) const
{
	GLint width, height, internalFormat;
	bind();

	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_COMPONENTS, &internalFormat); // get internal format type of GL texture
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &width); // get width of GL texture
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &height); // get height of GL texture

	GLint numBytes = 0;
	switch(internalFormat) // determine what type GL texture has...
	{
	case GL_RGB:
	case GL_DEPTH_COMPONENT24:
	numBytes = width * height * 3;
	break;
	case GL_RGBA:
	numBytes = width * height * 4;
	break;
	default: // unsupported type (or you can put some code to support more formats if you need)
	break;
	}

	if(numBytes)
	{
		glGetTexImage(GL_TEXTURE_2D, 0, GL_BGR, GL_UNSIGNED_BYTE, buffer);
	}

	GLenum glErr=glGetError();
	if(glErr!=GL_NO_ERROR)
	{
		printf("Error %d", glErr);
	}
}