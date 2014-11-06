#include <Poor3D/Poor3D.h>
#include <string>
#include <stdio.h>

using namespace Poor3D::Math;
using namespace Poor3D::Rendering;
using namespace Poor3D::Scene;
using namespace std;

PhongMaterial::PhongMaterial(Vec3f diffuse,
				float ambient,
				float specular,
				float shininess,
				std::vector<Light *> *plights)
	: Material("./resource/shaders/phong.vs", "./resource/shaders/phong.fs"),
	  m_diffuse(diffuse),
	  m_ambient(ambient),
	  m_specular(specular),
	  m_shininess(shininess),
	  m_plights(plights),
	  m_texture(nullptr)
{

}

PhongMaterial::PhongMaterial(Texture *text,
				float ambient,
				float specular,
				float shininess,
				std::vector<Light *> *plights)
	: Material("./resource/shaders/phong.vs", "./resource/shaders/phong.fs"),
	  m_diffuse(0.2, 0.2, 0.2),
	  m_ambient(ambient),
	  m_specular(specular),
	  m_shininess(shininess),
	  m_plights(plights),
	  m_texture(text)
{
	//temporary code
	if(m_texture!=nullptr)
		m_diffuse.x=-1.0f;
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

	if(m_texture)
	{
		m_texture->bind(GL_TEXTURE0);
		m_shader.setUniform("textureSampler", 0);
	}
}

void PhongMaterial::unbind() const
{
	Material::unbind();
	m_texture->unbind(GL_TEXTURE0);
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