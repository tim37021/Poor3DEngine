#ifndef RENDERING_TEXTURE_H_
#define RENDERING_TEXTURE_H_

#include <GLFW/glfw3.h>

namespace Poor3D
{
	namespace Rendering
	{
		class Texture
		{
		public:
			Texture();
			virtual ~Texture();

			void bind(GLenum text_unit=GL_TEXTURE0) const;

			void unbind(GLenum text_unit=GL_TEXTURE0) const;

			int getWidth() const
				{ return width; }

			int getHeight() const
				{ return height; }

			void getRawImageData(void *, int level=0) const;

			GLuint getID() const
				{ return m_id; }
		protected:
			int width, height;
		private:
			GLuint m_id;
		};
	}
}

#endif