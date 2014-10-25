#ifndef RENDERING_RENDERENGINE_H_
#define RENDERING_RENDERENGINE_H_

#include <Poor3D/Math/Mat4.h>
#include <Poor3D/Scene/Scene.h>

namespace Poor3D
{
	namespace Rendering
	{
		class RenderEngine
		{
		public:
			RenderEngine();
			void render(const Poor3D::Math::Mat4 &,
				Poor3D::Scene::Camera &cam, 
				const Poor3D::Scene::Scene *);
		};
	}
}

#endif