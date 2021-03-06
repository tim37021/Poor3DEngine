#ifndef RENDERING_LIGHT_H_
#define RENDERING_LIGHT_H_

#include <Poor3D/Math/Vec3f.h>
#include <Poor3D/Shader/Shader.h>
#include <Poor3D/Rendering/DepthTexture.h>
#include <Poor3D/Scene/Camera.h>
#include <string>
#include <vector>
#include <utility>

namespace Poor3D
{
	namespace Rendering
	{
		struct Light
		{
			Poor3D::Math::Vec3f position;
			Poor3D::Math::Vec3f color;
			std::vector<std::pair<Poor3D::Scene::Camera, DepthTexture *>> shadow_map;

			Light(const Poor3D::Math::Vec3f &p, const Poor3D::Math::Vec3f &c);
			virtual ~Light();
			virtual void setUniform(const Poor3D::Shader::Shader *shader,
				int *pLightCount,
				int *sLightCount);
		};
	}
}

#endif