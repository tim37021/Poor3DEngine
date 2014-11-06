#ifndef RENDERING_RENDERENGINE_H_
#define RENDERING_RENDERENGINE_H_

#include <Poor3D/Math/Mat4.h>
#include <Poor3D/Scene/Scene.h>
#include <Poor3D/Rendering/Material.h>
#include <Poor3D/Rendering/FrameBuffer.h>

namespace Poor3D
{
	namespace Rendering
	{
		class RenderEngine
		{
		public:
			RenderEngine();
			void render(Poor3D::Scene::Scene *) const;
			void render2(Poor3D::Scene::Scene *) const;
			void updateShadowMap(Poor3D::Scene::Scene *) const;
		private:
			void render_helper(Poor3D::Scene::Scene *, const Material *m=nullptr) const ;
			void render_depth(Poor3D::Scene::Scene *, const DepthTexture *depth) const;
			Material m_depth_material;
			FrameBuffer m_shadow_fbo;
		};
	}
}

#endif