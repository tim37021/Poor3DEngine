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
			Texture(int width, int height, void *image);
			~Texture();

			void bind(GLenum text_unit) const;

			GLuint getID() const
				{ return m_id; }
		private:
			GLuint m_id;
		};
	}
}

#endif