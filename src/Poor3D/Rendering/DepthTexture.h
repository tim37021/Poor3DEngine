#ifndef RENDERING_DEPTHTEXTURE_H_
#define RENDERING_DEPTHTEXTURE_H_

#include <Poor3D/Rendering/Texture.h>

namespace Poor3D
{
	namespace Rendering
	{
		class DepthTexture: public Texture
		{
		public:
			DepthTexture(int width, int height);
			virtual ~DepthTexture();
		};
	}

}

#endif