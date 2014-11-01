#include <Poor3D/Rendering/SpotLight.h>

using namespace Poor3D::Rendering;
using namespace std;

SpotLight::SpotLight(const Poor3D::Math::Vec3f &p,
					const Poor3D::Math::Vec3f &c,
					const Poor3D::Math::Vec3f &dir,
					float inner, float outer)
	: Light(p, c), direction(dir), inner_angle(inner), outer_angle(outer)
{

}

void SpotLight::setUniform(const Poor3D::Shader::Shader *shader, 
	int *pLightCount, int *sLightCount)
{
	std::string head="slights[";
	head+=std::to_string(*sLightCount)+"]";
	shader->setUniform((head+".pos").c_str(), position);
	shader->setUniform((head+".color").c_str(), color);
	shader->setUniform((head+".dir").c_str(), direction);
	shader->setUniform((head+".inner_angle").c_str(), inner_angle);
	shader->setUniform((head+".outer_angle").c_str(), outer_angle);

	(*sLightCount)++;
}