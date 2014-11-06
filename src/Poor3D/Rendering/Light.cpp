#include <Poor3D/Rendering/Light.h>

using namespace Poor3D::Rendering;
using namespace std;

Light::Light(const Poor3D::Math::Vec3f &p, const Poor3D::Math::Vec3f &c)
	: position(p), color(c) 
{

}

Light::~Light()
{
	for(unsigned int i=0; i<shadow_map.size(); i++)
		delete shadow_map[i].second;
}

void Light::setUniform(const Poor3D::Shader::Shader *shader,
	int *pLightCount, int *sLightCount)
{
	std::string head="plights[";
	head+=std::to_string(*pLightCount)+"]";
	shader->setUniform((head+".pos").c_str(), position);
	shader->setUniform((head+".color").c_str(), color);
	(*pLightCount)++;
}