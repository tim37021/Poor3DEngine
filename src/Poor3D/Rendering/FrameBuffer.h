#ifndef RENDERING_FRAMEBUFFER_H_
#define RENDERING_FRAMEBUFFER_H_

#include <GLFW/glfw3.h>
#include <Poor3D/Rendering/Texture.h>

namespace Poor3D
{
	namespace Rendering
	{
		class FrameBuffer
		{
		public:
			FrameBuffer();
			FrameBuffer(int width, int height);
			FrameBuffer(GLuint id);
			~FrameBuffer();

			void bind() const;
			void attach(const Texture &t, GLenum attachment, int mipmap_level=0) const;
			int getWidth() const
			{ return width; }
			int getHeight() const
			{ return height; }
			GLenum getStatus() const;

			void setWidth(int);
			void setHeight(int);
		private:
			GLuint m_id;
			int width, height;
			static GLuint getCurrentFrameBufferID();
		};

		extern const FrameBuffer DEFAULT_FRAMEBUFFER;
	}
}

#endif