#ifndef RENDERING_SPOTLIGHT_H_
#define RENDERING_SPOTLIGHT_H_

#include <Poor3D/Rendering/Light.h>

namespace Poor3D
{
	namespace Rendering
	{
		struct SpotLight: public Light
		{
			Poor3D::Math::Vec3f direction;
			float inner_angle;
			float outer_angle;

			SpotLight(const Poor3D::Math::Vec3f &p,
						const Poor3D::Math::Vec3f &c,
						const Poor3D::Math::Vec3f &dir,
						float inner, float outer);
			virtual ~SpotLight();
			virtual void setUniform(const Poor3D::Shader::Shader *shader, 
				int *pLightCount,
				int *sLightCount);
		};
	}
}

#endif