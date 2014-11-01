#include <Poor3D/Poor3D.h>
#include <string>
#include <stdio.h>

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
	int plightCount=0;
	int slightCount=0;
	
	for(i=0; i<m_lights.size(); i++)
		m_lights[i]->setUniform(&m_shader, &plightCount, &slightCount);

	m_shader.setUniform("pointlightCount", plightCount);
	m_shader.setUniform("spotlightCount", slightCount);

}