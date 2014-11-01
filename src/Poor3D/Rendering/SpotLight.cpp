#include <Poor3D/Rendering/SpotLight.h>

using namespace Poor3D::Rendering;
using namespace std;

SpotLight::SpotLight(const Poor3D::Math::Vec3f &p,
					const Poor3D::Math::Vec3f &c,
					const Poor3D::Math::Vec3f &dir,
					float a)
	: Light(p, c), direction(dir), angle(a)
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
	shader->setUniform((head+".angle").c_str(), angle);
	(*sLightCount)++;
}