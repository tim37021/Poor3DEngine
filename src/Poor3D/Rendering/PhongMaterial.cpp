#include <Poor3D/Rendering/PhongMaterial.h>
#include <string>

using namespace Poor3D::Math;
using namespace Poor3D::Rendering;
using namespace Poor3D::Scene;
using namespace std;

PhongMaterial::PhongMaterial(float ambient, 
				Vec3f diffuse,
				float specular,
				float shininess,
				std::vector<Light *> *plights)
	: Material("./resource/shaders/phong.vs", "./resource/shaders/phong.fs"),
	  m_ambient(ambient),
	  m_diffuse(diffuse),
	  m_specular(specular),
	  m_shininess(shininess),
	  m_plights(plights)
{

}

void PhongMaterial::bind(const Mat4 &proj, 
	Camera *cam, 
	const Mat4 &parentModel,
	const Mat4 &parentRotation,
	TransMat4 &t) const
{
	Material::bind(proj, cam, parentModel, parentRotation, t);

	//bind color 
	m_shader.setUniform("diffuse", m_diffuse);
	m_shader.setUniform("specular", m_specular);
	m_shader.setUniform("shininess", m_shininess);
	//if lights array ptr has been set
	if(m_plights)
		setLightsUniform();
}

void PhongMaterial::setLightsUniform() const
{
	unsigned int i;
	const std::vector<Light *> &m_lights=*m_plights;
	m_shader.setUniform("lightCount", static_cast<int>(m_lights.size()));
	for(i=0; i<m_lights.size(); i++)
	{
		string head="plights[";
		head+=to_string(i)+"]";
		m_shader.setUniform((head+".pos").c_str(), m_lights[i]->position);
		m_shader.setUniform((head+".color").c_str(), m_lights[i]->color);
	}
}