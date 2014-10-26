#ifndef RENDERING_MATERIAL_H_
#define RENDERING_MATERIAL_H_

#include <Poor3D/Math/TransMat4.h>
#include <Poor3D/Math/Mat4.h>
#include <Poor3D/Math/Vec3f.h>
#include <Poor3D/Shader/Shader.h>
#include <Poor3D/Scene/Camera.h>

namespace Poor3D
{
	namespace Rendering
	{
		class Material
		{
		public:
			Material();
			Material(const char *vsfile, const char *fsfile);

			virtual void bind(const Poor3D::Math::Mat4 &proj, 
				Poor3D::Scene::Camera *cam, 
				const Poor3D::Math::Mat4 &parentModel, 
				const Poor3D::Math::Mat4 &parentRotation, 
				Poor3D::Math::TransMat4 &t) const;
		protected:
			Poor3D::Shader::Shader m_shader;
		};
	}
}

#endif