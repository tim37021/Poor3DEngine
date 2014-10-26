#ifndef RENDERING_LIGHT_H_
#define RENDERING_LIGHT_H_

#include <Poor3D/Math/Vec3f.h>

namespace Poor3D
{
	namespace Rendering
	{
		struct Light
		{
			Poor3D::Math::Vec3f position;
			Poor3D::Math::Vec3f color;

			Light(const Poor3D::Math::Vec3f &p, const Poor3D::Math::Vec3f &c)
				: position(p), color(c) 
				{}
		};
	}
}

#endif