#ifndef RENDERING_IMAGETEXTURE_H_
#define RENDERING_IMAGETEXTURE_H_

#include <GLFW/glfw3.h>

namespace Poor3D
{
	namespace Rendering
	{
		class ImageTexture: public Texture
		{
		public:
			ImageTexture(int width, int height, void *image);
			virtual ~ImageTexture();
		};
	}
}

#endif