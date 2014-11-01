#ifndef RENDERING_FRAMEBUFFER_H_
#define RENDERING_FRAMEBUFFER_H_

#include <GLFW/glfw3.h>

namespace Poor3D
{
	namespace Rendering
	{
		class FrameBuffer
		{
		public:
			FrameBuffer();
			~FrameBuffer();

			void bind() const;	
		private:
			GLuint m_id;
		};
	}
}

#endif