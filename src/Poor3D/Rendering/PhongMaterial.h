#ifndef RENDERING_PHONGMATERIAL_H_
#define RENDERING_PHONGMATERIAL_H_

#include <Poor3D/Rendering/Material.h>
#include <Poor3D/Rendering/Light.h>
#include <vector>

namespace Poor3D
{
	namespace Rendering
	{
		class PhongMaterial: public Material
		{
		public:
			PhongMaterial(Poor3D::Math::Vec3f diffuse,
				float ambient=1.0f,
				float specular=1.0f,
				float shininess=30.0f,
				std::vector<Light *> *plights=nullptr);
			PhongMaterial(Texture *text=nullptr,
				float ambient=1.0f,
				float specular=1.0f,
				float shininess=30.0f,
				std::vector<Light *> *plights=nullptr);

			void bindLights(const std::vector<Light *> *plights)
				{m_plights=plights;}

			virtual void bind(const Poor3D::Math::Mat4 &proj, 
				Poor3D::Scene::Camera *cam, 
				const Poor3D::Math::Mat4 &parentModel, 
				const Poor3D::Math::Mat4 &parentRotation, 
				Poor3D::Math::TransMat4 &t) const;
		private:
			void setLightsUniform() const;

			
			Texture *m_texture;
			Poor3D::Math::Vec3f m_diffuse;
			float m_ambient;
			float m_specular;
			float m_shininess;

			const std::vector<Light *> *m_plights;
		};
	}
}

#endif